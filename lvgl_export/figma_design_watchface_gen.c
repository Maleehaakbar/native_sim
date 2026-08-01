/**
 * @file figma_design_watchface_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "figma_design_watchface_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * figma_design_watchface_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "figma_design_watchface_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x000000), 0);
        lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &screen_base, 0);
        lv_obj_t * panel_0 = panel_create(lv_obj_0);
        lv_obj_set_x(panel_0, 0);
        lv_obj_set_y(panel_0, 0);
        lv_obj_set_width(panel_0, 240);
        lv_obj_set_height(panel_0, 240);
        lv_obj_set_style_bg_color(panel_0, lv_color_hex(0x000000), 0);
        lv_obj_set_style_bg_opa(panel_0, 0, 0);
        lv_obj_t * image_0 = image_create(panel_0);
        lv_obj_set_align(image_0, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_x(image_0, 0);
        lv_obj_set_y(image_0, 0);
        lv_obj_set_width(image_0, 240);
        lv_obj_set_height(image_0, 240);
        lv_image_set_src(image_0, img_58546e68);

        lv_obj_t * panel_1 = panel_create(panel_0);
        lv_obj_set_align(panel_1, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_x(panel_1, 5);
        lv_obj_set_y(panel_1, 0);
        lv_obj_set_width(panel_1, 240);
        lv_obj_set_height(panel_1, 210);
        lv_obj_set_style_bg_color(panel_1, lv_color_hex(0x000000), 0);
        lv_obj_set_style_bg_opa(panel_1, 0, 0);
        lv_obj_t * label_0 = label_create(panel_1);
        lv_obj_set_align(label_0, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_x(label_0, -29);
        lv_obj_set_y(label_0, -141);
        lv_obj_set_height(label_0, 61);
        lv_label_bind_text(label_0, &time_variable, NULL);
        lv_obj_set_style_text_font(label_0, font_inter_semi_bold_69, 0);
        lv_obj_set_style_text_color(label_0, lv_color_hex(0xE5E9E5), 0);
        lv_label_set_long_mode(label_0, LV_LABEL_LONG_MODE_CLIP);

        lv_obj_t * label_1 = label_create(panel_1);
        lv_obj_set_align(label_1, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_x(label_1, -61);
        lv_obj_set_y(label_1, -121);
        lv_obj_set_height(label_1, 20);
        lv_label_bind_text(label_1, &date_week, NULL);
        lv_obj_set_style_text_font(label_1, font_inter_regular_21, 0);
        lv_obj_set_style_text_color(label_1, lv_color_hex(0xB6BAB6), 0);
        lv_label_set_long_mode(label_1, LV_LABEL_LONG_MODE_CLIP);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

