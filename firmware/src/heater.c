#include "heater.h"

void heater_init(void) {
    pwm_set_frequency(HEATER_PWM_HZ);
    pwm_set_duty(0);
}

void heater_update(float funnel_temp_c) {
    if (funnel_temp_c < HEATER_ON_C) {
        pwm_set_duty(HEATER_DUTY_ON);
    } else if (funnel_temp_c > HEATER_OFF_C) {
        pwm_set_duty(0);
    }
}
