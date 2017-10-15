   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  enable        True => enable, False => disable
    * @param[in]  nvicPriority  Interrupt priority
    */
   static void enableNvicInterrupts(bool enable=true, uint32_t nvicPriority=NvicPriority_Normal) {

      if (enable) {
         enableNvicInterrupt(Info::irqNums[0], nvicPriority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }
