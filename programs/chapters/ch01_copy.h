#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led1(LED_RED_R,!false);
DigitalOut led2(LED_RED_L,!false);
DigitalOut led3(LED_BLUE_L,!false);
DigitalOut led4(LED_GREEN_R,!false);
DigitalOut led5(LED_GREEN_L,!false);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

int vel = 80;
float p = 1.0;
// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    led3=1;
    wait(5);
    led3=0;
    //motor1.period(0.0125);
    //motor2.period(0.0125);
    //motor3.period(0.0125);
    motor4.period(0.0125);

    
    // Turn on red LEDs indicating motors are armed
    led1=1;
    led2=1;
    //motor1.write(p);
    //motor2.write(p);
    //motor3.write(p);
    motor4.write(p);

    wait(10);

    //motor1.write(0);
    //motor2.write(0);
    //motor3.write(0);
    motor4.write(0);
    // Test all motors with different frequencies (to make different noises)
    /*for(float i = 400; i<=1000;i+=50){
        motor1.write(0.5);
        motor1.period(1/i);
        //motor1=0.2;
        wait(0.1);
        motor1.write(0);
        wait(0.2);
    }
    */
    // Turn off red LEDs indicating motors are disarmed
 
    
    // Blink green LEDs indicating end of program
    

    while(true)
    {   
        
        
        
        
        
        /*motor3.write(0.5);
        motor3.period(1/80);
        motor3.write(0);
        wait(0.2);
        */
    }
}
