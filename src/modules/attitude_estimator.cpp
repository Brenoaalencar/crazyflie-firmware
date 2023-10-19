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
  

  theta = 0;


  psi = 0;


  p = 0;
  q = 0;
  r = 0;
}

// Initialize class
void AttitudeEstimator ::init() { imu.init(); }

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();
  //estima atitude com acelerometro
  //float phi_a = atan2(-imu.ay, -imu.az);
  //phi = phi_a;
  //phi_filtro = (1-alfa)*phi_filtro_ant + alfa*phi;
  //phi_filtro_ant = phi_filtro;

  //estima atitude com giroscopio
  p_g = imu.gx;
  phi_g = phi_g_ant + p_g*dt;
  phi_g_ant = phi_g;

  float theta_a = 0.0;
  theta = theta_a;

  float psi_a = 0.0;
  psi = psi_a;
}
