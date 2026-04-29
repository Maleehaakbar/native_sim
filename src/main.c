
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <lvgl.h>
#include <string.h>
#include <stdio.h>

static const int32_t sleep_time_ms = 50;   

int main(void)
{       
    uint32_t count = 0;
    int ret;
    static char buf[11] = {0};
    const struct device *display;

    lv_obj_t *hello_label;
    lv_obj_t *counter_label;

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

         // Create a static label widget
    hello_label = lv_label_create(lv_scr_act());
    lv_label_set_text(hello_label, "Hello");
    
    lv_obj_align(hello_label, LV_ALIGN_TOP_MID, 0, 5);
    
    // Create a dynamic label widget
    counter_label = lv_label_create(lv_scr_act());
    lv_obj_align(counter_label, LV_ALIGN_BOTTOM_MID, 0, 0);
    

    lv_obj_set_style_text_color(hello_label, lv_color_white(), 0);
    lv_obj_set_style_text_color(counter_label, lv_color_white(), 0);
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_black(), 0);


    lv_timer_handler(); 

    // Do forever
    while (1) {

        // Update counter label every second
        count++;
        if ((count % (1000 / sleep_time_ms)) == 0) {
            sprintf(buf, "%d", count / (1000 / sleep_time_ms));
            lv_label_set_text(counter_label, buf);
        }

        // Must be called periodically
        lv_timer_handler();

        // Sleep
        k_msleep(sleep_time_ms);
    }
}

