/** \file SpO2algorithm.h ******************************************************
 *
 * Project: MAXREFDES117#
 * Filename: algorithm.c
 * Description: This module is the heart rate/SpO2 calculation algorithm header file
 *
 * Revision History:
 * 1-18-2016 Rev 01.00 SK Initial release.
 */
/*******************************************************************************
 * Copyright (C) 2015 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *******************************************************************************
 */
#ifndef SPO2_ALGORITHM_H_
#define SPO2_ALGORITHM_H_

#include <stdint.h>
#include "CircularBuffer.h"

/**
 * Represents a MAX30102 measurement
 */
struct Pair {
   uint32_t redLed;
   uint32_t irLed;
};

/** Maximum number of items that can accumulate while the measurement buffer is processed */
static constexpr int BUFFER_MARGIN   = 20;
/** Size of buffer - determines the period of sampling */
static constexpr int BUFFER_SIZE     = 5*100;
/** How often to update buffer calculations (in samples) */
static constexpr int UPDATE_INTERVAL = 100;

/**
 * Circular buffer holding measurements.\n
 * The buffer is made slightly larger than the nominal size to allow for new measurements to
 * accumulate while the last set of measurements is processed.
 */
using Spo2Buffer = CircularBuffer<(BUFFER_SIZE+BUFFER_MARGIN),Pair>;

/**
 * @brief        Calculate the heart rate and SpO2 level
 * @par          Details
 *               By detecting peaks of PPG cycle and corresponding AC/DC of red/infra-red signal, the ratio for the SPO2 is computed.
 *
 * @param[in]  spo2Buffer       - Buffer contains MAX30102 IR LED and Red LED values
 * @param[out] sp02Value        - Calculated SpO2 value
 * @param[out] sp02IsValid      - Indicates if the calculated SpO2 value is valid
 * @param[out] heartRateValue   - Calculated heart rate value
 * @param[out] heartRateIsValid - Indicates if the calculated heart rate value is valid
 */
void maxim_heart_rate_and_oxygen_saturation(Spo2Buffer &spo2Buffer, int &sp02Value, bool &sp02IsValid, int &heartRateValue, bool &heartRateIsValid);

#endif /* SPO2_ALGORITHM_H_ */
