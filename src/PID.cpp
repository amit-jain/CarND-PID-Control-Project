#include "PID.h"
#include <iostream>

using namespace std;


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double min, double max) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->min = min;
  this->max = max;
}

double PID::Correction(double cte) {
  double diff_cte = cte - prev_cte;
  prev_cte = cte;
  sum_cte += cte;
  double correction = -Kp * cte - Kd * diff_cte - Ki * sum_cte;
  if (correction < min) {
    correction = min;
  } else if (correction > max) {
    correction = max;
  }
   return correction;
}

