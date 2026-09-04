/**
 * @file figma_design_watchface_gen.h
 */

#ifndef FIGMA_DESIGN_WATCHFACE_H
#define FIGMA_DESIGN_WATCHFACE_H

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

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * figma_design_watchface_create(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*FIGMA_DESIGN_WATCHFACE_H*/