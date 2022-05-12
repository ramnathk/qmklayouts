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

/* Add definitions for MT and LT */


// HNDD exclusive 

// #define NAV_KCL  LT(_HNDD_NUM, KC_L)
#define NUM_LPRN LT(_HNDD_NUM, KC_LPRN)
#define NUM_RPRN LT(_HNDD_NUM, KC_RPRN)
#define NUM_KCR LT(_HNDD_NUM, KC_R)
#define NUM_SPC LT(_HNDD_NUM, KC_SPC)
#define NUM_BSC LT(_HNDD_NUM, KC_BSPC)
#define FUN_DEL LT(_FUNL, KC_DEL)
#define SYM_BSC LT(_SYML, KC_BSPC)


// end HND exclusives

#define NAV_SPC LT(_HNDD_NUM, KC_SPC)
#define NAV_BSC LT(_HNDD_NUM, KC_BSPC)
#define SYM_ENT LT(_SYML, KC_ENT)
#define FN_DEL LT(_FUNL, KC_DEL)

#define HNDD DF(_HNDD)
#define QWERT DF(_QWERT)

#define kCmdSht G(KC_LSFT)
#define kCmdCtrlSft G(S(KC_LCTL))
#define kOptSht A(KC_LSFT)
#define kAGIN SCMD(KC_Z)
#define kUNDO LCMD(KC_Z)
#define kCUT LCMD(KC_X)
#define kCOPY LCMD(KC_C)
#define kPSTE LCMD(KC_V)

enum kSplKeys {
    mBOSSKY = SAFE_RANGE,
    mDblCtrl,
    mBootLoad,
};
