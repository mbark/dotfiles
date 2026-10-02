#pragma once

// The keymap's own settings. The halves only talk to each other when both are
// built with the same SPLIT_* defines.
#include "../barkis/config.h"

// The one working wire between the halves ends on GP1 on this half (see the
// main config.h)
#undef SERIAL_USART_TX_PIN
#define SERIAL_USART_TX_PIN GP1

// The board's lib/oled.c is compiled even with the display driver off, so give
// it a no-op to call
#ifndef __ASSEMBLER__
#    include <stdint.h>
static inline void oled_write_raw_P(const char *data, uint16_t size) {}
#endif
