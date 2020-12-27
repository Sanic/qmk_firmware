#include QMK_KEYBOARD_H

#define _QWERTY 0 // Base qerty
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH // backslash
#define SYM_L   MO(_SYMB) // momentary toggle layeer
#define TSYM_L   TG(_SYMB) // toggle layer  on/off
#define KC_SYQU   LT(_SYMB, KC_QUOTE) //Turn on layer when held, kc when tapped


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
#define KC_LAES LALT_T(KC_ESC)

#define KC_GUBS LGUI_T(KC_BSPACE)
#define KC_CTTA LCTL_T(KC_TAB)

#define KC_CTEN LCTL_T(KC_ENTER)
#define KC_GUSP LGUI_T(KC_SPACE)

#define KC_LCTA LCTL(KC_A)
#define KC_LCTE LCTL(KC_E)


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* [_QWERTY] = LAYOUT( */
/*            KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8, */
/*            KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   , */
/*            KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   , */
/*            KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   , */
/*            KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   , */
/*                    KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT, */
/*                                            KC_LCTL,KC_LALT, */
/*                                                    KC_HOME, */
/*                                     KC_BSPC,KC_DEL ,KC_END, */
/*  */
/*            KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET, */
/*            KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS, */
/*            KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS, */
/*            KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT, */
/*            KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT, */
/*            KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC, */
/*                    KC_RGUI,KC_RCTL, */
/*                    KC_PGUP, */
/*                    KC_PGDN,KC_ENTER ,KC_SPC */
/*     ) */
/* }; */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_NAES,KC_A   ,KC_S   ,KC_D   ,KC_NAF ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_UP  ,KC_DOWN,
                                           KC_LAES,KC_LALT,
                                                   KC_HOME,
                                   KC_GUBS,KC_CTTA, KC_END,

           KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
           KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
           KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BKSL,
           KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_SYQU,
           KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSPC,
           KC_LEFT,KC_RGHT,KC_LBRC,KC_RBRC,
                   KC_ESC ,KC_LAES,
                   KC_PGUP,
                   KC_PGDN,KC_CTEN ,KC_GUSP
),

[_SYMB] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,
           _______,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,
           _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,
           _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,
                   _______,_______,_______,_______,
                                           _______,_______,
                                                   _______,
                                   _______,_______,_______,

           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______,
           KC_PPLS,KC_KP_7,KC_KP_8,KC_KP_9,KC_PAST,_______,
           KC_PMNS,KC_KP_4,KC_KP_5,KC_KP_6,KC_PSLS,_______,
           KC_AMPR,KC_KP_1,KC_KP_2,KC_KP_3,KC_BKSL,XXXXXXX,
           KC_KP_0,KC_COMM,KC_PDOT,KC_PEQL,
                   _______,_______,
                   _______,
                   _______,_______ ,_______
    ),

[_NAV] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
           _______,XXXXXXX,XXXXXXX,XXXXXXX,_______,XXXXXXX,
           _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                           _______,_______,
                                                   _______,
                                   _______,_______,_______,

           _______,_______,_______,_______,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
           XXXXXXX,KC_LCTA,KC_UP  ,KC_LCTE,XXXXXXX,XXXXXXX,
           XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,
           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
           KC_VOLD,KC_VOLU,KC_MUTE,KC_DEL,
                   _______,_______,
                   _______,
                   _______,_______ ,_______
    )


};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}






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
