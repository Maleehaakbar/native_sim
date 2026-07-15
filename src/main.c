
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "watchface.h"


static const int32_t sleep_time_ms = 1000;  

int main(void)
{       
    int ret;
    static char buf[25] = {0};
    const struct device *display;
    lv_obj_t *timer_label;

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
    
   // timer_label =  lv_label_create(lv_scr_act());
   lv_obj_t *watchface_img = lv_img_create(lv_scr_act());
   lv_img_set_src(watchface_img, &watchface);
   lv_obj_center(watchface_img);

    
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

