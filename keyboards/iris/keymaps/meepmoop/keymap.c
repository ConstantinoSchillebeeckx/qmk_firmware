#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_ADJ MO(_ADJUST)  // Toggle layer ADJUDST
#define KC_MS_D KC_MS_DOWN
#define KC_MS_L KC_MS_LEFT
#define KC_MS_R KC_MS_RIGHT
#define KC_MS_1 KC_MS_BTN1
#define KC_MS_2 KC_MS_BTN2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,    ,     ENT , N  , M  ,COMM,DOT ,SLSH,,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LGUI,SPC,         ENT,ADJ,SPC
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    GRV,    ,    ,    ,    ,    ,                    ,    ,    ,MINUS,EQL,   ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                  ,    , UP ,LBRC,RBRC,BSLASH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,LEFT,DOWN,RIGHT,    ,   ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    , ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
