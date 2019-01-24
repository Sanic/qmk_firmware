#include QMK_KEYBOARD_H

// # https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

// # LCTL_T(kc)	CTL_T(kc)	Left Control when held, kc when tapped
// # RCTL_T(kc)		Right Control when held, kc when tapped
// # LSFT_T(kc)	SFT_T(kc)	Left Shift when held, kc when tapped
// # RSFT_T(kc)		Right Shift when held, kc when tapped
// # LALT_T(kc)	ALT_T(kc)	Left Alt when held, kc when tapped
// # RALT_T(kc)	ALGR_T(kc)	Right Alt when held, kc when tapped
// # LGUI_T(kc)	LCMD_T(kc), RWIN_T(kc), GUI_T(kc)	Left GUI when held, kc when tapped
// # RGUI_T(kc)	RCMD_T(kc), RWIN_T(kc)	Right GUI when held, kc when tapped
// 
// # KC_LSPO		Left Shift when held, ( when tapped
// # KC_RSPC		Right Shift when held, ) when tapped
// 
// # MO(layer)	Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)
// # OSL(layer)	Momentarily activates layer until a key is pressed. See One Shot Keys for details.
// # LM(layer, mod)	Momentarily turn on layer (like MO) with mod active as well.
// # LT(layer, kc)	Turn on layer when held, kc when tapped
// # TG(layer)	Toggle layer on or off
// # TO(layer)	Turn on layer when pressed
// # TT(layer)	Normally acts like MO unless it's tapped multiple times, which toggles layer on
// 
// # KC_HYPR		Hold Left Control, Shift, Alt and GUI
// # KC_MEH		Hold Left Control, Shift and Alt
// 
// # KC_AUDIO_MUTE	KC_MUTE	Mute
// # KC_AUDIO_VOL_UP	KC_VOLU	Volume Up
// # KC_AUDIO_VOL_DOWN	KC_VOLD	Volume Down
// 

extern keymap_config_t keymap_config;



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

bool has_layer_changed = false;
static uint8_t current_layer;
static uint8_t previous_layer;

extern rgblight_config_t rgblight_config;

void matrix_scan_user(void){
  uint8_t layer = biton32(layer_state);

  if(current_layer == layer){
    has_layer_changed = false;
  }else
  {
    has_layer_changed = true;
    previous_layer = current_layer;
    current_layer = layer;
  }

  if(has_layer_changed)
  {
    /* uint8_t rgbmode = rgblight_get_mode(); */
    rgblight_config.raw = eeconfig_read_rgblight();

    switch(current_layer) {
      case _QWERTY:

        if(!rgblight_config.enable){
          // If rgb is supposed to be off (no manual config), disable it
          rgblight_disable();
        }else{
          // Else, restore from eeprom
          rgblight_mode_noeeprom(rgblight_config.mode);

        }
        /* if(rgbmode == RGBLIGHT_MODE_STATIC_LIGHT) */


    /*   // TODO load current rgb light eeprom stuff if coming from adjust layer? */
      break;
      case _SYMB:
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom_red();
        /* rgblight_enable(); */
        /* rgblight_setrgb(255,0,0); */
      break;
      case _NAV:
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom_green();
        /* rgblight_enable(); */
        /* rgblight_setrgb(0,255,0); */
      break;
      case _ADJUST:
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom_blue();
        /* rgblight_enable(); */
        /* rgblight_setrgb(0,0,255); */
      break;
    }
    /* if(current_layer == _QWERTY){ */
    /*   rgblight_disable(); */
    /* }else{ */
    /*   rgblight_enable(); */
    /* } */
  }
}

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
#define SYM_L   MO(_SYMB)
#define TSYM_L   TG(_SYMB)
#define KC_SYQU   LT(_SYMB, KC_QUOTE)


#define KC_ALDO LALT_T(KC_DOWN)
/* #define KC_ALAS LALT_T(KC_PAST) */
/* #define KC_CTPL LCTL_T(KC_PSLS) */

// #define KC_NAGR LT(_NAV, KC_GRV)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)
#define KC_ADES LT(_ADJUST, KC_ESC)

#define KC_NAES LT(_NAV, KC_ESC)
#define KC_NAF LT(_NAV, KC_F)

#define KC_LAUP LALT_T(KC_UP)
#define KC_LALE LALT_T(KC_LEFT)

#define KC_GUBS LGUI_T(KC_BSPACE)
#define KC_CTTA LCTL_T(KC_TAB)

#define KC_CTEN LCTL_T(KC_ENTER)
#define KC_GUSP LGUI_T(KC_SPACE)

#define KC_LCTA LCTL(KC_A)
#define KC_LCTE LCTL(KC_E)


//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,TSYM_L  ,                          TSYM_L  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BKSL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NAES ,KC_A    ,KC_S    ,KC_D    ,KC_NAF  ,KC_G    ,KC_HYPR ,                          KC_MEH  ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_SYQU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADES ,KC_HOME ,        KC_END  ,KC_ADES ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,KC_DOWN ,     KC_LAUP ,    KC_GUBS ,KC_CTTA ,        KC_CTEN ,KC_GUSP ,    KC_LALE ,     KC_RIGHT,KC_LBRC ,KC_RBRC ,SYM_L 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,                          _______ ,KC_PPLS ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,KC_PAST ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,KC_GRV  ,_______ ,                          _______ ,KC_PMNS ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,KC_PSLS ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,KC_AMPR ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,KC_BKSL ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_KP_0 ,     KC_COMM ,KC_PDOT ,KC_PEQL ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_WH_U ,KC_MS_U ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LCTA ,KC_UP   ,KC_LCTE ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_F11  ,KC_MS_L ,KC_MS_D ,_______ ,XXXXXXX ,_______ ,                          _______ ,_______ ,KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN2 ,     KC_BTN1 ,    _______ ,_______ ,        _______ ,_______ ,    KC_VOLD ,     KC_VOLU ,KC_MUTE ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};
