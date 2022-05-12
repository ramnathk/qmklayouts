

enum combos {
    UI_BKSPC,
    IO_DEL,
    UIO_ALTBKSPC,
    IOP_ALTDEL,

    //HD specific. Should be disallowed on all other layers
    JG_Z,
    PV_Q,
    C_LENGTH, // always keep as the last entry
};

uint16_t COMBO_LEN = C_LENGTH; //reserved do not remove

const uint16_t PROGMEM ui_combo[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM iop_combo[] = {KC_I, KC_O, KC_P, COMBO_END};

// HD specific layers
const uint16_t PROGMEM jg_combo[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM pv_combo[]  = {KC_R, KC_T, COMBO_END};

combo_t key_combos[C_LENGTH] = {
    COMBO(ui_combo,     KC_BSPC),
    COMBO(io_combo,     KC_DEL),
    COMBO(uio_combo,    A(KC_BSPC)),
    COMBO(iop_combo,    A(KC_DEL)),
    COMBO(jg_combo,     KC_Z),
    COMBO(pv_combo,     KC_Q)
};