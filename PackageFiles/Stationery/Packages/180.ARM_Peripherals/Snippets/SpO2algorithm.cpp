/** \file algorithm.cpp ******************************************************
 *
 * Project: MAXREFDES117#
 * Filename: algorithm.cpp
 * Description: This module calculates the heart rate/SpO2 level
 *
 *
 * --------------------------------------------------------------------
 *
 * This code follows the following naming conventions:
 *
 * char              ch_pmod_value
 * char (array)      s_pmod_s_string[16]
 * float             f_pmod_value
 * int32_t           n_pmod_value
 * int32_t (array)   an_pmod_value[16]
 * int16_t           w_pmod_value
 * int16_t (array)   aw_pmod_value[16]
 * uint16_t          uw_pmod_value
 * uint16_t (array)  auw_pmod_value[16]
 * uint8_t           uch_pmod_value
 * uint8_t (array)   auch_pmod_buffer[16]
 * uint32_t          un_pmod_value
 * int32_t *         pn_pmod_value
 *
 * ------------------------------------------------------------------------- */
/*******************************************************************************
 * Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
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
 *
 * Modified: podonoghue
 *******************************************************************************
 */
#include "SpO2algorithm.h"
#include "max30102-example.h"

#define HR_FIFO_SIZE    7
#define MA4_SIZE        4 // DO NOT CHANGE
#define HAMMING_SIZE    5 // DO NOT CHANGE

static void maxim_find_peaks( uint32_t *pn_locs, uint32_t *pn_npks, int32_t *pn_x, uint32_t n_size, uint32_t n_min_height, uint32_t n_min_distance, uint32_t n_max_num );
static void maxim_peaks_above_min_height( uint32_t *pn_locs, uint32_t *pn_npks,  int32_t *pn_x, uint32_t n_size, int32_t n_min_height );
static void maxim_remove_close_peaks( uint32_t *pn_locs, uint32_t *pn_npks, int32_t  *pn_x, uint32_t n_min_distance );
static void maxim_sort_ascend( uint32_t *pn_x, uint32_t n_size );
static void maxim_sort_indices_descend( int32_t *pn_x, uint32_t *pn_indx, uint32_t n_size);

#define min(x,y) ((x) < (y) ? (x) : (y))

const uint16_t auw_hamm[31]={ 41,    276,    512,    276,     41 }; // Hamm = long16(512* hamming(5)');

/**
 * SPO2table is computed as  -45.060*ratioAverage* ratioAverage + 30.354 *ratioAverage + 94.845 ;
 */
static const uint8_t uch_spo2_table[184]={
      95, 95, 95, 96, 96, 96, 97, 97, 97, 97, 97, 98, 98, 98, 98, 98, 99, 99, 99, 99,
      99, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
      100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 99, 99, 98, 98, 98, 98, 98, 98, 97, 97,
      97, 97, 96, 96, 96, 96, 95, 95, 95, 94, 94, 94, 93, 93, 93, 92, 92, 92, 91, 91,
      90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 85, 85, 84, 84, 83, 82, 82, 81, 81,
      80, 80, 79, 78, 78, 77, 76, 76, 75, 74, 74, 73, 72, 72, 71, 70, 69, 69, 68, 67,
      66, 66, 65, 64, 63, 62, 62, 61, 60, 59, 58, 57, 56, 56, 55, 54, 53, 52, 51, 50,
      49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 31, 30, 29,
      28, 27, 26, 25, 23, 22, 21, 20, 19, 17, 16, 15, 14, 12, 11, 10, 9, 7, 6, 5,
      3, 2, 1
};

static  int32_t an_dx[BUFFER_SIZE-MA4_SIZE]; // delta
static  int32_t an_x[BUFFER_SIZE];           // Processed IR LED values
static  int32_t an_y[BUFFER_SIZE];           // Processed Red LED values

/**
 * \brief        Calculate the heart rate and SpO2 level
 * \par          Details
 *               By detecting  peaks of PPG cycle and corresponding AC/DC of red/infra-red signal, the ratio for the SPO2 is computed.
 *               Since this algorithm is aiming for Arm M0/M3. Formula for SPO2 did not achieve the accuracy due to register overflow.
 *               Thus, accurate SPO2 is precalculated and save long uch_spo2_table[] per each ratio.
 *
 * \param[out]    pn_spo2              - Calculated SpO2 value
 * \param[out]    pch_spo2_valid       - true if the calculated SpO2 value is valid
 * \param[out]    pn_heart_rate        - Calculated heart rate value
 * \param[out]    pch_hr_valid         - true if the calculated heart rate value is valid
 *
 * \retval       None
 */
void maxim_heart_rate_and_oxygen_saturation(uint32_t &pn_spo2, bool &pch_spo2_valid, uint32_t &pn_heart_rate, bool &pch_hr_valid) {

   // Remove DC of IR signal
   uint32_t un_ir_mean = 0;
   for (unsigned k=0 ; k<BUFFER_SIZE ; k++ ) {
      un_ir_mean += buffer[k].irLed;
   }
   un_ir_mean = un_ir_mean/BUFFER_SIZE ;
   for (unsigned k=0 ; k<BUFFER_SIZE ; k++ )  {
      an_x[k] =  buffer[k].irLed - un_ir_mean ;
   }

   // 4 point moving average
   for(unsigned k=0; k< BUFFER_SIZE-MA4_SIZE; k++){
      an_x[k] = (an_x[k] + an_x[k+1] + an_x[k+2] + an_x[k+3])/4;
   }

   // Get difference of smoothed IR signal
   for(unsigned k=0; k<BUFFER_SIZE-MA4_SIZE-1;  k++) {
      an_dx[k]= (an_x[k+1]- an_x[k]);
   }

   // 2-pt Moving Average to an_dx
   for(unsigned k=0; k< BUFFER_SIZE-MA4_SIZE-2; k++) {
      an_dx[k] =  (an_dx[k]+an_dx[k+1])/2 ;
   }

   // Hamming window
   // Flip wave form so that we can detect valley with peak detector
   for (unsigned i=0 ; i<BUFFER_SIZE-HAMMING_SIZE-MA4_SIZE-2 ;i++){
      int32_t s = 0;
      for(unsigned k=i; k<(i+HAMMING_SIZE); k++){
         s -= an_dx[k]*auw_hamm[k-i];
      }
      an_dx[i] = s/1146; // Divide by sum of auw_hamm
   }

   int32_t n_th1 = 0; // Threshold calculation
   for (unsigned k=0 ; k<(BUFFER_SIZE-HAMMING_SIZE); k++){
      n_th1 += ((an_dx[k]>0)? an_dx[k] : (0-an_dx[k])) ;
   }
   n_th1 = n_th1/(BUFFER_SIZE-HAMMING_SIZE);

   // Peak location is actually index for sharpest location of raw signal since we flipped the signal
   uint32_t an_dx_peak_locs[15] ;
   uint32_t n_npks;
   maxim_find_peaks( an_dx_peak_locs, &n_npks, an_dx, BUFFER_SIZE-HAMMING_SIZE, n_th1, 8, 5 ); //peak_height, peak_distance, max_num_peaks

   if (n_npks>=2){
      uint32_t n_peak_interval_sum = 0;
      for (unsigned k=1; k<n_npks; k++) {
         n_peak_interval_sum += (an_dx_peak_locs[k]-an_dx_peak_locs[k -1]);
      }
      n_peak_interval_sum = n_peak_interval_sum/(n_npks-1);
      pn_heart_rate = (int32_t)(6000/n_peak_interval_sum);// beats per minutes
      pch_hr_valid  = true;
   }
   else  {
      pn_heart_rate = -999;
      pch_hr_valid  = false;
   }

   uint32_t an_ir_valley_locs[15] ;
   for (unsigned k=0 ; k<n_npks ;k++)
      an_ir_valley_locs[k]=an_dx_peak_locs[k]+HAMMING_SIZE/2;


   // Raw value : RED(=y) and IR(=X)
   // We need to assess DC and AC value of ir and red PPG.
   for (unsigned k=0 ; k<BUFFER_SIZE ; k++ )  {
      an_x[k] =  buffer[k].irLed;
      an_y[k] =  buffer[k].redLed;
   }

   // Find precise min near an_ir_valley_locs
   uint32_t an_exact_ir_valley_locs[15] ;
   uint32_t n_exact_ir_valley_locs_count = 0;
   for(unsigned k=0 ; k<n_npks ;k++){
      bool un_only_once = true;
      uint32_t m = an_ir_valley_locs[k];
      int32_t n_c_min= 16777216;//2^24;
      if (m+5 <  BUFFER_SIZE-HAMMING_SIZE  && m-5 >0){
         for(unsigned i= m-5;i<m+5; i++)
            if (an_x[i]<n_c_min){
               if (un_only_once){
                  un_only_once = false;
               }
               n_c_min = an_x[i] ;
               an_exact_ir_valley_locs[k]=i;
            }
         if (un_only_once == false)
            n_exact_ir_valley_locs_count ++ ;
      }
   }
   if (n_exact_ir_valley_locs_count<2) {
      // Do not use SPO2 since signal ratio is out of range
      pn_spo2 =  -999 ;
      pch_spo2_valid  = false;
      return;
   }

   // 4 pt MA
   for(unsigned k=0; k< BUFFER_SIZE-MA4_SIZE; k++){
      an_x[k]=( an_x[k]+an_x[k+1]+ an_x[k+2]+ an_x[k+3])/(int32_t)4;
      an_y[k]=( an_y[k]+an_y[k+1]+ an_y[k+2]+ an_y[k+3])/(int32_t)4;
   }

   // Using an_exact_ir_valley_locs, find ir-red DC and ir-red AC for SPO2 calibration ratio
   // Finding AC/DC maximum of raw ir * red between two valley locations

   uint32_t an_ratio[5];
   for(unsigned k=0; k< 5; k++) {
      an_ratio[k] = 0;
   }
   for (unsigned k=0; k< n_exact_ir_valley_locs_count; k++){
      if (an_exact_ir_valley_locs[k] > BUFFER_SIZE ){
         pn_spo2 =  -999 ; // do not use SPO2 since valley loc is out of range
         pch_spo2_valid  = false;
         return;
      }
   }
   // Find max between two valley locations
   // and use ratio between AC component of Ir & Red and DC component of Ir & Red for SPO2

   uint32_t n_y_dc_max_idx  = 0;
   uint32_t n_x_dc_max_idx  = 0;
   uint32_t n_i_ratio_count = 0;
   for (unsigned k=0; k< n_exact_ir_valley_locs_count-1; k++) {
      int32_t n_y_dc_max= -16777216;
      int32_t n_x_dc_max= -16777216;
      if ((an_exact_ir_valley_locs[k+1]-an_exact_ir_valley_locs[k]) >10){
         for (unsigned i=an_exact_ir_valley_locs[k]; i< an_exact_ir_valley_locs[k+1]; i++) {
            if (an_x[i] > n_x_dc_max) {
               n_x_dc_max     = an_x[i];
               n_x_dc_max_idx = i;
            }
            if (an_y[i] > n_y_dc_max) {
               n_y_dc_max     = an_y[i];
               n_y_dc_max_idx = i;
            }
         }
         uint32_t n_y_ac = (an_y[an_exact_ir_valley_locs[k+1]] - an_y[an_exact_ir_valley_locs[k] ] )*(n_y_dc_max_idx -an_exact_ir_valley_locs[k]); // red
         n_y_ac =  an_y[an_exact_ir_valley_locs[k]] + n_y_ac/ (an_exact_ir_valley_locs[k+1] - an_exact_ir_valley_locs[k])  ;
         n_y_ac =  an_y[n_y_dc_max_idx] - n_y_ac;    // Subtracting linear DC components from raw - xxx
         uint32_t n_x_ac= (an_x[an_exact_ir_valley_locs[k+1]] - an_x[an_exact_ir_valley_locs[k] ] )*(n_x_dc_max_idx -an_exact_ir_valley_locs[k]); // ir
         n_x_ac =  an_x[an_exact_ir_valley_locs[k]] + n_x_ac/ (an_exact_ir_valley_locs[k+1] - an_exact_ir_valley_locs[k]);
         n_x_ac =  an_x[n_y_dc_max_idx] - n_x_ac;        // Subtracting linear DC components from raw
         uint32_t n_nume  = ( n_y_ac * n_x_dc_max)>>7 ;  // Prepare X100 to preserve floating value
         uint32_t n_denom = ( n_x_ac * n_y_dc_max)>>7;
         if ((n_denom>0) && (n_i_ratio_count<5) && (n_nume != 0)) {
            // Formula is ( n_y_ac *n_x_dc_max) / ( n_x_ac *n_y_dc_max) ;
            an_ratio[n_i_ratio_count]= (n_nume*100)/n_denom ;
            n_i_ratio_count++;
         }
      }
   }

   maxim_sort_ascend(an_ratio, n_i_ratio_count);
   uint32_t n_middle_idx = n_i_ratio_count/2;

   uint32_t n_ratio_average =0;
   if (n_middle_idx >1) {
      n_ratio_average = (an_ratio[n_middle_idx-1] + an_ratio[n_middle_idx])/2; // use median
   }
   else {
      n_ratio_average = an_ratio[n_middle_idx ];
   }

   if((n_ratio_average>2) && (n_ratio_average<184)) {
      //  float_SPO2 =  -45.060*n_ratio_average* n_ratio_average/10000 + 30.354 *n_ratio_average/100 + 94.845 ;  // for comparison with table
      pn_spo2        = uch_spo2_table[n_ratio_average] ;
      pch_spo2_valid = true;
   }
   else{
      pn_spo2        = -999 ; // do not use SPO2 since signal ratio is out of range
      pch_spo2_valid = false;
   }
}


/**
 * \brief        Find peaks
 * \par          Details
 *               Find at most MAX_NUM peaks above MIN_HEIGHT separated by at least MIN_DISTANCE
 *
 * \retval       None
 */
void maxim_find_peaks(uint32_t *pn_locs, uint32_t *pn_npks, int32_t *pn_x, uint32_t n_size, uint32_t n_min_height, uint32_t n_min_distance, uint32_t n_max_num) {
   maxim_peaks_above_min_height( pn_locs, pn_npks, pn_x, n_size, n_min_height );
   maxim_remove_close_peaks( pn_locs, pn_npks, pn_x, n_min_distance );
   *pn_npks = min( *pn_npks, n_max_num );
}

/**
 * \brief        Find peaks above n_min_height
 * \par          Details
 *               Find all peaks above MIN_HEIGHT
 *
 * \retval       None
 */
void maxim_peaks_above_min_height(uint32_t *pn_locs, uint32_t *pn_npks,  int32_t *pn_x, uint32_t n_size, int32_t n_min_height) {
   uint32_t i = 1, n_width;
   *pn_npks = 0;

   while (i < n_size-1) {
      if (pn_x[i] > n_min_height && pn_x[i] > pn_x[i-1]) {           // find left edge of potential peaks
         n_width = 1;
         while (i+n_width < n_size && pn_x[i] == pn_x[i+n_width])    // find flat peaks
            n_width++;
         if (pn_x[i] > pn_x[i+n_width] && (*pn_npks) < 15 ) {        // find right edge of peaks
            pn_locs[(*pn_npks)++] = i;
            // for flat peaks, peak location is left edge
            i += n_width+1;
         }
         else
            i += n_width;
      }
      else
         i++;
   }
}

/**
 * \brief        Remove peaks
 * \par          Details
 *               Remove peaks separated by less than MIN_DISTANCE
 *
 * \retval       None
 */
void maxim_remove_close_peaks(uint32_t *pn_locs, uint32_t *pn_npks, int32_t  *pn_x, uint32_t n_min_distance) {

   /* Order peaks from large to small */
   maxim_sort_indices_descend( pn_x, pn_locs, *pn_npks );

   for (int32_t i = -1; i < (int)*pn_npks; i++ ) {
      uint32_t n_old_npks = *pn_npks;
      *pn_npks = i+1;
      for (uint32_t j = i+1; j < n_old_npks; j++ ) {
         uint32_t n_dist =  pn_locs[j] - ( i == -1 ? -1 : pn_locs[i] ); // lag-zero peak of autocorr is at index -1
         if ( n_dist > n_min_distance || n_dist < -n_min_distance )
            pn_locs[(*pn_npks)++] = pn_locs[j];
      }
   }
   // Resort indices long ascending order
   maxim_sort_ascend( pn_locs, *pn_npks );
}

/**
 * \brief        Sort array
 * \par          Details
 *               Sort array in ascending order (insertion sort algorithm)
 */
void maxim_sort_ascend(uint32_t *pn_x, uint32_t n_size) {
   for (uint32_t i = 1; (i < n_size); i++) {
      uint32_t n_temp = pn_x[i];
      uint32_t j;
      for (j = i; (j > 0) && (n_temp < pn_x[j-1]); j--) {
         pn_x[j] = pn_x[j-1];
      }
      pn_x[j] = n_temp;
   }
}

/**
 * \brief        Sort indices
 * \par          Details
 *               Sort indices according to descending order (insertion sort algorithm)
 */
void maxim_sort_indices_descend(int32_t *pn_x, uint32_t *pn_indx, uint32_t n_size) {
   for (uint32_t i = 1; (i < n_size); i++) {
      uint32_t n_temp = pn_indx[i];
      uint32_t j;
      for (j = i; (j > 0) && (pn_x[n_temp] > pn_x[pn_indx[j-1]]); j--) {
         pn_indx[j] = pn_indx[j-1];
      }
      pn_indx[j] = n_temp;
   }
}

