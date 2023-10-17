# include " attitude_estimator.h"

 // Class constructor
 AttitudeEstimator :: AttitudeEstimator () : imu (IMU_SDA,IMU_SCL)
 {
 //Inicializando em 0 as variáveis
 phi=0;
 theta=0;
 psi=0;

 p=0;
 q=0;
 r=0;
 }

 // Initialize class
 void AttitudeEstimator :: init ()
 {
 imu.init();
 }

 // Estimate Euler angles (rad ) and angular velocities ( rad /s)
 void AttitudeEstimator :: estimate ()
 {
 //(...)
 }
