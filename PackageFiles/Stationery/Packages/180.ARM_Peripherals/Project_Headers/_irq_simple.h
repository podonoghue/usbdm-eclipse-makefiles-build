   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  enable    True => enable, False => disable
    * @param[in]  priority  Interrupt priority
    */
   static void enableNvicInterrupts(bool enable=true, uint32_t priority=NvicPriority_Normal) {

      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], priority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }
