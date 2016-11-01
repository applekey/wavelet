#define SIGNAL_PAD_VALUE 0
class waveletTransform {

public:
    void forwardTransform(double * inputSignal, int signalLength,
                          double * lowFilter, double * highFilter,
                          double * lowCoeff, double * highCoeff, 
                          int filterLength) {
        //extend the signal with 0's to the right and to the left
        int extendedSigLength = signalLength + 2 * (filterLength - 1);

        double * extendedSignal = new double[extendedSigLength];
        //pad the left and right
        int padLength = filterLength - 1;

        for(int i = 0; i < padLength ; i++) {
            extendedSignal[i] = SIGNAL_PAD_VALUE; //pad left
            extendedSignal[extendedSigLength - 1 - i] = SIGNAL_PAD_VALUE; //pad right
        }

        //copy the remaining signal
        for(int i = 0; i < signalLength; i++ ) {
            extendedSignal[padLength + i] = inputSignal[i];
        }

        //apply convolution kernel to inputSignal
        // assume that the signal has being extended
        for(int i = 0; i < signalLength; i++) {
            double * filter = (i % 2 != 0) ? lowFilter : highFilter;
            double * outputCoefficient = (i % 2 != 0) ? lowCoeff : highCoeff; 
            int coefficientIndex = i / 2;
            int signalPaddedIndex = i + padLength; 
            applyConvolution(signalPaddedIndex, extendedSignal, signalLength,
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
            sum += filter[i] * inputSignal[(inputIndex - 1) - (filterRadius - i)];

            //convolve back
            sum += filter[(filterRadius + 1) + i] * inputSignal[inputIndex + 1 + i];
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
