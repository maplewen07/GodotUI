shader_type canvas_item;
render_mode unshaded;

uniform sampler2D screen_texture : hint_screen_texture, repeat_disable, filter_linear_mipmap;
uniform vec2 panel_size = vec2(320.0, 180.0);
uniform int shape_mode = 0;
uniform float corner_radius : hint_range(0.0, 128.0, 0.5) = 28.0;
uniform float superellipse_exponent : hint_range(2.0, 12.0, 0.1) = 4.0;
uniform float edge_softness : hint_range(0.25, 4.0, 0.05) = 1.25;
uniform float blur_lod : hint_range(0.0, 8.0, 0.05) = 2.2;
uniform float refraction : hint_range(0.0, 24.0, 0.1) = 4.0;
uniform float dispersion : hint_range(0.0, 8.0, 0.05) = 0.8;
uniform vec4 tint : source_color = vec4(0.72, 0.91, 1.0, 1.0);
uniform float tint_strength : hint_range(0.0, 1.0, 0.01) = 0.16;
uniform float saturation : hint_range(0.0, 2.0, 0.01) = 1.08;
uniform float rim_strength : hint_range(0.0, 2.0, 0.01) = 0.42;
uniform float inner_shadow : hint_range(0.0, 1.0, 0.01) = 0.16;
uniform float noise_strength : hint_range(0.0, 0.08, 0.001) = 0.008;
uniform float visual_intensity : hint_range(0.0, 2.0, 0.01) = 1.0;

float rounded_rect_sdf(vec2 point, vec2 half_size, float radius) {
    vec2 q = abs(point) - max(half_size - vec2(radius), vec2(0.0));
    return length(max(q, vec2(0.0))) + min(max(q.x, q.y), 0.0) - radius;
}

float shape_sdf(vec2 point) {
    vec2 half_size = max(panel_size * 0.5, vec2(1.0));
    if (shape_mode == 1) {
        float radius = min(half_size.x, half_size.y);
        return rounded_rect_sdf(point, half_size, radius);
    }
    if (shape_mode == 2) {
        return length(point) - min(half_size.x, half_size.y);
    }
    if (shape_mode == 3) {
        float exponent = max(superellipse_exponent, 2.0);
        vec2 normalized = abs(point) / half_size;
        float contour = pow(pow(normalized.x, exponent) + pow(normalized.y, exponent), 1.0 / exponent);
        return (contour - 1.0) * min(half_size.x, half_size.y);
    }
    return rounded_rect_sdf(point, half_size, min(corner_radius, min(half_size.x, half_size.y)));
}

float random_value(vec2 point) {
    return fract(sin(dot(point, vec2(12.9898, 78.233))) * 43758.5453);
}

void fragment() {
    vec2 point = (UV - vec2(0.5)) * panel_size;
    float distance_to_edge = shape_sdf(point);
    float alpha = 1.0 - smoothstep(-edge_softness, edge_softness, distance_to_edge);

    vec2 gradient_step = vec2(1.0, 0.0);
    vec2 normal = normalize(vec2(
        shape_sdf(point + gradient_step.xy) - shape_sdf(point - gradient_step.xy),
        shape_sdf(point + gradient_step.yx) - shape_sdf(point - gradient_step.yx)
    ) + vec2(0.00001));
    vec2 refracted_uv = clamp(SCREEN_UV + normal * refraction * SCREEN_PIXEL_SIZE, vec2(0.0), vec2(1.0));
    vec2 channel_offset = normal * dispersion * SCREEN_PIXEL_SIZE;

    vec3 blurred = textureLod(screen_texture, refracted_uv, blur_lod).rgb;
    float red = textureLod(screen_texture, clamp(refracted_uv + channel_offset, vec2(0.0), vec2(1.0)), blur_lod).r;
    float blue = textureLod(screen_texture, clamp(refracted_uv - channel_offset, vec2(0.0), vec2(1.0)), blur_lod).b;
    blurred = vec3(red, blurred.g, blue);

    float luminance = dot(blurred, vec3(0.299, 0.587, 0.114));
    blurred = mix(vec3(luminance), blurred, saturation);
    float effective_tint = clamp(tint_strength * visual_intensity, 0.0, 1.0);
    vec3 color = mix(blurred, tint.rgb, effective_tint);

    float inner_distance = max(-distance_to_edge, 0.0);
    float rim = exp(-inner_distance * 0.12) * rim_strength * visual_intensity;
    float shadow = exp(-inner_distance * 0.045) * inner_shadow;
    color += tint.rgb * rim;
    color *= 1.0 - shadow;
    color += (random_value(FRAGCOORD.xy) - 0.5) * noise_strength;

    COLOR = vec4(max(color, vec3(0.0)), alpha * tint.a);
}
