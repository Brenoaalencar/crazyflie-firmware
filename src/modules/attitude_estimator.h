#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "crazyflie.h"
#include "mbed.h"

// Attitude estimator class
class AttitudeEstimator {
public:
  // Class constructor
  AttitudeEstimator();
  // Initialize class
  void init();
  // Estimate Euler angles ( rad ) and angular velocities ( rad /s)
  void estimate();
  // Euler angles (rad)
  float phi, theta, psi;
  // Angular velocities ( rad /s)
  float p, q, r;
  //valores filtrados
  float phi_filtro, phi_filtro_ant;
  //valores para atitude pelo giroscópio
  float phi_g, phi_g_ant, p_g,p_bias,q_bias,r_bias;
  //Seção n-linear
  float phi_est_ant,theta_est_ant,psi_est_ant,phi_est,theta_est,psi_est,theta_g,psi_g;

private:
  // IMU sensor object
  BMI088 imu;
};

#endif