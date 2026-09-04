/**
 * @file watchface_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "watchface_gen.h"
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

lv_obj_t * watchface_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        /*remove it to save memory , as these are convienent to find objects with human readable text, also make it compatible with previous version*/
        //lv_obj_set_name_static(lv_obj_0, "watchface_#");  
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x000000), 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &screen_base, 0);
        lv_obj_t * card_0 = card_create(lv_obj_0);
        lv_obj_set_align(card_0, LV_ALIGN_CENTER);
        lv_obj_set_x(card_0, 0);
        lv_obj_set_y(card_0, 0);
        lv_obj_set_width(card_0, 240);
        lv_obj_set_height(card_0, 240);
        lv_obj_set_style_bg_color(card_0, lv_color_hex(0x303030), 0);
        lv_obj_set_style_border_color(card_0, lv_color_hex(0x1E1E1E), 0);
        lv_obj_set_style_border_width(card_0, 10, 0);
        lv_obj_set_style_radius(card_0, 32767, 0);

        lv_obj_t * container_0 = container_create(lv_obj_0);
        lv_obj_set_x(container_0, 149);
        lv_obj_set_y(container_0, 173);
        lv_obj_set_width(container_0, 61);
        lv_obj_set_height(container_0, 12);
        lv_obj_t * container_1 = container_create(container_0);
        lv_obj_set_x(container_1, 0);
        lv_obj_set_y(container_1, 2);
        lv_obj_set_width(container_1, 22);
        lv_obj_set_height(container_1, 10);
        lv_obj_set_style_border_color(container_1, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_style_border_width(container_1, 1, 0);

        lv_obj_t * label_0 = label_create(container_0);
        lv_obj_set_x(label_0, 31);
        lv_obj_set_y(label_0, 0);
        lv_obj_set_height(label_0, 10);
        lv_label_set_text(label_0, "85%");
        lv_obj_set_style_text_font(label_0, font_inter_regular_10, 0);
        lv_obj_set_style_text_color(label_0, lv_color_hex(0xFFFFFF), 0);
        lv_label_set_long_mode(label_0, LV_LABEL_LONG_MODE_CLIP);

        lv_obj_t * panel_0 = panel_create(lv_obj_0);
        lv_obj_set_align(panel_0, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(panel_0, -72);
        lv_obj_set_y(panel_0, 177);
        lv_obj_set_width(panel_0, 16);
        lv_obj_set_height(panel_0, 6);
        lv_obj_set_style_bg_color(panel_0, lv_color_hex(0xD9D9D9), 0);

        lv_obj_t * label_1 = label_create(lv_obj_0);
        lv_obj_set_align(label_1, LV_ALIGN_TOP_MID);
        lv_obj_set_x(label_1, 5);
        lv_obj_set_y(label_1, 85);
        lv_obj_set_height(label_1, 58);
        lv_label_bind_text(label_1, &dsiplay_time, NULL);
        lv_obj_set_style_text_font(label_1, font_inter_semi_bold_48, 0);
        lv_obj_set_style_text_color(label_1, lv_color_hex(0xFFFFFF), 0);

        lv_obj_t * label_2 = label_create(lv_obj_0);
        lv_obj_set_x(label_2, 64);
        lv_obj_set_y(label_2, 143);
        lv_obj_set_height(label_2, 17);
        lv_label_bind_text(label_2, &display_date, NULL);
        lv_obj_set_style_text_font(label_2, font_inter_medium_16, 0);
        lv_obj_set_style_text_color(label_2, lv_color_hex(0xB0B6BE), 0);
        lv_label_set_long_mode(label_2, LV_LABEL_LONG_MODE_CLIP);

        lv_obj_t * image_0 = image_create(lv_obj_0);
        lv_obj_set_x(image_0, 93);
        lv_obj_set_y(image_0, 178);
        lv_obj_set_width(image_0, 6);
        lv_obj_set_height(image_0, 10);
        lv_image_set_src(image_0, vec_48_15);
        lv_obj_set_style_bg_color(image_0, lv_color_hex(0xF3F3F3), 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

