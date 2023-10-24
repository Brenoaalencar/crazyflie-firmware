#include "mbed.h"
#include "crazyflie.h"

#define c_ 279.6
#define C_ 559.15
#define D_ 627.79
#define d_ 313.9
#define e 332.6
#define f 352.4
#define f_ 373.3
#define F 352.4
#define F_ 746.59
#define g_ 419

// Define motor as PWM output object
//Grupo Breno, Lucca e Richetti
PwmOut motor4(MOTOR4) ;
PwmOut motor3(MOTOR3) ;
PwmOut motor2(MOTOR2) ;
PwmOut motor1(MOTOR1) ;


float frequency[]= {c_, C_, g_, f_, F_, g_, F, g_,c_, C_, g_, f_, F_, g_, F, g_,
                    d_, C_, g_, f_, F_, g_, F, g_,d_, C_, g_, f_, F_, g_, F, g_,
                    f_, C_, g_, f_, F_, g_, F, g_, f_, C_, g_, f_, F_, g_, F, g_,
                    D_, g_, C_, g_, D_, g_, F, g_,D_, g_, C_, g_, D_, g_, F, g_,
                    F_, g_, F, g_, D_, g_, C_, C_,
                    g_,g_,g_, g_,  f_,f,
                    f_, g_, e, c_, f_,
                   };

float beat[]= {0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,
               0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8
               ,0.8,0.8,0.8,2.4,0.8,0.8,
               1.6,0.8,2.4,0.8
              }; //beat array


// Main program
int main ()
{


    for (int i=0; i<=80; i=i+4) {
        motor1.period(1.0/(2.0*frequency[i])); // set PWM period
        motor1 = 0.1;
        wait(0.4*beat[i]); // hold for beat period
        motor1 = 0;
        motor2.period(1.0/(2.0*frequency[i+1])); // set PWM period
        motor2 = 0.1;
        wait(0.4*beat[i+1]); // hold for beat period
        motor2 = 0;
        motor3.period(1.0/(2.0*frequency[i+2])); // set PWM period
        motor3 = 0.1;
        wait(0.4*beat[i+2]); // hold for beat period
        motor3 = 0;
        motor4.period(1.0/(2.0*frequency[i+3])); // set PWM period
        motor4 = 0.1;
        wait(0.4*beat[i+3]); // hold for beat period
        motor4 = 0;
    }
   
    // Turn off motor
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    while(true){

    }
}

