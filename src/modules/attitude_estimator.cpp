#include "attitude_estimator.h"

// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  // Inicializando em 0 as variáveis
  phi = 0;
  phi_filtro = 0;
  phi_filtro_ant = 0;

  phi_g_ant = 0.0;
  phi_g = 0.0;
  theta_g=0.0;
  psi_g=0.0;
  p_g = 0.0;

  // Erro sistemático
  p_bias = 0;
  q_bias = 0;
  r_bias = 0;

  // Seção não-linear
  phi_est_ant = 0;
  theta_est_ant=0;
  psi_est_ant=0;

  phi_est=0;
  theta_est=0;
  psi_est=0;

  theta = 0;

  psi = 0;

  p = 0;
  q = 0;
  r = 0;
}

// Initialize class
void AttitudeEstimator ::init() {
  imu.init();
  for (int i = 0; i < 500; i++) {
    imu.read();
    p_bias = p_bias + imu.gx;
    q_bias = q_bias + imu.gy;
    r_bias = r_bias + imu.gz;
    wait(dt);
  }
  p_bias = (p_bias) / 500;
  q_bias = (q_bias) / 500;
  r_bias = (r_bias) / 500;
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
  imu.read();
  // estima atitude com acelerometro
  float phi_a = atan2(-imu.ay, -imu.az);
  // phi = phi_a;
  // phi_filtro = (1-alfa)*phi_filtro_ant + alfa*phi;
  // phi_filtro_ant = phi_filtro;

  // estima atitude com giroscopio
  p = imu.gx - p_bias;
  q = imu.gy - q_bias;
  r = imu.gz; //- r_bias;

  //phi_g = phi + p_g * dt;
  // phi_g_ant = phi_g;
  // phi_filtro = (1-alfa)*phi_g;
  //phi = (1 - alfa) * phi_g + alfa * phi_a;

  float theta_a = atan2(imu.ax, (-((imu.az > 0) - (imu.az < 0))*sqrt(imu.az * imu.az + imu.ay * imu.ay)));
  
  //Seção não linear

  phi_g=phi_est_ant+(p+sin(phi_est_ant)*tan(theta_est_ant)*q+cos(phi_est_ant)*tan(theta_est_ant)*r)*dt;
  theta_g=theta_est_ant+(cos(theta_est_ant)*q-sin(phi_est_ant)*r)*dt;
  psi_g=psi_est_ant+(sin(phi_est_ant)*(1/cos(theta_est_ant))*q+cos(phi_est_ant)*(1/cos(theta_est_ant))*r)*dt;

  phi_est=(1-alfa)*phi_g+alfa*phi_a;
  theta_est=(1-alfa)*theta_g+alfa*theta_a;
  psi_est=(1/(1+1*dt))*psi_g;

  phi_est_ant=phi_est;
  theta_est_ant=theta_est;
  psi_est_ant=psi_est;

}
