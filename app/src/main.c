/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <settings/settings.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/matrix.h>
#include <zmk/kscan.h>
#include <zmk/display.h>
#include <drivers/ext_power.h>

#ifdef CONFIG_ZMK_MOUSE
#include <zmk/mouse.h>
#endif /* CONFIG_ZMK_MOUSE */

#ifdef CONFIG_ZMK_POINT_DEVICE
#include <zmk/point_device.h>
#endif /* CONFIG_ZMK_POINT_DEVICE */

#define ZMK_KSCAN_DEV DT_LABEL(ZMK_MATRIX_NODE_ID)

void main(void) {
    LOG_INF("Welcome to ZMK!\n");
    k_msleep(5000);

    if (zmk_kscan_init(ZMK_KSCAN_DEV) != 0) {
        return;
    }

#ifdef CONFIG_ZMK_DISPLAY
    zmk_display_init();
#endif /* CONFIG_ZMK_DISPLAY */

#ifdef CONFIG_ZMK_MOUSE
    zmk_mouse_init();
#endif /* CONFIG_ZMK_MOUSE */

#ifdef CONFIG_ZMK_POINT_DEVICE
    zmk_pd_init();
#endif /* CONFIG_ZMK_POINT_DEVICE */
}
