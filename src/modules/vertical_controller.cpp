#include "vertical_controller.h"

// Class constructor
VerticalController ::VerticalController() {
  f_t=0;
}

// Control thrust force (N) given vertical position (m) and velocity (m/s)
void VerticalController ::control(float z_r, float z, float w) {
  f_t=m*(g+control_siso(z_r,z,w,kp_z,kd_z));
}

// Control aceleration given reference position (m) and current position (m)
// andvelocity (m/s) with given controller gains
float VerticalController ::control_siso(float pos_r, float pos, float vel,
                                        float kp, float kd) {
  float ac = kp*(pos_r-pos)+kd*(0-vel);
  return ac;
}
