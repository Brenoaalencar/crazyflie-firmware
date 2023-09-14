#include "mbed.h"
#include "crazyflie.h"

// Define motor as PWM output object
//Grupo Breno, Lucca e Richetti
PwmOut motor4(MOTOR4) ;
PwmOut motor3(MOTOR3) ;
PwmOut motor2(MOTOR2) ;
PwmOut motor1(MOTOR1) ;

//Definindo as velocidades angulares (rad/s)
float omega_1;
float omega_2;
float omega_3;
float omega_4;

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor ( float omega )
{
   float PWM = 0.0000001*1.341*omega*omega + 0.0000000001*2.956*omega;
   return PWM;
 }

//Converte força total de arrasto (N) e torques (N.m) para velocidade angular
void mixer (float f_t, float tau_phi, float tau_theta, float tau_psi)
{   
      omega_1= sqrt(f_t/(4*kl) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l) - tau_psi/(4*kd));
      omega_2= sqrt(f_t/(4*kl) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l) + tau_psi/(4*kd));
      omega_3= sqrt(f_t/(4*kl) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l) - tau_psi/(4*kd));
      omega_4= sqrt(f_t/(4*kl) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l) + tau_psi/(4*kd));
}

//Atuar motor com arrasto total desejado (N) e torques (N.m)
void actuate (float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t,tau_phi,tau_theta,tau_psi);
    motor1 = control_motor(omega_1);
    motor2 = control_motor(omega_2);
    motor3 = control_motor(omega_3);
    motor4 = control_motor(omega_4);

}


// Main program
int main ()
{
    wait(3);
    // Set PWM frequency to 500 Hz
    motor1.period (1.0/500.0) ;
    motor2.period (1.0/500.0) ;
    motor3.period (1.0/500.0) ;
    motor4.period (1.0/500.0) ;
    // Turn on motor with 1.000 rad /s for 0.5s
    actuate(1*m*g,0,0,0);
    wait(3);
    //actuate(0.7*m*g,0,0.0015,0);
    //wait(1);
    //actuate(0.7*m*g,0,0,0);
    //Atuar motor com 50% mg com arrasto total(N) e torque zero.
    wait(2);
    // Turn off motor
    //actuate(0,0,0,0);
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    while(true){

    }
}

