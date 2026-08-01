
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "watchface.h"
#include "../lvgl_export/ui.h"
#include <zephyr/logging/log.h>

static const int32_t sleep_time_ms = 1000;  
LOG_MODULE_REGISTER(my_app_module, LOG_LEVEL_INF);

int main(void)
{       
    int ret;
    static char buf[25] = {0};
    const struct device *display;
    lv_obj_t *timer_label;

    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);


    display  = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display)) {
        printk("Error: display not ready\r\n");
        return 0;
    }

    k_sleep(K_MSEC(100));

    ret = display_blanking_off(display);
	if (ret < 0 && ret != -ENOSYS) {
		printk("Failed to turn blanking off (error %d)", ret);
		return 0;
    }

    LOG_INF("Pool1: total=%zu, used=%zu (%d%%), free_biggest=%zu",
        mon.total_size, mon.total_size - mon.free_size,
        mon.used_pct, mon.free_biggest_size);
	
    //ui_init("/home/mod/Desktop/nrf/native_sim/lvgl_export/assets");
    ui_init("A:/home/mod/Desktop/nrf/native_sim/");
    
    LOG_INF("Pool2: total=%zu, used=%zu (%d%%), free_biggest=%zu",
        mon.total_size, mon.total_size - mon.free_size,
        mon.used_pct, mon.free_biggest_size);
  
    lv_screen_load(figma_design_watchface_create());
    
    LOG_INF("Pool3: total=%zu, used=%zu (%d%%), free_biggest=%zu",
        mon.total_size, mon.total_size - mon.free_size,
        mon.used_pct, mon.free_biggest_size);

    lv_timer_handler(); 

    // Do forever
   while (1) {

       /* time_t now = time(NULL);

        struct tm *tm_info = localtime(&now);
         printf("Time: %02d : %02d : %02d\n",
               tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec);
        sprintf(buf, " %02d : %02d : %02d\n", tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec);
         lv_label_set_text(timer_label,buf);
    
         lv_obj_align(timer_label, LV_ALIGN_TOP_MID, 0, 5);*/

        // Must be called periodically
        lv_timer_handler();

        // Sleep
        k_msleep(sleep_time_ms);
    }

}



/*cant find lv_translation in v9.3 in github adn my downloads but found in documentation*/

/* try generated integrate code directly from vscode lvgl example*/