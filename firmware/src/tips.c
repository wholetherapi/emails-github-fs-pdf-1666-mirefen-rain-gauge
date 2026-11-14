#include "tips.h"
#include "heater.h"

static volatile uint32_t last_tip_ms;

void tips_init(void) {
    gpio_configure_reeds();
    heater_init();
}

void tips_on_edge(uint32_t now_ms) {
    if (now_ms - last_tip_ms < TIP_DEBOUNCE_MS) {
        return;
    }
    last_tip_ms = now_ms;
    bucket_count_increment();
}
