# Copyright 2022 Markus Knutsson (@TweetyDaBird)
# SPDX-License-Identifier: GPL-2.0-or-later

LTO_ENABLE = yes

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