/**
 * @file    pid.h
 * @brief   PID Controller
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
 * Makes use of CMSIS Timer callback
 *
 * These template parameters connect the PID controller to the input and output functions
 * @tparam inputFn      Input function  - used to obtain value of system state
 * @tparam outputFn     Output function - used to control the output variable
 */
template<Pid::InFunction inputFn, Pid::OutFunction outputFn>
class Pid_T : Pid {

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

private:
   /** Used by static callback to locate class */
   static Pid_T *This;

   /** Used to wrap the class method for passing to Timer callback */
   static void callBack(const void *) {
      This->update();
   }

   /** Used to wrap the class function for passing to Timer callback */
   CMSIS::Timer<osTimerPeriodic> timer{callBack};

public:
   /**
    * Constructor
    *
    * @param Kp          Initial proportional constant
    * @param Ki          Initial integral constant
    * @param Kd          Initial differential constant
    * @param interval    Sample interval for controller
    * @param outMin      Minimum value of output variable
    * @param outMax      Maximum value of output variable
    */
   Pid_T(double Kp, double Ki, double Kd, double interval, double outMin, double outMax) :
      interval(interval), outMin(outMin), outMax(outMax), enabled(false) {
      setTunings(Kp, Ki, Kd);
      This = this;
   }

   ~Pid_T() {
   }

   void initialise() {
//      timer.create();
   }

   /**
    * Enable controller\n
    * Note: Controller is re-initialised when enabled
    *
    * @param enable True to enable
    */
   void enable(bool enable = true) {
      if (enable) {
         if (!enabled) {
            // Just enabled
            currentInput = inputFn();
            integral     = 0; //currentOutput;
            tickCount    = 0;
            timer.start(interval);
         }
      }
      else {
         timer.stop();
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
    * @param Kp Proportional constant
    * @param Ki Integral constant
    * @param Kd Differential constant
    */
   void setTunings(double Kp, double Ki, double Kd) {
      if (Kp<0 || Ki<0 || Kd<0) {
         USBDM::setAndCheckErrorCode(USBDM::E_ILLEGAL_PARAM);
      }
      kp = Kp;
      ki = Ki * interval;
      kd = Kd / interval;
   }

   /**
    * Change set-point of controller
    *
    * @param value Value to set
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
   void update() {
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
template<Pid::InFunction inputFn, Pid::OutFunction outputFn>
Pid_T<inputFn, outputFn>* Pid_T<inputFn, outputFn>::This = nullptr;

#endif // PROJECT_HEADERS_PID_H_
