/**
 * @file ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ui_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t ui_target = UI_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_inter_regular_10;
extern lv_font_t font_inter_regular_10_data;
lv_font_t * font_inter_semi_bold_48;
extern lv_font_t font_inter_semi_bold_48_data;
lv_font_t * font_inter_medium_16;
extern lv_font_t font_inter_medium_16_data;
lv_font_t * font_inter_semi_bold_69;
extern lv_font_t font_inter_semi_bold_69_data;
lv_font_t * font_inter_regular_21;
extern lv_font_t font_inter_regular_21_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * img_58546e68 = NULL;
extern const void * img_58546e68_data;
const void * vec_48_15 = NULL;
extern const void * vec_48_15_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t screen_base;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t date_week;
lv_subject_t display_date;
lv_subject_t dsiplay_time;
lv_subject_t time_variable;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ui_init_gen(const char * asset_path)
{
    char buf[256];

    /* When running from the editor the theme set from the XML should overwrite this */
#if !defined(LV_EDITOR_PREVIEW)
#if LV_USE_THEME_SIMPLE
    lv_display_t * disp = lv_display_get_default();
    lv_theme_t * th = lv_theme_simple_init(disp);
    lv_display_set_theme(disp, th);
#else
    LV_LOG_WARN("Simple theme is selected in project.xml but LV_USE_THEME_SIMPLE is disabled");
#endif
#endif /*LV_EDITOR_PREVIEW*/


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        if (!font_inter_regular_10) {
            /* font_inter_regular_10 */
            /* get font 'font_inter_regular_10' from a C array */
            font_inter_regular_10 = &font_inter_regular_10_data;

        }
        if (!font_inter_semi_bold_48) {
            /* font_inter_semi_bold_48 */
            /* get font 'font_inter_semi_bold_48' from a C array */
            font_inter_semi_bold_48 = &font_inter_semi_bold_48_data;

        }
        if (!font_inter_medium_16) {
            /* font_inter_medium_16 */
            /* get font 'font_inter_medium_16' from a C array */
            font_inter_medium_16 = &font_inter_medium_16_data;

        }
        if (!font_inter_semi_bold_69) {
            /* font_inter_semi_bold_69 */
            /* get font 'font_inter_semi_bold_69' from a C array */
            font_inter_semi_bold_69 = &font_inter_semi_bold_69_data;

        }
        if (!font_inter_regular_21) {
            /* font_inter_regular_21 */
            /* get font 'font_inter_regular_21' from a C array */
            font_inter_regular_21 = &font_inter_regular_21_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        /* img_58546e68 */
        if (!img_58546e68) {
            img_58546e68 = &img_58546e68_data;
        }
        /* vec_48_15 */
        if (!vec_48_15) {
            vec_48_15 = &vec_48_15_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
        if (ui_check_target(UI_TARGET_ALL)) {
            lv_style_init(&screen_base);
            lv_style_set_border_width(&screen_base, 0);
            lv_style_set_radius(&screen_base, 0);
            lv_style_set_shadow_width(&screen_base, 0);
            lv_style_set_shadow_opa(&screen_base, 0);

        }
        #endif
        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    static char date_week_buf[UI_SUBJECT_STRING_LENGTH];
    static char date_week_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&date_week,
                           date_week_buf,
                           date_week_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "05.06 MON"
                          );
    static char display_date_buf[UI_SUBJECT_STRING_LENGTH];
    static char display_date_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&display_date,
                           display_date_buf,
                           display_date_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Tue, 29 JULY"
                          );
    static char dsiplay_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char dsiplay_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&dsiplay_time,
                           dsiplay_time_buf,
                           dsiplay_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "10:45"
                          );
    static char time_variable_buf[UI_SUBJECT_STRING_LENGTH];
    static char time_variable_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&time_variable,
                           time_variable_buf,
                           time_variable_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "20:22"
                          );

    /*----------------
     * Translations
     *----------------*/

    /*#ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif*/

#if LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_inter_regular_10, "font_inter_regular_10");
    check_font(&font_inter_semi_bold_48, "font_inter_semi_bold_48");
    check_font(&font_inter_medium_16, "font_inter_medium_16");
    check_font(&font_inter_semi_bold_69, "font_inter_semi_bold_69");
    check_font(&font_inter_regular_21, "font_inter_regular_21");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_inter_regular_10", font_inter_regular_10);
    lv_xml_register_font(NULL, "font_inter_semi_bold_48", font_inter_semi_bold_48);
    lv_xml_register_font(NULL, "font_inter_medium_16", font_inter_medium_16);
    lv_xml_register_font(NULL, "font_inter_semi_bold_69", font_inter_semi_bold_69);
    lv_xml_register_font(NULL, "font_inter_regular_21", font_inter_regular_21);

    /* Register subjects */
    lv_xml_register_subject(NULL, "date_week", &date_week);
    lv_xml_register_subject(NULL, "display_date", &display_date);
    lv_xml_register_subject(NULL, "dsiplay_time", &dsiplay_time);
    lv_xml_register_subject(NULL, "time_variable", &time_variable);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_58546e68", img_58546e68);
    lv_xml_register_image(NULL, "vec_48_15", vec_48_15);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void ui_set_target(uint32_t target)
{
    ui_target = target;
}

uint32_t ui_get_target(void)
{
    return ui_target;
}

bool ui_check_target(uint32_t target)
{
    return (ui_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}