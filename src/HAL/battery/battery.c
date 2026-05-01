#include "battery.h"
#include "motor.h"

#define BAT_CH      ADC2
#define DIV_RATIO   3.0f
#define ADC_VREF_V  5.0f
#define LOW_BAT_V   9.0f

#define LED_PORT    GPIOB
#define LED_PIN     PIN0


void BATTERY_init(void) {
    ADC_init(AVCC, DIV_128);
    GPIO_setPinDirection(LED_PORT, LED_PIN, OUTPUT);
    GPIO_setPinValue(LED_PORT, LED_PIN, LOW);
}

f32 BATTERY_getVoltage(void) {
    return ADC_convert_to_v(ADC_read(BAT_CH), ADC_VREF_V) * DIV_RATIO;
}

u8 lowBatState = 0;
u16 stopCounter = 0;

void BATTERY_updateLED(Motor_State motorState) {

    if (motorState == STOP) {
        stopCounter++;

        if (stopCounter > 50) {  // ~50ms تقريبًا
            f32 v = BATTERY_getVoltage();

            if (v < LOW_BAT_V) {
                lowBatState = 1;
            } 
            else if (v > (LOW_BAT_V + 0.5f)) {
                lowBatState = 0;
            }
        }
    } else {
        stopCounter = 0;  // reset أول ما يتحرك
    }

    GPIO_setPinValue(LED_PORT, LED_PIN, lowBatState ? HIGH : LOW);
}
