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
    double * compressWave(double * inputSignal, int signalLength,
                          int levelsToCompress, std::vector<int> & coefficentIndicies) {

        //apply the coefficients to the wavelet
        //calculate coefficient length
        int totalCoefficientLength = 0;
        calculateCoefficientLength(coefficentIndicies, levelsToCompress,
                                   signalLength, totalCoefficientLength);
        //allocate buffer for all high coefficients
        double * outputCoefficients = new double[totalCoefficientLength];
        double * currentCoeffPointer = outputCoefficients;
        int currentOutputCoefficientIndex = 0;

        //calculate length
        int coefficientLength = signalLength / 2; //assume that all signal lengths are powers of 2

        //allocate low coeeficient buffer, we'll just re-use this
        double * currentInputSignal = inputSignal;
        struct signalWithLength lowCoeffBuffer;
        lowCoeffBuffer.length = coefficientLength;
        lowCoeffBuffer.coefficients = new double[coefficientLength];

        for(int level = 0; level < levelsToCompress; level++) {

            struct signalWithLength highCoeffBuffer;
            highCoeffBuffer.length = coefficientLength;
            highCoeffBuffer.coefficients = currentCoeffPointer;

            dwt.DWT1D(currentInputSignal, signalLength,
                      lowCoeffBuffer.coefficients, highCoeffBuffer.coefficients);

            currentCoeffPointer += coefficentIndicies[level];

            //swap signal for new signal which are now the low coefficients
            lowCoeffBuffer.length = coefficientLength;
            currentInputSignal = lowCoeffBuffer.coefficients;

            //the coeffficients are now the new signal
            signalLength = coefficientLength;
            coefficientLength /= 2;
        }

        return outputCoefficients;
    }

    void calculateCoefficientLength(std::vector<int> &L, int levels,
                                    int inputSignalLength, int & totalLength) {

        totalLength = 0;
        int currentCoefficientLength = inputSignalLength;
        L.reserve(levels + 2);
        L[0] = 0;

        for(int i = 1 ; i < levels; i++) {
            L[i] = currentCoefficientLength + L[i-1];
            currentCoefficientLength /= 2;
        }

        //append last level, which is just the high and low coefficients
        L[levels] = currentCoefficientLength + L[levels-1];
        totalLength = currentCoefficientLength + L[levels];
    }
};
