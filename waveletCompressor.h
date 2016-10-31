#include "waveletDWT.h"
#include <cassert>
class waveletCompressor {
private:
   void waveletDWT dwt;
    struct signalWithLength {
        double * coefficients;
        int length;
    }
public:
   void compressWave(double * inputSignal, int signalLength
                     int levelsToCompress, std::vector<int> & coefficentIndicies) {

    	//apply the coefficients to the wavelet
   		//figure out low coeff
   		//figure out high coeff

   		//calculate coefficient length
   		calculateCoefficientLength();
   		//add 2 extra 

		//calculate length
        int coefficientLength = signalLength/2;//assume that all signal lengths are powers of 2 

        //allocate low coeeficient buffer, we'll just re-use this
        double * currentInputSignal = inputSignal;
        struct signalWithLength lowCoeffBuffer;
        lowCoeffBuffer.length = coefficientLength;
        lowCoeffBuffer.coefficients = new COEFF_TYPE[];
        for(int level = 0; i< levelsToCompress; i++) {
   		    dwt.DWT1D(currentInputSignal, signalLength);
            //swap signal for new signal which are now the low coefficients
            lowCoeffBuffer.length = coefficientLength;
            currentInputSignal = lowCoeffBuffer.coefficients;
            signalLength = currentCoefficientLength; 
            coefficientLength=/2;
        }
   }
   void calculateCoefficientLength(std::vector<int> &L,
   								   int levels, int inputSignalLength) {

   		int currentCoefficientLength = inputSignalLength;
   		l.reserve(inputSignalLength + 2)ff;


   		for(int i =0 i < levels + 2 ;i++) {
   			l[i] = currentCoefficientLength / 2;
   			assert(currentCoefficientLength % 2 == 0); //assume that all input signals are powers of 2
   		}
   }
};
 
