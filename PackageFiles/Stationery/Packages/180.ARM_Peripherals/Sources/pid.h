/*
 * pid.h
 *
 *  Created on: 10 Jul 2016
 *      Author: podonoghue
 */

#ifndef PROJECT_HEADERS_PID_H_
#define PROJECT_HEADERS_PID_H_

#include <time.h>
#include <functional>
#include "pit.h"
#include "pid.h"

class PID {
public:
   typedef float  InFunction();
   typedef void   OutFunction(float);
};

/**
 * These template parameters connect the PID controller to the control variables/operations
 *
 * @tparam inputFn      Input function  - used to obtain value of system state
 * @tparam outputFn     Output function - used to control the output variable
 * @tparam timerChannel The PIT channel to use for timing
 */
template<PID::InFunction inputFn, PID::OutFunction outputFn, unsigned timerChannel>
class PID_T : PID {

private:
   const double interval;
   const double outMin;
   const double outMax;

   double kp;                 // Proportional Tuning Parameter
   double ki;                 // Integral Tuning Parameter
   double kd;                 // Derivative Tuning Parameter

   bool   enabled;            // Enable for controller

   double integral;           // Integral accumulation term

   double lastInput;          // Last input sample
   double currentInput;       // Current input sample
   double currentOutput;      // Current output
   double setpoint;           // Setpoint for controller
   double currentError;

   unsigned tickCount = 0;

public:

   class FunctionWrapper {
      static PID_T *This;

   public:
      FunctionWrapper(PID_T *This) {
         this->This = This;
      };
      static void f(void) {
         This->update();
      }
   };

   /** Used to wrap the class function for passing to PIT callback */
   FunctionWrapper *functionWrapper = new FunctionWrapper(this);

   /**
    * Constructor
    *
    * @param Kp          Initial proportional constant
    * @param Ki          Initial integral constant
    * @param Kd          Initial differential constant
    * @param interval    Sample interval for controller. (update() should be called at this interval)
    * @param outMin      Minimum value of output variable
    * @param outMax      Maximum value of output variable
    */
   PID_T(double Kp, double Ki, double Kd, double interval, double outMin, double outMax) :
      interval(interval), outMin(outMin), outMax(outMax)  {

      setTunings(Kp, Ki, Kd);

      // Using PIT
      USBDM::Pit::enable();
      USBDM::Pit::setCallback(timerChannel, functionWrapper->f);

      // Controller initially disabled
      enable(false);
   }

   ~PID_T() {
      delete functionWrapper;
   }
   /**
    * Enable controller\n
    * Note: Controller is re-initialised when enabled
    *
    * @param enable True to enable
    */
   void enable(bool enable = true) {
      if (enable && !enabled) {
         // Just enabled
         currentInput = inputFn();
         integral     = currentOutput;
         tickCount    = 0;
      }
      enabled = enable;
      USBDM::Pit::setPeriod(timerChannel, interval);
      USBDM::Pit::enableChannel(timerChannel, enable);
      USBDM::Pit::enableInterrupts(timerChannel, enable);
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
    */
   unsigned getTicks() {
      if (!enabled) {
         return 0;
      }
      return tickCount;
   }
   /**
    * Main PID calculation
    *
    * Should be called \ref interval interval
    */
   void update() {
      if(!enabled) {
         return;
      }

      tickCount++;

      // Update input samples & error
      lastInput = currentInput;
      currentInput = inputFn();
      currentError = setpoint - currentInput;

      integral += (ki * currentError);
      if(integral > outMax) {
         integral = outMax;
      }
      else if(integral < outMin) {
         integral = outMin;
      }
      double dInput = (currentInput - lastInput);

      currentOutput = kp * currentError + integral - kd * dInput;
      if(currentOutput > outMax) {
         currentOutput = outMax;
      }
      else if(currentOutput < outMin) {
         currentOutput = outMin;
      }
      // Update output
      outputFn(currentOutput);
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
    * Change setpoint of controller
    *
    * @param value Value to set
    */
   void setSetpoint(double value) {
      if (value>5000.0) {
         return;
      }
      if (value<-5000.0) {
         return;
      }
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

};
template<PID::InFunction inputFn, PID::OutFunction outputFn, unsigned timerChannel> PID_T<inputFn, outputFn, timerChannel>* PID_T<inputFn, outputFn, timerChannel>::FunctionWrapper::This = nullptr;

#endif // PROJECT_HEADERS_PID_H_
