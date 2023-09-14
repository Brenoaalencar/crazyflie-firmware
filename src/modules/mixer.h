#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

//Classe do Mixer
class Mixer{
    public:
        //Construtor de classe
        Mixer();
        //Atuar motor com arrasto total desejado (N) e torques (N.m)
        void actuate (float f_t, float tau_phi, float tau_theta, float tau_psi);
    private:
        //Saída dos motores PWM
        PwmOut motor_1, motor_2, motor_3, motor_4;
        //Velocidades Angulares (rad/s)
        float omega_1,omega_2,omega_3,omega_4;
        //Converte força total de arrasto (N) e torques (N.m) para velocidade angular
        void mixer (float f_t, float tau_phi, float tau_theta, float tau_psi);
        // Converts desired angular velocity ( rad/s) to PWM signal (%)
        float control_motor ( float omega );

};
    //Atuar os motores
#endif