/**
 * @file watchface_gen.h
 */

#ifndef WATCHFACE_H
#define WATCHFACE_H

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



lv_obj_t * watchface_create(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WATCHFACE_H*/