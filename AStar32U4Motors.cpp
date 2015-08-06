// Copyright Pololu Corporation.  For more information, see http://www.pololu.com/

#include <AStar32U4Motors.h>
#include <FastGPIO.h>
#include <avr/io.h>

#define PWM_M1 9
#define PWM_M2 10
#define DIR_M1 12
#define DIR_M2 IO_E2

static bool _flipM1 = false;
static bool _flipM2 = false;

// initialize timer1 to generate the proper PWM outputs to the motor drivers
void AStar32U4Motors::init2()
{
    FastGPIO::Pin<PWM_M1>::setOutputLow();
    FastGPIO::Pin<PWM_M2>::setOutputLow();
    FastGPIO::Pin<DIR_M1>::setOutputLow();
    FastGPIO::Pin<DIR_M2>::setOutputLow();

    // Timer 1 configuration
    // prescaler: clockI/O / 1
    // outputs enabled
    // phase-correct PWM
    // top of 400
    //
    // PWM frequency calculation
    // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
    TCCR1A = 0b10100000;
    TCCR1B = 0b00010001;
    ICR1 = 400;
    OCR1A = 0;
    OCR1B = 0;
}

// enable/disable flipping of motor 1
void AStar32U4Motors::flipM1(bool flip)
{
    _flipM1 = flip;
}

// enable/disable flipping of motor 2
void AStar32U4Motors::flipM2(bool flip)
{
    _flipM2 = flip;
}

// set speed for motor 1; speed is a number between -400 and 400
void AStar32U4Motors::setM1Speed(int16_t speed)
{
    init();

    bool reverse = 0;

    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity.
        reverse = 1;     // Preserve the direction.
    }
    if (speed > 400)     // Max PWM duty cycle.
    {
        speed = 400;
    }

    OCR1A = speed;

    FastGPIO::Pin<DIR_M1>::setOutput(reverse ^ _flipM1);
}

// set speed for motor 2; speed is a number between -400 and 400
void AStar32U4Motors::setM2Speed(int16_t speed)
{
    init();

    bool reverse = 0;

    if (speed < 0)
    {
        speed = -speed; // Make speed a positive quantity.
        reverse = 1;    // Preserve the direction.
    }
    if (speed > 400)    // Max PWM duty cycle.
    {
        speed = 400;
    }

    OCR1B = speed;

    FastGPIO::Pin<DIR_M2>::setOutput(reverse ^ _flipM2);
}

// set speed for both motors
void AStar32U4Motors::setSpeeds(int16_t m1Speed, int16_t m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}
