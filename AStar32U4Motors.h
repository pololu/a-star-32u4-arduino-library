// Copyright Pololu Corporation.  For more information, see http://www.pololu.com/

/*! \file AStar32U4Motors.h */

#pragma once

#include <stdint.h>

/*! \brief Controls motor speed and direction on the A-Star 32U4 Robot
 * Controller.
 *
 * By default, positive speed arguments ("forward") correspond to current
 * flowing from motor driver output A to B, while negative speed arguments
 * ("reverse") correspond to current flowing from B to A. Calling flipM1() or
 * flipM2() with an argument of \c true flips the correspondence for that motor
 * (that is, it flips the meaning of "forward" and "reverse").
 *
 * This library uses Timer 1, so it will conflict with any other libraries using
 * that timer. */
class AStar32U4Motors
{
  public:

    /** \brief Flips the direction of motor 1.
     *
     * You can call this function with an argument of \c true if you want to
     * flip the effect that positive and negative speeds have on the direction
     * of motor 1.
     *
     * \param flip If true, then positive motor speeds will correspond to 
     * current flowing from B to A.  If false, then positive motor speeds will
     * correspond to current flowing from A to B. */
    static void flipM1(bool flip);

    /** \brief Flips the direction of motor 2.
     *
     * You can call this function with an argument of \c true if you want to
     * flip the effect that positive and negative speeds have on the direction
     * of motor 2.
     *
     * \param flip If true, then positive motor speeds will correspond to 
     * current flowing from B to A.  If false, then positive motor speeds will
     * correspond to current flowing from A to B. */
    static void flipM2(bool flip);

    /** \brief Sets the speed for motor 1.
     *
     * \param speed A number from -400 to 400 representing the speed and
     * direction of motor 1. Values of -400 or less result in full speed
     * reverse, and values of 400 or more result in full speed forward. */
    static void setM1Speed(int16_t speed);

    /** \brief Sets the speed for motor 2.
     *
     * \param speed A number from -400 to 400 representing the speed and
     * direction of motor 2.  Values of -400 or less result in full speed
     * reverse, and values of 400 or more result in full speed forward. */
    static void setM2Speed(int16_t speed);

    /** \brief Sets the speed for both motors.
     *
     * \param m1Speed A number from -400 to 400 representing the speed and
     * direction of motor 1. Values of -400 or less result in full speed
     * reverse, and values of 400 or more result in full speed forward.
     * \param m2Speed A number from -400 to 400 representing the speed and
     * direction of motor 2. Values of -400 or less result in full speed
     * reverse, and values of 400 or more result in full speed forward. */
    static void setSpeeds(int16_t m2Speed, int16_t m1Speed);

  private:

    static inline void init()
    {
        static bool initialized = false;

        if (!initialized)
        {
            initialized = true;
            init2();
        }
    }

    static void init2();
};
