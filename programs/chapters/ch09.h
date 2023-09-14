#include "mbed.h"
#include "crazyflie.h"

//Grupo Breno, Lucca e Richetti
//Declare Mixer
Mixer mixer;

// Main program

int main ()
{
    wait(2);
    //Mixer com 50% da força total e 0 de torque
    mixer.actuate(0.7*m*g,0,0,0);
    wait(2);
    //Desliga os motores
    mixer.actuate(0,0,0,0);
    //Fim de programa
    while(true){

    }
}

