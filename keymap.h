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

// #define NAV_KCL  LT(_NUM, KC_L)
#define NUM_LPRN LT(_NUM, KC_LPRN)
#define NUM_RPRN LT(_NUM, KC_RPRN)
#define NUM_KCR LT(_NUM, KC_R)
#define NUM_SPC LT(_NUM, KC_SPC)
#define SYM_SPC LT(_SYML, KC_SPC)
#define FUN_DEL LT(_FUNL, KC_DEL)
#define SYM_TAB LT(_SYML, KC_TAB)


// end HND exclusives

#define SYM_ENT LT(_SYML, KC_ENT)

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
#define kCmdW LCMD(KC_W)
#define kCmdQ LCMD(KC_Q)

enum kSplKeys {
    mBOSSKY = SAFE_RANGE,
    mDblCtrl,
    mBootLoad,
};
