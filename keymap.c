/* Copyright 2020 Dustin Bosveld <steamyleafjuice@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "keymap.h"
#include "string.h"
#include "g/keymap_combo.h"  // refer: http://combos.gboards.ca/docs/install/

#include <stdio.h>

#ifdef AUTO_SHIFT_ENABLE
#    include "process_auto_shift.h"
#endif

enum layers { _QWERT = 0,
   _HNDD,
   _HNDD_NUM,
   _SYML,
   _FUNL
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERT] = LAYOUT( \
 //,-----------------------------------------------------.                                 ,------------------------------------------------------.
     mBOSSKY,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_ESC,\
 //|--------+--------+--------+--------+--------+--------|                                  |--------+--------+--------+--------+---------+--------|
     kCmdSht,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P, KC_HYPR,\
 //|--------+------------+-------------+------------+------------+------|                   |--------+------------+------------+------------+-----------+--------|
     kOptSht,LCTL_T(KC_A), LALT_T(KC_S),LGUI_T(KC_D),LSFT_T(KC_F),  KC_G,                        KC_H,RSFT_T(KC_J),RGUI_T(KC_K),RALT_T(KC_L),RCTL_T(KC_QUOT), _______,\
 //|--------+------------+------------+------------+------------+------+--------.   ,-------+--------+--------+--------+--------+---------+--------|
 kCmdCtrlSft,        KC_Z,        KC_X,        KC_C,        KC_V,  KC_B,  KC_TAB,    FUN_DEL,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, _______,\
 //`---------------------+------------+-----------+------------+------+--------|   |--------+--------+--------+--------+---------------------------'
                               _______,  _______, NUM_SPC, KC_TAB,                   SYM_ENT, NUM_SPC, SYM_BSC, FUN_DEL \
                            //`------------------------------------'               `------------------------------------'
    ),


// this is based on the handsdown Titanium layout

    [_HNDD] = LAYOUT( \
 //|-------------------------------------------------------------------------|                   |-------------------------------------------------------------------------|
     _______,      _______,      _______,      _______,      _______, _______,                     _______,      _______,      _______,      _______,      _______, _______,\
 //|--------+-------------+-------------+-------------+-------------+--------|                   |--------+-------------+-------------+-------------+-------------+--------|
     _______,        KC_J ,         KC_G,         KC_M,         KC_P,    KC_V,                     KC_SCLN,       KC_DOT,      KC_SLSH,       KC_DQT,      KC_QUOT, _______,\
 //|--------+-------------+-------------+-------------+-------------+--------|                   |--------+-------------+-------------+-------------+-------------+--------|
     _______, LCTL_T(KC_C), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T),    KC_W,                     KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_H), _______,\
 //|--------+-------------+-------------+-------------+-------------+-----------------|  |-------+--------+-------------+-------------+-------------+-------------+--------|
     _______,         KC_X,         KC_F,         KC_L,         KC_D,    KC_B, _______,   _______, KC_MINS,         KC_U,         KC_O,         KC_Y,         KC_K, _______,\
 //`--------+-------------+-------------+-------------+-------------+--------+--------|  |-------+--------+-------------+-------------+-------------+-------------+--------|
                                                  KC_Z,         KC_Q, NUM_KCR,  KC_SPC,   SYM_ENT, NUM_SPC,      SYM_BSC, FUN_DEL \
    ),

   [_HNDD_NUM] = LAYOUT(
 //,------------------------------------------------------.                    ,-----------------------------------------------------.
     mBootLoad,  QWERT,    HNDD, _______, KC_CAPS, KC_ASTG,                      _______, _______, _______, _______, _______, _______,\
 //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      KC_COLN, KC_UNDS, KC_ASTR, KC_QUES, KC_EXLM, _______,\
 //|--------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,  KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                       KC_EQL, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,\
 //|--------+---------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______,   KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, _______,    _______, KC_UNDS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,\
 //`----------------------+--------+--------+--------+-------------|  |--------+--------+--------+--------+--------+-----------------'
                                 _______,  KC_DOT,    KC_0, KC_MINS,    _______, KC_SPC,  KC_LT, KC_GT \
                        //`----------------------------------------'  `------------------------------------'
    ),



    [_SYML] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,    _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------------------------'
                                _______, KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),


    [_FUNL] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                        kAGIN,   kUNDO,    kCUT,   kCOPY,   kPSTE, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                        kCmdW,   kCmdQ, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,    _______, _______, _______, _______, _______, _______, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------------------------'
                                _______, KC_APP,   KC_SPC,  KC_TAB,    _______, _______, _______, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),
};


// 20 fps
#define FRAME_TIMEOUT (1000 / 20)
// static uint16_t anim_timer = 0;

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
// // only the NUM_BSC mod key allows for tapping force hold
//         case NUM_BSC:
//             return false;
//         default:
//             return true;
//     }
// }

#ifdef OLED_DRIVER_ENABLE

const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return OLED_ROTATION_270;
}

// Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    // Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t              buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        // Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            // Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            // increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}

#    define IDLE_FRAMES 5
#    define IDLE_SPEED 20
#    define TAP_FRAMES 2
#    define TAP_SPEED 20
#    define ANIM_FRAME_DURATION 200
#    define ANIM_SIZE 512

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint8_t  current_tap_frame  = 0;
char     wpm_str[6];

static void render_status(void) {
#    ifdef AUTO_SHIFT_ENABLE
    // Auto shift state
    switch (get_autoshift_state()) {
        case true:
            oled_write_P(PSTR("Shift\n"), false);
            break;
        default:
            oled_write_P(PSTR("Nosh\n"), false);
    }
#    else
    oled_write_P(PSTR("NO SH\n"), false);
#    endif
    // Host Keyboard Layer Status
    oled_write_P(PSTR("\n-----\n"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERT:
            oled_write_P(PSTR("Qwert\n"), false);
            break;
        case _HNDD:
            oled_write_P(PSTR("HDTi\n"), false);
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_P(PSTR("\n-----\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _HNDD_NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYML:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FUNL:
            oled_write_P(PSTR("Fn\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    // the below snippet is because of a bug reported that oled_task_user is called too often
    // refer: https://github.com/qmk/qmk_firmware/issues/9375
    if (timer_elapsed(anim_timer) > FRAME_TIMEOUT) {
        anim_timer = timer_read();

        if (is_keyboard_master()) {
            // render_status();
            fade_display();
        } else {
            oled_write(read_logo(), false);
            oled_scroll_right();
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_clear();
        render_status();
        switch (keycode) {
            case mBOSSKY: // maps to a workflow in alfred
                SEND_STRING(SS_LGUI(SS_LSFT(SS_LALT(SS_LCTL("1")))));
                break;

            case mDblCtrl:
                // when keycode QMKBEST is pressed
                // SEND_STRING("QMK is the best thing ever!");
                SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL));
                break;

            case mBootLoad:
                bootloader_jump();
                break;
        }
    }
    return true;
};

#endif // for OLED Driver Enable

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    if (combo_index == JG_Z || combo_index == PV_Q) {
        return (layer_state_is(_HNDD));
    }

    return true;
}