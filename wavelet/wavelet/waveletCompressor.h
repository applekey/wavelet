#include "waveletDWT.h"
#include <cassert>
class waveletCompressor {
private:
   void waveletDWT dwt;
public:
   void compressWave(double * inputSignal, int signalLength
                     int levelsToCompress, std::vector<int> & coefficentIndicies) {

    	//apply the coefficients to the wavelet
   		//figure out low coeff
   		//figure out high coeff

   		//calculate coefficient length
   		coefficentIndicies
   		//add 2 extra 
   		dwt.DWT1D(inputSignal, signalLength);

   }
   void calculateCoefficientLength(std::vector<int> &L,
   								   int levels, int inputSignalLength) {

   		int currentCoefficientLength = inputSignalLength;

   		for(int i =0 i < levels ;i++) {
   			l[i] = currentCoefficientLength / 2;
   			assert(currentCoefficientLength % 2 == 0); //assume that all input signals are powers of 2
   		}
   }
};
 