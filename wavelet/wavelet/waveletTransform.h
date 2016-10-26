#include "waveletFilter.h"
class waveletTransform {
private;
    waveletFilter filter;
    
public:
    void forwardTransform(double * inputSignal, int signalLength
                          double * filter, int filterLength) {
        //extend the signal with 0's to the right and to the left
        int extendedSigLength = signalLength + 2 *(filterLength - 1);
        
        double  * extendedSignal = new double[extendedSigLength];
        //pad the left and right
        double padValue = 0;
        
        for(int i = 0; i< signalLength-1 ;i++) {
            extendedSignal[i] = 0;
        }
        
        for(int i = 0; i< signalLength-1 ;i++) {
            extendedSignal[extendedSigLength - 1 - i] = 0;
        }
        
        // copy the rest of the signal into
        for(int i = 0;i <signalLength;i++ ) {
            extendedSignal[signalLength-1 + i] = inputSignal[i];
        }
        
        //apply convolution kernel to inputSignal
        // assume that the signal has being extended
        for(int i = 0; i< signalLength; i++) {
            applyConvolution(i, inputSignal, signalLength,
                             filter, filterLength);
        }
        
        //delete the extended signal
    }
    
    void extendSignal() {
        
    }
    
    void applyConvolution(int inputIndex,
                          double * inputSignal, int signalLength
                          double * filter, int filterLength){
        
    }
    
    int getLength(int inputSignalLength) {
        //assume all filters are symetric
        return (inputSignalLength % 2 == 0) ?
            (sigInLen- 1) / 2 : sigInLen / 2;
    }
};
