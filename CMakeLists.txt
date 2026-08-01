cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(native_sim)

zephyr_compile_definitions(_DEFAULT_SOURCE)
target_include_directories(app PRIVATE 
                        lvgl_export)

target_compile_definitions(app PRIVATE
  LV_USE_TINY_TTF=1
  LV_USE_TRANSLATION=1
)

target_sources(app PRIVATE src/main.c
                            src/watchface.c
                            lvgl_export/container_gen.c
                            lvgl_export/label_gen.c
                            lvgl_export/image_gen.c
                            lvgl_export/panel_gen.c
                            lvgl_export/ui_gen.c
                            lvgl_export/figma_design_watchface_gen.c
                            lvgl_export/ui.c
                            lvgl_export/img_58546e68_data.c)
