#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_773137018329152076);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_447307053981164472);
void car_H_mod_fun(double *state, double *out_8346572503660215627);
void car_f_fun(double *state, double dt, double *out_2968127823182416653);
void car_F_fun(double *state, double dt, double *out_5862947193001861040);
void car_h_25(double *state, double *unused, double *out_1081912774028385498);
void car_H_25(double *state, double *unused, double *out_814213482369784826);
void car_h_24(double *state, double *unused, double *out_7656509362565968560);
void car_H_24(double *state, double *unused, double *out_7389785288961302927);
void car_h_30(double *state, double *unused, double *out_806718711743879609);
void car_H_30(double *state, double *unused, double *out_7730903823861401581);
void car_h_26(double *state, double *unused, double *out_2286646816318226569);
void car_H_26(double *state, double *unused, double *out_2927289836504271398);
void car_h_27(double *state, double *unused, double *out_1625996774220301670);
void car_H_27(double *state, double *unused, double *out_1489888776573880155);
void car_h_29(double *state, double *unused, double *out_8213824700696596833);
void car_H_29(double *state, double *unused, double *out_1195105879540936940);
void car_h_28(double *state, double *unused, double *out_2229312658896779187);
void car_H_28(double *state, double *unused, double *out_3158736151106263191);
void car_h_31(double *state, double *unused, double *out_7237359969869045627);
void car_H_31(double *state, double *unused, double *out_844859444246745254);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}