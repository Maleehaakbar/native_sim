
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "../lvgl_watch_export/ui.h"
#include <zephyr/logging/log.h>
 #include <lvgl_private.h>


static const int32_t sleep_time_ms = 1000;  
LOG_MODULE_REGISTER(my_app_module, LOG_LEVEL_INF);

struct sys_memory_stats stat;

int main(void)
{       
    int ret;
    static char buf[25] = {0};
    const struct device *display;

    

   // lv_obj_t *screen1 = figma_design_watchface_create();
    //lv_obj_t *screen2 = watchface_create();


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

    
   // ui_init("A:/home/mod/Desktop/nrf/native_sim/");
    ui_init("");
    lv_screen_load(watchface_create());

    lv_sysmon_show_memory(NULL);
    lv_sysmon_show_performance(NULL);
  
    lv_timer_handler(); 

   

    // Do forever
   while (1) {

        time_t now = time(NULL);

        struct tm *tm_info = localtime(&now);
         printf("Time: %02d : %02d : %02d\n",
               tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec);
        sprintf(buf, " %02d : %02d : %02d\n", tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec);
        lv_subject_copy_string(&dsiplay_time, buf);

        // Must be called periodically
        lv_timer_handler();
       
        // Sleep
        k_msleep(sleep_time_ms);
    }

}



/*cant find lv_translation in v9.3 in github adn my downloads but found in documentation*/

/* try generated integrate code directly from vscode lvgl example*/

/*todo: check how to update week*/