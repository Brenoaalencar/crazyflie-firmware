#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2
const float dt = 0.002;         //ms
const float dt_range = 0.050; 

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

//NOVOS PARAMETROS
const float a2 = 0.0000001*1.341;
const float a1 = 0.0000000001*2.956;
const float kl = 0.00000001*1.768;
const float kd = 0.0000000001*1.553;
const float wc = 1.0;
const float alfa = (wc*dt)/(1+wc*dt);

//Controlador de atitude
const float os = 0.005;
const float ts_phi = 0.3;
//const float zeta_phi = (abs(log(os))/(sqrt((log(os))*(log(os)) + pi*pi )));
const float zeta_phi = abs(log(os))/sqrt(pow(log(os),2) + pow(pi,2));
const float wn_phi = 4/(zeta_phi*ts_phi);
//const float kp_phi = wn_phi*wn_phi;
const float kp_phi = pow(wn_phi,2);
const float kd_phi = 2*zeta_phi*wn_phi;

const float kp_theta = kp_phi;
const float kd_theta = kd_phi;

const float ts_psi = 0.6;
//const float zeta_psi = (abs(log(os))/(sqrt((log(os))*(log(os)) + pi*pi )));
const float zeta_psi = zeta_phi;
const float wn_psi = 4/(zeta_psi*ts_psi);
//const float kp_psi = wn_psi*wn_psi;
const float kp_psi = pow(wn_psi,2);
const float kd_psi = 2*zeta_psi*wn_psi;

//Controlador vertical
const float wc_cv=10;
const float zeta_cv=sqrt(2)/2;
const float l1 = wc_cv*wc_cv;
const float l2= 2*zeta_cv*wc_cv;
const float kp_z=5.8567;
const float kd_z=3.4225;

//Controlador horizontal
const float gamma = 42.0*pi/180.0;
const float W = 420.0;
const float sigma = 2.0*tan(gamma/2.0)/(W*dt);
const float wc_ch=50.0;
const float l_ch = wc_ch;


const float ts_h = 2;
//const float zeta_phi = (abs(log(os))/(sqrt((log(os))*(log(os)) + pi*pi )));
const float zeta_h = abs(log(os))/sqrt(pow(log(os),2) + pow(pi,2));
const float wn_h = 4/(zeta_phi*ts_phi);
//const float kp_phi = wn_phi*wn_phi;
const float kp_h = pow(wn_phi,2);
const float kd_h = 2*zeta_phi*wn_phi;

#endif