// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: dial

#ifndef _DIAL_UI_H
#define _DIAL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_mac.h"
#include "esp_app_desc.h"
#include "ui_helpers.h"
#include "ui_events.h"
#include "../usb_device/usb_device.h"
#include "../dial_power/dial_power.h"
#include "../dial/dial.h"
#include "../nvs_data/nvs_data.h"
#include "../display/display.h"
#define DIAL_STA_NUM 10
enum {
    UI_NULL,
    UI_MENU_INTERFACE,            /*!< Main menu select different interface */
    UI_HID_INTERFACE,            /*!< USB menu Control PC or Phone */
    UI_SETTING_INTERFACE,         /*!< Setting menu  */
    UI_HID_CUSTOM_INTERFACE,    /*!< USB Custom Control PC or Phone */
};
enum
{
    DIAL_STA_RELEASE,
    DIAL_STA_PRESS,
    DIAL_STA_R,
    DIAL_STA_L,
    DIAL_STA_CLICK,
    DIAL_STA_DOUBLE_CLICK,
    DIAL_STA_LONG_PRESS,
    DIAL_STA_LONG_PRESS_UP,
    DIAL_STA_P_R,
    DIAL_STA_P_L
};
typedef struct{
    uint8_t index;//current ui screen index
}_ui_state;
struct DIAL_STA_DATA {
    uint8_t hid_data[6];
};
struct UI_HID_ICON_INFO
{
    const void* img_src;
    const char* name;
    const char* left_info;
    const char* mid_info;
    const char* right_info;
};
typedef struct 
{
    uint8_t icon_id; //图标的id
    uint8_t hid_id; //hid设备id
    uint16_t img_angle;//图标的角度
    foc_knob_param_t param_list;
    struct DIAL_STA_DATA dial_sta[DIAL_STA_NUM];
    struct UI_HID_ICON_INFO icon;
}UI_HID_INFO;
extern _ui_state ui_state;
extern int16_t enc_num;
extern int16_t enc_click;
void ui_send_hid_command(uint8_t hid_id,uint8_t keycode[6],uint8_t state);
// SCREEN:
extern lv_obj_t * ui_Screen1; //main screen
extern lv_obj_t * ui_Screen2; //system hid screen
extern lv_obj_t * ui_Screen3; //Customize HID
extern lv_obj_t * ui_Screen_Setting;
extern lv_indev_t* encoder_indev;
// SCREEN: Init and event
void ui_Screen1_dial_event(uint8_t state);
void ui_Screen1_screen_init(void);
void ui_Screen2_hid_event(uint8_t state);
void ui_Screen2_screen_init(void);
void ui_Screen3_screen_init(void);
void ui_Screen3_Custom_hid_event(uint8_t state);
void ui_Screen_Setting_screen_init(void);
void ui_Screen_Setting_event(uint8_t state);
void set_screen2_index();
void set_screen3_index();

LV_IMG_DECLARE(ui_img_bg1_png);    // assets\bg1.png
LV_IMG_DECLARE(ui_img_pc_png);    // assets\pc.png
LV_IMG_DECLARE(ui_img_set_png);    // assets\set.png
LV_IMG_DECLARE(ui_img_power_png);    // assets\power.png
LV_IMG_DECLARE(ui_img_copy_png);    // assets\copy.png
LV_IMG_DECLARE(ui_img_left_right_png);    // assets\left_right.png
LV_IMG_DECLARE(ui_img_dial_png);    // assets\dial.png
LV_IMG_DECLARE(ui_img_up_dowm_png);    // assets\up_dowm.png
LV_IMG_DECLARE(ui_img_wheel_png);    // assets\wheel.png
LV_IMG_DECLARE(ui_img_key_left_right_png);    // assets\key_left_right.png
LV_IMG_DECLARE(ui_img_volume_png);    // assets\volume.png
LV_IMG_DECLARE(ui_img_pointer_png);    // assets\pointer.png
LV_IMG_DECLARE(ui_img_bg_anime_png);    // assets\bg_anime.png
LV_IMG_DECLARE(ui_img_customize_png);    // assets\customize.png
LV_IMG_DECLARE(ui_img_screenrotation_png);    // assets\ScreenRotation.png
LV_IMG_DECLARE(ui_img_wifilogo_png);    // assets\WifiLogo.png
LV_IMG_DECLARE(ui_img_light_png);    // assets\light.png
LV_IMG_DECLARE(ui_img_screenlocklandscape_png);    // assets\ScreenLockLandscape.png
LV_IMG_DECLARE(ui_img_sleep_png);    // assets\sleep.png
LV_IMG_DECLARE(ui_img_ble_png);    // assets\ble.png
LV_IMG_DECLARE(ui_img_home_page_png);    // assets\home_page.png

LV_FONT_DECLARE(ui_font_SmileySansOblique16);
LV_FONT_DECLARE(ui_font_SmileySansOblique20);
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
