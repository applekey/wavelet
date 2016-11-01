class waveletTransform {

public:
    void forwardTransform(double * inputSignal, int signalLength,
                          double * lowFilter, double * highFilter,
                          double * lowCoeff, double * highCoeff, 
                          int filterLength) {
        //extend the signal with 0's to the right and to the left
        int extendedSigLength = signalLength + 2 * (filterLength - 1);

        double  * extendedSignal = new double[extendedSigLength];
        //pad the left and right
        double padValue = 0;

        for(int i = 0; i < signalLength - 1 ; i++) {
            extendedSignal[i] = 0;
        }

        for(int i = 0; i < signalLength - 1 ; i++) {
            extendedSignal[extendedSigLength - 1 - i] = 0;
        }

        // copy the rest of the signal into
        for(int i = 0; i < signalLength; i++ ) {
            extendedSignal[signalLength - 1 + i] = inputSignal[i];
        }

        //apply convolution kernel to inputSignal
        // assume that the signal has being extended
        for(int i = 0; i < signalLength; i++) {
            double * filter = (i % 2 != 0) ? lowFilter : highFilter;
            double * outputCoefficient = (i % 2 != 0) ?lowCoeff: highCoeff; 
            int coefficientIndex = i / 2;
        
            applyConvolution(i, inputSignal, signalLength,
                             filter, filterLength, outputCoefficient, coefficientIndex);
        }
        //delete the extended signal
        delete [] extendedSignal;
    }

    void applyConvolution(int inputIndex,
                          double * inputSignal, int signalLength,
                          double * filter,
                          int filterLength,
                          double * outputCoefficient,
                          int coefficientIndex) {
        //assume that the filterLength will be an odd value
        int filterRadius = filterLength / 2;
        double sum = 0;
        for(int i = 0; i <= filterRadius; i++) {
            //convole front
            sum += filter[i] * inputSignal[inputIndex - 1 - filterRadius + i];

            //convolve back
            sum += filter[filterRadius + 1 + i] * inputSignal[inputIndex + 1 + i];
        }
        sum += filter[filterRadius + 1] * inputSignal[inputIndex];

        outputCoefficient[coefficientIndex] = sum;
    }

    int getLength(int inputSignalLength) {
        //assume all filters are symetric
        return (inputSignalLength % 2 != 0) ?
               (inputSignalLength - 1) / 2 : inputSignalLength / 2;
    }
};
