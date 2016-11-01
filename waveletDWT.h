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
        int filterLength = filter.getFilterLength();

        //apply fitler to convolution kernel
        transform.forwardTransform(inputSignal, signalLength,
                                   lowFilter, highFilter, 
                                   lowCoeff, highCoeff,
                                   filterLength);
    }
};
