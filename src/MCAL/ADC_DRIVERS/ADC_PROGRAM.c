#include "ADC_INTERFACE.h"

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
            setBit(ADMUX, 6);   // Set REFS0
            clearBit(ADMUX, 7); // Clear REFS1
            break;
        case INTERNAL:
            setBit(ADMUX, 6);   // Set REFS0
            setBit(ADMUX, 7);   // Set REFS1
            break;
    }

    // Clear prescaler bits first
    ADCSRA &= ~(0x07);

    // Set prescaler
    switch (prescaler)
    {
        case DIV_2:
            setBit(ADCSRA, 0);   // Set   ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_4:
            clearBit(ADCSRA, 0); // Clear ADPS0
            setBit(ADCSRA, 1);   // Set   ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_8:
            setBit(ADCSRA, 0);   // Set   ADPS0
            setBit(ADCSRA, 1);   // Set   ADPS1
            clearBit(ADCSRA, 2); // Clear ADPS2
            break;
        case DIV_16:
            clearBit(ADCSRA, 0); // Clear ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            setBit(ADCSRA, 2);   // Set   ADPS2
            break;
        case DIV_32:
            setBit(ADCSRA, 0);   // Set   ADPS0
            clearBit(ADCSRA, 1); // Clear ADPS1
            setBit(ADCSRA, 2);   // Set   ADPS2
            break;
        case DIV_64:
            clearBit(ADCSRA, 0); // Clear ADPS0
            setBit(ADCSRA, 1);   // Set   ADPS1
            setBit(ADCSRA, 2);   // Set   ADPS2
            break;               // was missing in original repo!
        case DIV_128:
            setBit(ADCSRA, 0);   // Set   ADPS0
            setBit(ADCSRA, 1);   // Set   ADPS1
            setBit(ADCSRA, 2);   // Set   ADPS2
            break;
    }

    setBit(ADCSRA, 7); // Enable ADC (ADEN)
}

u16 ADC_read(adc_channel_t channel)
{
    // Select ADC channel (keep upper nibble, set MUX[3:0])
    ADMUX = (ADMUX & 0xF0) | (channel & 0x07);

    // Start conversion
    setBit(ADCSRA, 6); // Set ADSC

    // Wait for conversion to complete
    while (readBit(ADCSRA, 6)); // Wait until ADSC is cleared by hardware

    // Return ADC value (read ADCL first — locks ADCH)
    return (u16)(ADCL | (ADCH << 8));
}

void ADC_freeRunning(adc_channel_t channel)
{
    // Select ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x07);

    // ATmega328P: use ADCSRB instead of SFIOR
    // ADTS2:ADTS1:ADTS0 = 000 → free running mode
    clearBit(ADCSRB, 2); // Clear ADTS2
    clearBit(ADCSRB, 1); // Clear ADTS1
    clearBit(ADCSRB, 0); // Clear ADTS0

    setBit(ADCSRA, 5);   // Set ADATE (auto trigger enable)
    setBit(ADCSRA, 6);   // Set ADSC  (start conversion)
}

f32 ADC_convert_to_v(u16 adc_value, f32 vref)
{
    f32 voltage = (adc_value / 1023.0f) * vref;
    return voltage;
}

f32 ADC_read_v(adc_channel_t channel, f32 vref)
{
    u16 adc_value = ADC_read(channel);
    f32 voltage   = (adc_value / 1023.0f) * vref;
    return voltage;
}