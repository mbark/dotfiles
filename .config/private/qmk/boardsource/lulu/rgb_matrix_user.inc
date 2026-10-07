// A key lights up when pressed and fades out, in a rainbow that runs from the
// left edge of the board to the right. The hue setting shifts the rainbow, the
// speed setting changes how fast a key fades.
RGB_MATRIX_EFFECT(RAINBOW_REACTIVE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// effect_runner_reactive doesn't tell its callback which LED it is colouring,
// so this is that runner with the hue taken from the LED's position
static bool RAINBOW_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        // QMK's scale16by8 multiplies by scale + 1, so a key at rest comes out
        // just over 255, which would wrap around below to full brightness
        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        if (offset > 255) offset = 255;
        hsv_t    hsv    = rgb_matrix_config.hsv;
        hsv.h += g_led_config.point[i].x;
        hsv.v = scale8(255 - offset, hsv.v);
        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif
