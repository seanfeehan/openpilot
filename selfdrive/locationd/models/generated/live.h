#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_3601087727253132969);
void live_err_fun(double *nom_x, double *delta_x, double *out_1153752211634308443);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6655342838562251109);
void live_H_mod_fun(double *state, double *out_6387601908760479860);
void live_f_fun(double *state, double dt, double *out_2644681283468648566);
void live_F_fun(double *state, double dt, double *out_7072203675530199062);
void live_h_4(double *state, double *unused, double *out_563680518451919752);
void live_H_4(double *state, double *unused, double *out_3231227212246200753);
void live_h_9(double *state, double *unused, double *out_3347631837389681515);
void live_H_9(double *state, double *unused, double *out_2990037565616610108);
void live_h_10(double *state, double *unused, double *out_4158589424796333618);
void live_H_10(double *state, double *unused, double *out_2024137388413149700);
void live_h_12(double *state, double *unused, double *out_3670144666999023199);
void live_H_12(double *state, double *unused, double *out_1788229195785761042);
void live_h_35(double *state, double *unused, double *out_2017282508012269633);
void live_H_35(double *state, double *unused, double *out_135434845126406623);
void live_h_32(double *state, double *unused, double *out_6789382851101083323);
void live_H_32(double *state, double *unused, double *out_6779429658567709733);
void live_h_13(double *state, double *unused, double *out_2360763578780184583);
void live_H_13(double *state, double *unused, double *out_4053935256495661757);
void live_h_14(double *state, double *unused, double *out_3347631837389681515);
void live_H_14(double *state, double *unused, double *out_2990037565616610108);
void live_h_33(double *state, double *unused, double *out_2351356237073976575);
void live_H_33(double *state, double *unused, double *out_3285991849765264227);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}