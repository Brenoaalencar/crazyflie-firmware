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
  float phi_g, phi_g_ant, p_g;

private:
  // IMU sensor object
  BMI088 imu;
};

#endif