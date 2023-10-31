#include "mixer.h"

//Classe construtora
Mixer::Mixer():motor_1(MOTOR1),motor_2(MOTOR2),motor_3(MOTOR3),motor_4(MOTOR4)
{
    motor_1.period (1.0/500.0) ;
    motor_2.period (1.0/500.0) ;
    motor_3.period (1.0/500.0) ;
    motor_4.period (1.0/500.0) ;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
    
}

//Atuar motor com arrasto total desejado (N) e torques (N.m)
void Mixer::actuate (float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t,tau_phi,tau_theta,tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);

}

//Converte força total de arrasto (N) e torques (N.m) para velocidade angular
void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{  float conta_1=f_t/(4*kl) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l) - tau_psi/(4*kd);
   if(conta_1<0){omega_1=0;}else{omega_1= sqrt(conta_1);}
   float conta_2=f_t/(4*kl) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l) + tau_psi/(4*kd);
   if(conta_2<0){omega_2=0;}else{omega_2= sqrt(conta_2);}
   float conta_3=f_t/(4*kl) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l) - tau_psi/(4*kd);
   if(conta_3<0){omega_3=0;}else{omega_3= sqrt(conta_3);}
   float conta_4=f_t/(4*kl) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l) + tau_psi/(4*kd);
    if(conta_4<0){omega_4=0;}else{omega_4= sqrt(conta_4);}
    //omega_2= sqrt();
    //omega_3= sqrt();
    //omega_4= sqrt();

    //Correção da Giu
    //if(f_t/(4*kl) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l) - tau_psi/(4*kd)<0){omega_1=0;}
    //if(f_t/(4*kl) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l) + tau_psi/(4*kd)<0){omega_2=0;}
    //if(f_t/(4*kl) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l) - tau_psi/(4*kd)<0){omega_3=0;}
    //if(f_t/(4*kl) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l) + tau_psi/(4*kd)<0){omega_4=0;}
}

// Converts desired angular velocity ( rad/s) to PWM signal (%)
float Mixer::control_motor(float omega)
{
    float PWM = 0.0000001*1.341*omega*omega + 0.0000000001*2.956*omega;
    return PWM;
}