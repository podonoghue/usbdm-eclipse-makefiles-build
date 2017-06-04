/**
 * @file    pid.h
 * @brief   PID Controller using CMSIS TimerClass
 *
 *  Created on: 10 Jul 2016
 *      Author: podonoghue
 */

#ifndef PROJECT_HEADERS_PID_H_
#define PROJECT_HEADERS_PID_H_

#include <time.h>
#include "cmsis.h"
#include "pid.h"

class Pid {
public:
   typedef float  InFunction();
   typedef void   OutFunction(float);
};

/**
 * PID Controller
 * Makes use of CMSIS TimerClass
 *
 * These template parameters connect the PID controller to the input and output functions
 * @tparam inputFn      Input function  - used to obtain value of system state
 * @tparam outputFn     Output function - used to control the output variable
 */
template<Pid::InFunction inputFn, Pid::OutFunction outputFn>
class Pid_T : private Pid, private CMSIS::TimerClass<osTimerPeriodic> {

private:
   const double interval;     //! Interval for sampling
   const double outMin;       //! Minimum limit for output
   const double outMax;       //! Maximum limit for output

   double kp;                 //! Proportional Tuning Parameter
   double ki;                 //! Integral Tuning Parameter
   double kd;                 //! Derivative Tuning Parameter

   bool   enabled;            //! Enable for controller

   double integral;           //! Integral accumulation term

   double lastInput;          //! Last input sample
   double currentInput;       //! Current input sample
   double currentOutput;      //! Current output
   double setpoint;           //! Set-point for controller
   double currentError;       //! Current error calculation

   unsigned tickCount = 0;    //! Time in ticks since last enabled

public:
   /**
    * Constructor
    *
    * @param[in] Kp          Initial proportional constant
    * @param[in] Ki          Initial integral constant
    * @param[in] Kd          Initial differential constant
    * @param[in] interval    Sample interval for controller
    * @param[in] outMin      Minimum value of output variable
    * @param[in] outMax      Maximum value of output variable
    */
   Pid_T(double Kp, double Ki, double Kd, double interval, double outMin, double outMax) :
      interval(interval), outMin(outMin), outMax(outMax), enabled(false) {
      setTunings(Kp, Ki, Kd);
      create();
   }

   /**
   * Destructor
   */
   virtual ~Pid_T() {
   }

   /**
    * Enable controller\n
    * Note: Controller is re-initialised when enabled
    *
    * @param[in] enable True to enable
    */
   void enable(bool enable = true) {
      if (enable) {
         if (!enabled) {
            // Just enabled
            currentInput = inputFn();
            integral     = 0; //currentOutput;
            tickCount    = 0;
            start(interval);
         }
      }
      else {
         stop();
      }
      enabled = enable;
   }

   /**
    * Indicates if the controller is enabled
    *
    * @return True => enabled
    */
   bool isEnabled() {
      return enabled;
   }

   /**
    * Get number of ticks since last enabled
    *
    * @return Number of ticks
    */
   unsigned getTicks() {
      return tickCount;
   }

   /**
    * Get number of seconds since last enabled
    *
    * @return Elapsed time
    */
   double getElapsedTime() {
      return (tickCount*interval);
   }

   /**
    * Change controller tuning
    *
    * @param[in] Kp Proportional constant
    * @param[in] Ki Integral constant
    * @param[in] Kd Differential constant
    */
   void setTunings(double Kp, double Ki, double Kd) {
      if ((Kp<0) || (Ki<0) || (Kd<0)) {
         USBDM::setAndCheckErrorCode(USBDM::E_ILLEGAL_PARAM);
      }
      kp = Kp;
      ki = Ki * interval;
      kd = Kd / interval;
   }

   /**
    * Change set-point of controller
    *
    * @param[in] value Value to set
    */
   void setSetpoint(double value) {
      setpoint = value;
   }

   /**
    * Get setpoint of controller
    *
    * @return Current setpoint
    */
   double getSetpoint() {
      return setpoint;
   }

   /**
    * Get input of controller
    *
    * @return Last input sample
    */
   double getInput() {
      return currentInput;
   }

   /**
    * Get setpoint of controller
    *
    * @return Last output sample
    */
   double getOutput() {
      return currentOutput;
   }

   /**
    * Get error of controller
    *
    * @return Last error calculation
    */
   double getError() {
      return currentError;
   }

   /**
    * Get proportional control factor
    *
    * @return factor as double
    */
   double getKp() {
      return  kp;
   }
   /**
    * Get integral control factor
    *
    * @return factor as double
    */
   double getKi() {
      return  ki/interval;
   }
   /**
    * Get differential control factor
    *
    * @return factor as double
    */
   double getKd() {
      return  kd*interval;
   }

private:
   /**
    * Main PID calculation
    *
    * Executed at \ref interval by Timer callback
    */
   void callback() override {
      if(!enabled) {
         return;
      }

      tickCount++;

      // Update input samples & error
      lastInput    = currentInput;
      currentInput = inputFn();
      currentError = setpoint - currentInput;

      integral += (ki * currentError);
      if(integral > outMax) {
         integral = outMax;
      }
      else if(integral < outMin) {
         integral = outMin;
      }
      double deltaInput = (currentInput - lastInput);

      currentOutput = kp * currentError + integral - kd * deltaInput;
      if(currentOutput > outMax) {
         currentOutput = outMax;
      }
      else if(currentOutput < outMin) {
         currentOutput = outMin;
      }
      // Update output
      outputFn(currentOutput);
   }

};

#endif // PROJECT_HEADERS_PID_H_
