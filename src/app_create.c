#include <lvgl.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <string.h>
#include <stdio.h>


#include "../lvgl_watch_export/ui.h"

extern lv_obj_t* watchface;  //todo: make global variable sharing neat 

lv_obj_t* screen2;
lv_obj_t *menu;

int id;
lv_obj_t *watchface_img;

void update_watchface(void);

/*button callback of watchface screen*/
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        lv_screen_load(screen2);
    }
    
}

/*callback of root button on menu page*/
static void back_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * menu = lv_event_get_user_data(e);

    if(lv_menu_back_button_is_root(menu, obj)) {
       lv_screen_load(watchface);   //if menu main page button click , go back to watchface screen
    }
}

/*callback event for selection of watchface*/
 void watchface_select_event_handler(lv_event_t * e)
{
    id = (int)lv_event_get_user_data(e);

    update_watchface();

    /* Go back to the main/watchface screen */
   // lv_screen_load(watchface);
}

void create_menu_screen()   
{
    lv_obj_t* cont;
    lv_obj_t* label;

    lv_obj_t* cont_1;
    lv_obj_t* label_1;

    screen2  = lv_obj_create(NULL);

   
    menu = lv_menu_create(screen2);  //create screen
    lv_menu_set_mode_root_back_button(menu, LV_MENU_ROOT_BACK_BUTTON_ENABLED);   //from sub page, root button is created to navigate back
    lv_obj_add_event_cb(menu, back_event_handler, LV_EVENT_CLICKED, menu);
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_center(menu);


    /*Create sub pages*/
    lv_obj_t * sub_1_page = lv_menu_page_create(menu, "Page 1");
    cont = lv_menu_cont_create(sub_1_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "watchface picker");
    lv_obj_set_style_bg_color(sub_1_page, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(sub_1_page, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * picker_cont = lv_obj_create(sub_1_page);
    lv_obj_set_size(picker_cont, lv_pct(100), lv_pct(80)); // Leaves room for headers
    lv_obj_set_flex_flow(picker_cont, LV_FLEX_FLOW_ROW_WRAP); // Allows images to wrap nicely
    lv_obj_set_flex_align(picker_cont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    /* Watchface option 1 */
    lv_obj_t * img1 = lv_img_create(picker_cont);
    lv_img_set_src(img1, img_58546e68);
    lv_obj_set_size(img1, 40, 40);
    lv_obj_add_flag(img1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_t *img_label1 = lv_label_create(picker_cont);
    lv_label_set_text(img_label1, "image1");
    lv_obj_add_event_cb(img1, watchface_select_event_handler, LV_EVENT_CLICKED, (void*)0);

    /* Watchface option 2 */
    lv_obj_t * img2 = lv_img_create(picker_cont);
    lv_img_set_src(img2, vec_48_15);
    lv_obj_set_size(img2, 40, 40);
    lv_obj_add_flag(img2, LV_OBJ_FLAG_CLICKABLE);
     lv_obj_t *img_label2 = lv_label_create(picker_cont);
    lv_label_set_text(img_label2, "image2");
    lv_obj_add_event_cb(img2, watchface_select_event_handler, LV_EVENT_CLICKED, (void*)1);

    /*menu main page*/
    lv_obj_t * main_page = lv_menu_page_create(menu, NULL);
    /*create a container in main page*/
    cont = lv_menu_cont_create(main_page); 
    label = lv_label_create(cont);
    lv_label_set_text(label, "Settings");

    /*load sub page for settings*/
    lv_menu_set_load_page_event(menu, cont, sub_1_page);


    /*use new cont and label variables if needed later*/
    cont_1 = lv_menu_cont_create(main_page); 
    label_1 = lv_label_create(cont_1);
    lv_label_set_text(label_1, "calculator");

    /*set the menu main page*/
    lv_menu_set_page(menu, main_page);
     
}    


/*create menu button on active screen*/
void create_menu_button(lv_obj_t *parent)
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(parent);

    /*register button event*/
    lv_obj_add_event_cb(btn1, event_handler,LV_EVENT_CLICKED, NULL);
    lv_obj_align(btn1,LV_ALIGN_TOP_LEFT, 10, 10);

     label = lv_label_create(btn1);
    lv_label_set_text(label, "menu");
    lv_obj_center(label);
}


/*init main screen with menu button*/
void init_main_screen(void)
{   

    //create menu button(on main screen)
    create_menu_button(watchface);     
    
    //load watchface screen/main screen
    lv_screen_load(watchface); 
}

/*update just image , dynamic text etc will be updated auto */
void update_watchface(void)  
{   
    lv_obj_delete(watchface); /*delete the previous watchface so RAM is no consumed when new watchface create/updated*/

    if(id == 0) {
       watchface = figma_design_watchface_create();      
    }
    else {
      watchface =  watchface_create();
    }

    init_main_screen(); 
}
