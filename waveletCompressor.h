#include "waveletDWT.h"
#include <cassert>
class waveletCompressor {
private:
    waveletDWT dwt;
    struct signalWithLength {
        double * coefficients;
        int length;
    };
public:
   void compressWave(double * inputSignal, int signalLength,
                     int levelsToCompress, std::vector<int> & coefficentIndicies) {

    	//apply the coefficients to the wavelet
   		//calculate coefficient length
   		calculateCoefficientLength(coefficentIndicies, levelsToCompress, signalLength);
   		//add 2 extra 

		//calculate length
        int coefficientLength = signalLength/2;//assume that all signal lengths are powers of 2 

        //allocate low coeeficient buffer, we'll just re-use this
        double * currentInputSignal = inputSignal;
        struct signalWithLength lowCoeffBuffer;
        lowCoeffBuffer.length = coefficientLength;
        lowCoeffBuffer.coefficients = new COEFF_TYPE[coefficientLength];

        for(int level = 0; level< levelsToCompress; level++) {

            struct signalWithLength highCoeffBuffer;
            highCoeffBuffer.length = coefficientLength;
            highCoeffBuffer.coefficients = new COEFF_TYPE[coefficientLength];

   		    dwt.DWT1D(currentInputSignal, signalLength,
                      lowCoeffBuffer.coefficients, highCoeffBuffer.coefficients);

            //swap signal for new signal which are now the low coefficients
            lowCoeffBuffer.length = coefficientLength;
            currentInputSignal = lowCoeffBuffer.coefficients;

            //the coeffficients are now the new signal
            signalLength = coefficientLength; 
            coefficientLength /=2;

        }
   }
   void calculateCoefficientLength(std::vector<int> &L,
   								   int levels, int inputSignalLength) {

   		int currentCoefficientLength = inputSignalLength;
   		L.reserve(inputSignalLength + 2);


   		for(int i =0 ;i < levels + 2 ;i++) {
   			L[i] = currentCoefficientLength / 2;
   			assert(currentCoefficientLength % 2 == 0); //assume that all input signals are powers of 2
   		}
   }
};
 
