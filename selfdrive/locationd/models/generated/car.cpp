#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_773137018329152076) {
   out_773137018329152076[0] = delta_x[0] + nom_x[0];
   out_773137018329152076[1] = delta_x[1] + nom_x[1];
   out_773137018329152076[2] = delta_x[2] + nom_x[2];
   out_773137018329152076[3] = delta_x[3] + nom_x[3];
   out_773137018329152076[4] = delta_x[4] + nom_x[4];
   out_773137018329152076[5] = delta_x[5] + nom_x[5];
   out_773137018329152076[6] = delta_x[6] + nom_x[6];
   out_773137018329152076[7] = delta_x[7] + nom_x[7];
   out_773137018329152076[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_447307053981164472) {
   out_447307053981164472[0] = -nom_x[0] + true_x[0];
   out_447307053981164472[1] = -nom_x[1] + true_x[1];
   out_447307053981164472[2] = -nom_x[2] + true_x[2];
   out_447307053981164472[3] = -nom_x[3] + true_x[3];
   out_447307053981164472[4] = -nom_x[4] + true_x[4];
   out_447307053981164472[5] = -nom_x[5] + true_x[5];
   out_447307053981164472[6] = -nom_x[6] + true_x[6];
   out_447307053981164472[7] = -nom_x[7] + true_x[7];
   out_447307053981164472[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8346572503660215627) {
   out_8346572503660215627[0] = 1.0;
   out_8346572503660215627[1] = 0;
   out_8346572503660215627[2] = 0;
   out_8346572503660215627[3] = 0;
   out_8346572503660215627[4] = 0;
   out_8346572503660215627[5] = 0;
   out_8346572503660215627[6] = 0;
   out_8346572503660215627[7] = 0;
   out_8346572503660215627[8] = 0;
   out_8346572503660215627[9] = 0;
   out_8346572503660215627[10] = 1.0;
   out_8346572503660215627[11] = 0;
   out_8346572503660215627[12] = 0;
   out_8346572503660215627[13] = 0;
   out_8346572503660215627[14] = 0;
   out_8346572503660215627[15] = 0;
   out_8346572503660215627[16] = 0;
   out_8346572503660215627[17] = 0;
   out_8346572503660215627[18] = 0;
   out_8346572503660215627[19] = 0;
   out_8346572503660215627[20] = 1.0;
   out_8346572503660215627[21] = 0;
   out_8346572503660215627[22] = 0;
   out_8346572503660215627[23] = 0;
   out_8346572503660215627[24] = 0;
   out_8346572503660215627[25] = 0;
   out_8346572503660215627[26] = 0;
   out_8346572503660215627[27] = 0;
   out_8346572503660215627[28] = 0;
   out_8346572503660215627[29] = 0;
   out_8346572503660215627[30] = 1.0;
   out_8346572503660215627[31] = 0;
   out_8346572503660215627[32] = 0;
   out_8346572503660215627[33] = 0;
   out_8346572503660215627[34] = 0;
   out_8346572503660215627[35] = 0;
   out_8346572503660215627[36] = 0;
   out_8346572503660215627[37] = 0;
   out_8346572503660215627[38] = 0;
   out_8346572503660215627[39] = 0;
   out_8346572503660215627[40] = 1.0;
   out_8346572503660215627[41] = 0;
   out_8346572503660215627[42] = 0;
   out_8346572503660215627[43] = 0;
   out_8346572503660215627[44] = 0;
   out_8346572503660215627[45] = 0;
   out_8346572503660215627[46] = 0;
   out_8346572503660215627[47] = 0;
   out_8346572503660215627[48] = 0;
   out_8346572503660215627[49] = 0;
   out_8346572503660215627[50] = 1.0;
   out_8346572503660215627[51] = 0;
   out_8346572503660215627[52] = 0;
   out_8346572503660215627[53] = 0;
   out_8346572503660215627[54] = 0;
   out_8346572503660215627[55] = 0;
   out_8346572503660215627[56] = 0;
   out_8346572503660215627[57] = 0;
   out_8346572503660215627[58] = 0;
   out_8346572503660215627[59] = 0;
   out_8346572503660215627[60] = 1.0;
   out_8346572503660215627[61] = 0;
   out_8346572503660215627[62] = 0;
   out_8346572503660215627[63] = 0;
   out_8346572503660215627[64] = 0;
   out_8346572503660215627[65] = 0;
   out_8346572503660215627[66] = 0;
   out_8346572503660215627[67] = 0;
   out_8346572503660215627[68] = 0;
   out_8346572503660215627[69] = 0;
   out_8346572503660215627[70] = 1.0;
   out_8346572503660215627[71] = 0;
   out_8346572503660215627[72] = 0;
   out_8346572503660215627[73] = 0;
   out_8346572503660215627[74] = 0;
   out_8346572503660215627[75] = 0;
   out_8346572503660215627[76] = 0;
   out_8346572503660215627[77] = 0;
   out_8346572503660215627[78] = 0;
   out_8346572503660215627[79] = 0;
   out_8346572503660215627[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2968127823182416653) {
   out_2968127823182416653[0] = state[0];
   out_2968127823182416653[1] = state[1];
   out_2968127823182416653[2] = state[2];
   out_2968127823182416653[3] = state[3];
   out_2968127823182416653[4] = state[4];
   out_2968127823182416653[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2968127823182416653[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2968127823182416653[7] = state[7];
   out_2968127823182416653[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5862947193001861040) {
   out_5862947193001861040[0] = 1;
   out_5862947193001861040[1] = 0;
   out_5862947193001861040[2] = 0;
   out_5862947193001861040[3] = 0;
   out_5862947193001861040[4] = 0;
   out_5862947193001861040[5] = 0;
   out_5862947193001861040[6] = 0;
   out_5862947193001861040[7] = 0;
   out_5862947193001861040[8] = 0;
   out_5862947193001861040[9] = 0;
   out_5862947193001861040[10] = 1;
   out_5862947193001861040[11] = 0;
   out_5862947193001861040[12] = 0;
   out_5862947193001861040[13] = 0;
   out_5862947193001861040[14] = 0;
   out_5862947193001861040[15] = 0;
   out_5862947193001861040[16] = 0;
   out_5862947193001861040[17] = 0;
   out_5862947193001861040[18] = 0;
   out_5862947193001861040[19] = 0;
   out_5862947193001861040[20] = 1;
   out_5862947193001861040[21] = 0;
   out_5862947193001861040[22] = 0;
   out_5862947193001861040[23] = 0;
   out_5862947193001861040[24] = 0;
   out_5862947193001861040[25] = 0;
   out_5862947193001861040[26] = 0;
   out_5862947193001861040[27] = 0;
   out_5862947193001861040[28] = 0;
   out_5862947193001861040[29] = 0;
   out_5862947193001861040[30] = 1;
   out_5862947193001861040[31] = 0;
   out_5862947193001861040[32] = 0;
   out_5862947193001861040[33] = 0;
   out_5862947193001861040[34] = 0;
   out_5862947193001861040[35] = 0;
   out_5862947193001861040[36] = 0;
   out_5862947193001861040[37] = 0;
   out_5862947193001861040[38] = 0;
   out_5862947193001861040[39] = 0;
   out_5862947193001861040[40] = 1;
   out_5862947193001861040[41] = 0;
   out_5862947193001861040[42] = 0;
   out_5862947193001861040[43] = 0;
   out_5862947193001861040[44] = 0;
   out_5862947193001861040[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5862947193001861040[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5862947193001861040[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5862947193001861040[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5862947193001861040[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5862947193001861040[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5862947193001861040[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5862947193001861040[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5862947193001861040[53] = -9.8000000000000007*dt;
   out_5862947193001861040[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5862947193001861040[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5862947193001861040[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5862947193001861040[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5862947193001861040[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5862947193001861040[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5862947193001861040[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5862947193001861040[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5862947193001861040[62] = 0;
   out_5862947193001861040[63] = 0;
   out_5862947193001861040[64] = 0;
   out_5862947193001861040[65] = 0;
   out_5862947193001861040[66] = 0;
   out_5862947193001861040[67] = 0;
   out_5862947193001861040[68] = 0;
   out_5862947193001861040[69] = 0;
   out_5862947193001861040[70] = 1;
   out_5862947193001861040[71] = 0;
   out_5862947193001861040[72] = 0;
   out_5862947193001861040[73] = 0;
   out_5862947193001861040[74] = 0;
   out_5862947193001861040[75] = 0;
   out_5862947193001861040[76] = 0;
   out_5862947193001861040[77] = 0;
   out_5862947193001861040[78] = 0;
   out_5862947193001861040[79] = 0;
   out_5862947193001861040[80] = 1;
}
void h_25(double *state, double *unused, double *out_1081912774028385498) {
   out_1081912774028385498[0] = state[6];
}
void H_25(double *state, double *unused, double *out_814213482369784826) {
   out_814213482369784826[0] = 0;
   out_814213482369784826[1] = 0;
   out_814213482369784826[2] = 0;
   out_814213482369784826[3] = 0;
   out_814213482369784826[4] = 0;
   out_814213482369784826[5] = 0;
   out_814213482369784826[6] = 1;
   out_814213482369784826[7] = 0;
   out_814213482369784826[8] = 0;
}
void h_24(double *state, double *unused, double *out_7656509362565968560) {
   out_7656509362565968560[0] = state[4];
   out_7656509362565968560[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7389785288961302927) {
   out_7389785288961302927[0] = 0;
   out_7389785288961302927[1] = 0;
   out_7389785288961302927[2] = 0;
   out_7389785288961302927[3] = 0;
   out_7389785288961302927[4] = 1;
   out_7389785288961302927[5] = 0;
   out_7389785288961302927[6] = 0;
   out_7389785288961302927[7] = 0;
   out_7389785288961302927[8] = 0;
   out_7389785288961302927[9] = 0;
   out_7389785288961302927[10] = 0;
   out_7389785288961302927[11] = 0;
   out_7389785288961302927[12] = 0;
   out_7389785288961302927[13] = 0;
   out_7389785288961302927[14] = 1;
   out_7389785288961302927[15] = 0;
   out_7389785288961302927[16] = 0;
   out_7389785288961302927[17] = 0;
}
void h_30(double *state, double *unused, double *out_806718711743879609) {
   out_806718711743879609[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7730903823861401581) {
   out_7730903823861401581[0] = 0;
   out_7730903823861401581[1] = 0;
   out_7730903823861401581[2] = 0;
   out_7730903823861401581[3] = 0;
   out_7730903823861401581[4] = 1;
   out_7730903823861401581[5] = 0;
   out_7730903823861401581[6] = 0;
   out_7730903823861401581[7] = 0;
   out_7730903823861401581[8] = 0;
}
void h_26(double *state, double *unused, double *out_2286646816318226569) {
   out_2286646816318226569[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2927289836504271398) {
   out_2927289836504271398[0] = 0;
   out_2927289836504271398[1] = 0;
   out_2927289836504271398[2] = 0;
   out_2927289836504271398[3] = 0;
   out_2927289836504271398[4] = 0;
   out_2927289836504271398[5] = 0;
   out_2927289836504271398[6] = 0;
   out_2927289836504271398[7] = 1;
   out_2927289836504271398[8] = 0;
}
void h_27(double *state, double *unused, double *out_1625996774220301670) {
   out_1625996774220301670[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1489888776573880155) {
   out_1489888776573880155[0] = 0;
   out_1489888776573880155[1] = 0;
   out_1489888776573880155[2] = 0;
   out_1489888776573880155[3] = 1;
   out_1489888776573880155[4] = 0;
   out_1489888776573880155[5] = 0;
   out_1489888776573880155[6] = 0;
   out_1489888776573880155[7] = 0;
   out_1489888776573880155[8] = 0;
}
void h_29(double *state, double *unused, double *out_8213824700696596833) {
   out_8213824700696596833[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1195105879540936940) {
   out_1195105879540936940[0] = 0;
   out_1195105879540936940[1] = 1;
   out_1195105879540936940[2] = 0;
   out_1195105879540936940[3] = 0;
   out_1195105879540936940[4] = 0;
   out_1195105879540936940[5] = 0;
   out_1195105879540936940[6] = 0;
   out_1195105879540936940[7] = 0;
   out_1195105879540936940[8] = 0;
}
void h_28(double *state, double *unused, double *out_2229312658896779187) {
   out_2229312658896779187[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3158736151106263191) {
   out_3158736151106263191[0] = 1;
   out_3158736151106263191[1] = 0;
   out_3158736151106263191[2] = 0;
   out_3158736151106263191[3] = 0;
   out_3158736151106263191[4] = 0;
   out_3158736151106263191[5] = 0;
   out_3158736151106263191[6] = 0;
   out_3158736151106263191[7] = 0;
   out_3158736151106263191[8] = 0;
}
void h_31(double *state, double *unused, double *out_7237359969869045627) {
   out_7237359969869045627[0] = state[8];
}
void H_31(double *state, double *unused, double *out_844859444246745254) {
   out_844859444246745254[0] = 0;
   out_844859444246745254[1] = 0;
   out_844859444246745254[2] = 0;
   out_844859444246745254[3] = 0;
   out_844859444246745254[4] = 0;
   out_844859444246745254[5] = 0;
   out_844859444246745254[6] = 0;
   out_844859444246745254[7] = 0;
   out_844859444246745254[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_773137018329152076) {
  err_fun(nom_x, delta_x, out_773137018329152076);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_447307053981164472) {
  inv_err_fun(nom_x, true_x, out_447307053981164472);
}
void car_H_mod_fun(double *state, double *out_8346572503660215627) {
  H_mod_fun(state, out_8346572503660215627);
}
void car_f_fun(double *state, double dt, double *out_2968127823182416653) {
  f_fun(state,  dt, out_2968127823182416653);
}
void car_F_fun(double *state, double dt, double *out_5862947193001861040) {
  F_fun(state,  dt, out_5862947193001861040);
}
void car_h_25(double *state, double *unused, double *out_1081912774028385498) {
  h_25(state, unused, out_1081912774028385498);
}
void car_H_25(double *state, double *unused, double *out_814213482369784826) {
  H_25(state, unused, out_814213482369784826);
}
void car_h_24(double *state, double *unused, double *out_7656509362565968560) {
  h_24(state, unused, out_7656509362565968560);
}
void car_H_24(double *state, double *unused, double *out_7389785288961302927) {
  H_24(state, unused, out_7389785288961302927);
}
void car_h_30(double *state, double *unused, double *out_806718711743879609) {
  h_30(state, unused, out_806718711743879609);
}
void car_H_30(double *state, double *unused, double *out_7730903823861401581) {
  H_30(state, unused, out_7730903823861401581);
}
void car_h_26(double *state, double *unused, double *out_2286646816318226569) {
  h_26(state, unused, out_2286646816318226569);
}
void car_H_26(double *state, double *unused, double *out_2927289836504271398) {
  H_26(state, unused, out_2927289836504271398);
}
void car_h_27(double *state, double *unused, double *out_1625996774220301670) {
  h_27(state, unused, out_1625996774220301670);
}
void car_H_27(double *state, double *unused, double *out_1489888776573880155) {
  H_27(state, unused, out_1489888776573880155);
}
void car_h_29(double *state, double *unused, double *out_8213824700696596833) {
  h_29(state, unused, out_8213824700696596833);
}
void car_H_29(double *state, double *unused, double *out_1195105879540936940) {
  H_29(state, unused, out_1195105879540936940);
}
void car_h_28(double *state, double *unused, double *out_2229312658896779187) {
  h_28(state, unused, out_2229312658896779187);
}
void car_H_28(double *state, double *unused, double *out_3158736151106263191) {
  H_28(state, unused, out_3158736151106263191);
}
void car_h_31(double *state, double *unused, double *out_7237359969869045627) {
  h_31(state, unused, out_7237359969869045627);
}
void car_H_31(double *state, double *unused, double *out_844859444246745254) {
  H_31(state, unused, out_844859444246745254);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
