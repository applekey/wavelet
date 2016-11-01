#include "waveletTransform.h"
#include "waveletFilter.h"

#define COEFF_TYPE double

class waveletDWT {
private:
    waveletFilter filter;
    waveletTransform transform;
public:
    //assume that the signal length is an odd
    void DWT1D(double * inputSignal, int signalLength,
               double * lowCoeff, double * highCoeff) {
        //get the filter low and high and apply
        double * lowFilter = filter.getLowPassFilter();
        double * highFilter = filter.getHighPassFilter();

        //apply fitler to convolution kernel
        for(int i = 0; i< signalLength; i++) {
            //allocate high coeeficient buffer
            double * coeff = (i % 2 != 0) ? lowCoeff : highCoeff;
            //the signal is split,
            int coefficientIndex = i/2;
            //transform.applyConvolution(inputSignal, signalLength, coefficientIndex, coeff);
        }
    }
};
