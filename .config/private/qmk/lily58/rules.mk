WPM_ENABLE = yes
LTO_ENABLE = yes

EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

 # If you want to change the display of OLED, you need to change here
 SRC +=  ./lib/rgb_state_reader.c \
         ./lib/layer_state_reader.c \
         ./lib/logo_reader.c \
         ./lib/keylogger.c \
         # ./lib/mode_icon_reader.c \
         # ./lib/host_led_state_reader.c \
         # ./lib/timelogger.c \
