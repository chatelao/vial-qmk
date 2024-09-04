# Copyright 2022 Markus Knutsson (@TweetyDaBird)
# SPDX-License-Identifier: GPL-2.0-or-later

# Needed for VIAL compatability (all are needed)
VIA_ENABLE         = yes
VIAL_ENABLE        = yes
# VIALRGB_ENABLE     = yes
# ENCODER_MAP_ENABLE = yes
CONSOLE_ENABLE     = yes

# OLI
LTO_ENABLE = yes
# RGBLIGHT_ENABLE = yes  # 24'248 -> 27'870 = 3'632
# BACKLIGHT_ENABLE = no  # 24'248 -> ...
# OLED_ENABLE = yes      # 24'248 -> 24'842 =   624
QMK_SETTINGS = yes     # 24'248 -> 28'672 = 4'424

# Reduce size on atmega32u4
ifeq ($(strip $(CONVERT_TO)), )
    TAP_DANCE_ENABLE = no
    QMK_SETTINGS = no
    KEY_OVERRIDE_ENABLE = no
    COMBO_ENABLE = no
    
	# Reduce size even more for non-nanoboot bootloaders
    ifneq ($(strip $(BOOTLOADER_SIZE)), 512)
        MAGIC_ENABLE = no
        MOUSEKEY_ENABLE = no
    endif
endif