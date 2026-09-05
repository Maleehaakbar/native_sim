cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(native_sim)

zephyr_compile_definitions(_DEFAULT_SOURCE)
target_include_directories(app PRIVATE 
                        lvgl_export)

target_sources(app PRIVATE src/main.c
                           src/app_create.c
                            lvgl_watch_export/card_gen.c
                            lvgl_watch_export/container_gen.c
                            lvgl_watch_export/label_gen.c
                            lvgl_watch_export/image_gen.c
                            lvgl_watch_export/panel_gen.c
                            lvgl_watch_export/figma_design_watchface_gen.c
                            lvgl_watch_export/watchface_gen.c
                            lvgl_watch_export/ui_gen.c
                            lvgl_watch_export/ui.c
                            lvgl_watch_export/images/img_58546e68_data.c
                            lvgl_watch_export/images/vec_48_15_data.c
                            fonts/font_inter_medium_16_data.c
                            fonts/font_inter_regular_10_data.c
                            fonts/font_inter_regular_21_data.c
                            fonts/font_inter_semi_bold_48_data.c
                            fonts/font_inter_semi_bold_69_data.c
                            )
