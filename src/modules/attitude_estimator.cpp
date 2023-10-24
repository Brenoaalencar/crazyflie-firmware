#include "attitude_estimator.h"

// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  // Inicializando em 0 as variáveis
  phi = 0;
  phi_filtro = 0;
  phi_filtro_ant = 0;

  
  phi_g_ant = 0.0;
  phi_g = 0.0;
  p_g = 0.0;

  //Erro sistemático
  p_bias=0;
  q_bias=0;
  r_bias=0;

  theta = 0;


  psi = 0;


  p = 0;
  q = 0;
  r = 0;
}

// Initialize class
void AttitudeEstimator ::init() { 
    imu.init();
    for (int i=0;i<500;i++){
        imu.read();
        p_bias=p_bias+imu.gx;
        q_bias=q_bias+imu.gy;
        r_bias=r_bias+imu.gz;
        wait(dt);
    }
    p_bias=(p_bias)/500;
    q_bias=(q_bias)/500;
    r_bias=(r_bias)/500;
     }

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();
  //estima atitude com acelerometro
  float phi_a = atan2(-imu.ay, -imu.az);
  //phi = phi_a;
  //phi_filtro = (1-alfa)*phi_filtro_ant + alfa*phi;
  //phi_filtro_ant = phi_filtro;

  //estima atitude com giroscopio
  p_g = imu.gx-p_bias;
  phi_g = phi + p_g*dt;
  //phi_g_ant = phi_g;
  //phi_filtro = (1-alfa)*phi_g;
  phi=(1-alfa)*phi_g+alfa*phi_a;


  float theta_a = atan2(imu.ax,(-((imu.az>0)-(imu.az<0))*sqrt(imu.az*imu.az+imu.ay*imu.ay)));
  theta = 

  float psi_a = 0.0;
  psi = psi_a;
}
