#include "Motor.h"

#define DDRD  (*(volatile unsigned char*)0x2A)
#define PORTD (*(volatile unsigned char*)0x2B)
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

void Motor_Init(void)
{
    DDRD |= (1 << IN1) | (1 << IN2) | (1 << IN3) | (1 << IN4);
}

void Motor_Forward(void)
{
    PORTD |= (1 << IN1) | (1 << IN3);
    PORTD &= ~((1 << IN2) | (1 << IN4));
}

void Motor_Backward(void)
{
    PORTD |= (1 << IN2) | (1 << IN4);
    PORTD &= ~((1 << IN1) | (1 << IN3));
}

void Motor_Left(void)
{
    PORTD |= (1 << IN3);
    PORTD &= ~(1 << IN4);

    PORTD &= ~(1 << IN1);
    PORTD &= ~(1 << IN2);
}

void Motor_Right(void)
{
    PORTD |= (1 << IN1);
    PORTD &= ~(1 << IN2);

    PORTD &= ~(1 << IN3);
    PORTD &= ~(1 << IN4);
}

void Motor_Stop(void)
{
    PORTD &= ~((1 << IN1) | (1 << IN2) | (1 << IN3) | (1 << IN4));
}