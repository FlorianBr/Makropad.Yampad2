MCU = atmega32u4
BOOTLOADER = caterina

LTO_ENABLE = yes				# Link time optimisation
OLED_ENABLE = yes				# OLED support
OLED_DRIVER = SSD1306			# OLED Driver

MOUSEKEY_ENABLE = no			# mousekeys (Warning: Needs lots of flash)
EXTRAKEY_ENABLE = yes			# Audio/Systemcontrol keys
CONSOLE_ENABLE = no				# No debug console
RGBLIGHT_ENABLE = yes			# Enable RGB underglow
BOOTMAGIC_ENABLE = no			# We have a physical resit button
BACKLIGHT_ENABLE = no			# No keyboard backlight
COMMAND_ENABLE = no				# No Commands for debug
DEBOUNCE_TYPE = sym_eager_pk	# Eager debouncing per key
NKRO_ENABLE = yes				# Enable N-Key Rollover
ENCODER_ENABLE = yes			# enabled encoder
DIP_SWITCH_ENABLE = yes			# for directly wired encoder key
