#include "mbed.h"
#include "crazyflie.h"

// Define motor as PWM output object
//Grupo Breno, Lucca e Richetti
PwmOut motor4(MOTOR4) ;
PwmOut motor3(MOTOR3) ;
PwmOut motor2(MOTOR2) ;
PwmOut motor1(MOTOR1) ;

float vel = 2000;

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor ( float omega )
{
   float PWM = 0.0000001*1.341*omega*omega + 0.0000000001*2.956*omega;
   return PWM;
 }

// Main program
int main ()
{
    wait(2);
    // Set PWM frequency to 500 Hz
    motor1.period (1.0/500.0) ;
    motor2.period (1.0/500.0) ;
    motor3.period (1.0/500.0) ;
    motor4.period (1.0/500.0) ;
    // Turn on motor with 1.000 rad /s for 0.5s
    motor1.write(control_motor (vel)) ;
    motor2.write(control_motor (vel)) ;
    motor3.write(control_motor (vel)) ;
    motor4.write(control_motor (vel)) ;
    wait(10);
    // Turn off motor
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    while(true){

    }
}

