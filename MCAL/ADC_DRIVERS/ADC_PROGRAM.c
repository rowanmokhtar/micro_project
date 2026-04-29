#include "ADC_INTERFACE.h"
#include "..\MICRO_PROJECT\MCAL\GPIO_Drivers\GPIO_INTERFACE.h"

void ADC_init(adc_vref_t vref, adc_prescaler_t prescaler)
{
    // Set reference voltage
    switch (vref)
    {
        case AREF:
            clearBit(ADMUX, 6); // Clear REFS0
            clearBit(ADMUX, 7); // Clear REFS1
            break;
        case AVCC:
            setBit(ADMUX, 6);  // Set REFS0
            clearBit(ADMUX, 7); // Clear REFS1
            break;
        case INTERNAL:
            setBit(ADMUX, 6);  // Set REFS0
            setBit(ADMUX, 7);  // Set REFS1
            break;
    }

    // Set prescaler
    switch (prescaler)
    {
        case DIV_2:
            setBit(ADCSRA, 0); // Set ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_4:
            clearBit(ADCSRA, 0); // Clear ADPS0
            setBit(ADCSRA, 1);  // Set ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_8:
            setBit(ADCSRA, 0); // Set ADPS0
            setBit(ADCSRA, 1); // Set ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_16:
            clearBit(ADCSRA, 0); // Clear ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            setBit(ADCSRA, 2);  // Set ADPS2
            break;
        case DIV_32:
            setBit(ADCSRA, 0); // Set ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            setBit(ADCSRA, 2);  // Set ADPS2
            break;
        case DIV_64:
            clearBit(ADCSRA, 0); // Clear ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            setBit(ADCSRA, 2);  // Set ADPS2
            break;
        case DIV_128:
            setBit(ADCSRA, 0); // Set ADPS0
            setBit(ADCSRA, 1); // Set ADPS1
            setBit(ADCSRA, 2);  // Set ADPS2
            break;
    }
    setBit(ADCSRA, 7); // Enable ADC
}

u16 ADC_read(adc_channel_t channel)
{
    // Select ADC channel
    ADMUX = (ADMUX & 0xE0) | channel; // Clear MUX bits and set new channel
    // Start conversion
    setBit(ADCSRA, 6); // Set ADSC bit to start conversion
    // Wait for conversion to complete
    while (readBit(ADCSRA, 6)); // Wait until ADSC bit is cleared
    // Return ADC value
    return (ADCL | (ADCH << 8));
}

void ADC_freeRunning(adc_channel_t channel)
{
    // Select ADC channel
    ADMUX = (ADMUX & 0xE0) | channel; // Clear MUX bits and set new channel
    // Start conversion
    setBit(ADCSRA, 5); // Set ADATE bit to enable auto-triggering
clearBit(ADCSRB, 0);
clearBit(ADCSRB, 1);
clearBit(ADCSRB, 2);
    setBit(ADCSRA, 6); // Set ADSC bit to start conversion
    
}


f32 ADC_convert_to_v(u16 adc_value, f32 vref)
{
    f32 voltage = (adc_value / 1023.0) * vref;
    return voltage;
}

f32 ADC_read_v(adc_channel_t channel, f32 vref)
{
    u16 adc_value = ADC_read(channel);
    f32 voltage = (adc_value / 1023.0) * vref;
    return voltage;
}