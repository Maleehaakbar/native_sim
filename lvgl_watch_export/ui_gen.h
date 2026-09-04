/**
 * @file ui_gen.h
 */

#ifndef UI_GEN_H
#define UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include <lvgl.h>
    #include <lvgl_private.h>
#endif

/*#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif*/



/* Prototypes for target functions, needed by responsive const definitions */

void ui_set_target(uint32_t target);
uint32_t ui_get_target(void);
bool ui_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define UI_TARGET_UNDEFINED  (0 << 1)
#define UI_TARGET_TARGET1    (1 << 1)
#define UI_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef UI_COMPILE_TARGET
#define UI_COMPILE_TARGET UI_TARGET_ALL
#endif

#define UI_CHECK_COMPILE_TARGET(target) (UI_COMPILE_TARGET & (target) ? 1 : 0)

#define BASE_ACCENT lv_color_hex(0x70609C)
#define BASE_UNIT_SM 4


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t screen_base;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_inter_regular_10;
extern lv_font_t * font_inter_semi_bold_48;
extern lv_font_t * font_inter_medium_16;
extern lv_font_t * font_inter_semi_bold_69;
extern lv_font_t * font_inter_regular_21;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * img_58546e68;
extern const void * vec_48_15;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t date_week;
extern lv_subject_t display_date;
extern lv_subject_t dsiplay_time;
extern lv_subject_t time_variable;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "card_gen.h"
#include "container_gen.h"
#include "image_gen.h"
#include "label_gen.h"
#include "panel_gen.h"
#include "figma_design_watchface_gen.h"
#include "watchface_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_GEN_H*/