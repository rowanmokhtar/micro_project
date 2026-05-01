#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "ADC_PRIVATE.h"

typedef enum
{
    AREF,
    AVCC,
    INTERNAL
} adc_vref_t;

typedef enum
{
    DIV_2,
    DIV_4,
    DIV_8,
    DIV_16,
    DIV_32,
    DIV_64,
    DIV_128
} adc_prescaler_t;

typedef enum
{
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5
} adc_channel_t;

void ADC_init        (adc_vref_t vref, adc_prescaler_t prescaler);
u16  ADC_read        (adc_channel_t channel);
void ADC_freeRunning (adc_channel_t channel);
f32  ADC_convert_to_v(u16 adc_value, f32 vref);
f32  ADC_read_v      (adc_channel_t channel, f32 vref);

<<<<<<< HEAD:src/MCAL/ADC_DRIVERS/ADC_INTERFACE.h
#endif /* ADC_INTERFACE_H */
=======
void ADC_init(adc_vref_t vref, adc_prescaler_t prescaler);
u16 ADC_read(adc_channel_t channel);
void ADC_freeRunning(adc_channel_t channel);
f32 ADC_convert_to_v(u16 adc_value, f32 vref);
f32 ADC_read_v(adc_channel_t channel, f32 vref);

#endif // ADC_INTERFACE_H
>>>>>>> 3cd5e5031fe010ce0452b7c155e8674a55259b2a:MCAL/ADC_DRIVERS/ADC_INTERFACE.h
