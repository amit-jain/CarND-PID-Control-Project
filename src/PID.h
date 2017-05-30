#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  bool is_initialized;
  double sum_cte;
  double prev_cte;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  double min;
  double max;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double min, double max);

  /*
  * Update the PID error variables given cross track error.
  */
  double Correction(double cte);
};

#endif /* PID_H */
