#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2
const float dt = 0.002;         //ms

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

const float os = 0.05;
const float ts_phi = 0.3;
//const float zeta_phi = (abs(log(os))/(sqrt((log(os))*(log(os)) + pi*pi )));
const float zeta_phi = (abs(log(os))/(sqrt(pow(log(os),2) + pow(pi,2))));
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

#endif