#include "attitude_controller.h"

// Class constructor
AttitudeController ::AttitudeController() {

}
// Control torques (N.m) given reference angles ( rad) and current angles ( rad
// ) andangular velocities ( rad /s)
void AttitudeController ::control(float phi_r, float theta_r, float psi_r,
                                  float phi, float theta, float psi, float p,
                                  float q, float r) {


                                  }
                                  
// Control torque (N.m) given reference angle ( rad ) and current angle ( rad )
// and angular velocity ( rad /s) with given controller gains
float AttitudeController ::control_siso(float angle_r, float angle, float rate,
                                        float kp, float kd) {


                                        }
