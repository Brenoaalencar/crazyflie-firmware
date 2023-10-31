#include "attitude_estimator.h"

// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
    // Inicializando em 0 as variáveis
    phi = 0;
    theta = 0;
    psi = 0;
    //
    p = 0;
    q = 0;
    r = 0;
    // Erro sistemático
    p_bias = 0;
    q_bias = 0;
    r_bias = 0;
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

  // estima atitude com giroscopio
  p = imu.gx - p_bias;
  q = imu.gy - q_bias;
  r = imu.gz - r_bias;

  // estima atitude com acelerometro
  float phi_a = atan2(-imu.ay, -imu.az);
  float theta_a = atan2(imu.ax, (-((imu.az > 0) - (imu.az < 0))*sqrt(imu.az * imu.az + imu.ay * imu.ay)));
  
  //Seção não linear
  float phi_g = phi+(p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
  float theta_g = theta+(cos(theta)*q-sin(phi)*r)*dt;
  float psi_g = psi+(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r)*dt;

  phi = (1-alfa)*phi_g+alfa*phi_a;
  theta = (1-alfa)*theta_g+alfa*theta_a;
  psi = psi_g;

}
