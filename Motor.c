#include "Motor.h"

// Motor A (Left)
#define A_IN1_PORT GPIOB
#define A_IN1_PIN  PIN0

#define A_IN2_PORT GPIOB
#define A_IN2_PIN  PIN1

// Motor B (Right)
#define B_IN1_PORT GPIOB
#define B_IN1_PIN  PIN2

#define B_IN2_PORT GPIOB
#define B_IN2_PIN  PIN3

void Motor_init(void)
{
    GPIO_setPinDirection(A_IN1_PORT, A_IN1_PIN, OUTPUT);
    GPIO_setPinDirection(A_IN2_PORT, A_IN2_PIN, OUTPUT);
    GPIO_setPinDirection(B_IN1_PORT, B_IN1_PIN, OUTPUT);
    GPIO_setPinDirection(B_IN2_PORT, B_IN2_PIN, OUTPUT);

    Motor_move(STOP);
}

void Motor_move(Motor_State state)
{
    switch(state)
    {
        case STOP:
            GPIO_setPinValue(A_IN1_PORT, A_IN1_PIN, LOW);
            GPIO_setPinValue(A_IN2_PORT, A_IN2_PIN, LOW);
            GPIO_setPinValue(B_IN1_PORT, B_IN1_PIN, LOW);
            GPIO_setPinValue(B_IN2_PORT, B_IN2_PIN, LOW);
            break;

        case FORWARD:
            GPIO_setPinValue(A_IN1_PORT, A_IN1_PIN, HIGH);
            GPIO_setPinValue(A_IN2_PORT, A_IN2_PIN, LOW);

            GPIO_setPinValue(B_IN1_PORT, B_IN1_PIN, HIGH);
            GPIO_setPinValue(B_IN2_PORT, B_IN2_PIN, LOW);
            break;

        case BACKWARD:
            GPIO_setPinValue(A_IN1_PORT, A_IN1_PIN, LOW);
            GPIO_setPinValue(A_IN2_PORT, A_IN2_PIN, HIGH);

            GPIO_setPinValue(B_IN1_PORT, B_IN1_PIN, LOW);
            GPIO_setPinValue(B_IN2_PORT, B_IN2_PIN, HIGH);
            break;

        case RIGHT:
            // الموتور( A ) بيتحرك لقدام
            GPIO_setPinValue(A_IN1_PORT, A_IN1_PIN, HIGH);
            GPIO_setPinValue(A_IN2_PORT, A_IN2_PIN, LOW);
            // الموتور( B ) بيتحرك للخلف
            GPIO_setPinValue(B_IN1_PORT, B_IN1_PIN, LOW);
            GPIO_setPinValue(B_IN2_PORT, B_IN2_PIN, HIGH);
            break;

        case LEFT:
            // الموتور( A ) بيتحرك للخلف
            GPIO_setPinValue(A_IN1_PORT, A_IN1_PIN, LOW);
            GPIO_setPinValue(A_IN2_PORT, A_IN2_PIN, HIGH);
            // الموتور( B ) بيتحرك لقدام
            GPIO_setPinValue(B_IN1_PORT, B_IN1_PIN, HIGH);
            GPIO_setPinValue(B_IN2_PORT, B_IN2_PIN, LOW);
            break;
    }
}