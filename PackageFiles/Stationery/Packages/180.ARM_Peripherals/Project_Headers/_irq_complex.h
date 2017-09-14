   /**
    * Enable/disable interrupts in NVIC
    *
    * @param[in]  channel   Channel being modified
    * @param[in]  enable    True => enable, False => disable
    * @param[in]  priority  Interrupt priority
	
    * @return E_NO_ERROR on success
    */
   static ErrorCode enableNvicInterrupts(XXXX channel, bool enable=true, uint32_t priority=NvicPriority_Normal) {
#ifdef DEBUG_BUILD
      if (channel>=Info::NumChannels) {
         setAndCheckErrorCode(E_ILLEGAL_PARAM);
      }
#endif

      IRQn_Type irqNum = (IRQn_Type)(Info::irqNums[0] + channel);
      if (enable) {
         // Enable interrupts
         NVIC_EnableIRQ(irqNum);

         // Set priority level
         NVIC_SetPriority(irqNum, priority);
      }
      else {
         // Disable interrupts
         NVIC_DisableIRQ(irqNum);
      }
      return E_NO_ERROR;
   }
