
BOOTLOADER = atmel-dfu

ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no      # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
BOOTMAGIC_ENABLE = no    # Bootmagic lite (only reset)
AUTO_SHIFT_ENABLE = no

EXTRAFLAGS += -flto
KEY_OVERRIDE_ENABLE = yes


SRC += lib/logo_reader.c