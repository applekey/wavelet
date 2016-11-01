#include <iostream>
#include <vector>
#include "waveletCompressor.h"

void printCoefficients(std::vector<int>& coefficientLengths, double * outputSignal) {
    int coefficientLevels = coefficientLengths.size();
    //last coefficient level is just a place holder
    int currentOutputIndex = 0;
    for(int i = 1; i< coefficientLevels;i++) {
        std::cerr<<"Level: "<<i<<std::endl;
        int levelCoefficientSize = coefficientLengths[i];
        for(int j = 0; j<levelCoefficientSize;j++) {
            double coeffVal = outputSignal[currentOutputIndex + j];
            std::cerr<<coeffVal<<" ";
        }
        currentOutputIndex += levelCoefficientSize;
        std::cerr<<std::endl;
    }
}

int main(int argc, const char * argv[]) {
    waveletCompressor compressor;
    //generate constant signal that is power of 2, 64
    int signalLength = 64;
    double inputSignal[64];
    for(int i = 0; i < 64; i++) {
        inputSignal[0] = 1.0;
    }

    int levelsToCompress = 1;
    std::vector<int> coefficientLengths;
    double * coefficients = compressor.compressWave(inputSignal, signalLength, 
                                                        levelsToCompress, coefficientLengths);
    printCoefficients(coefficientLengths, coefficients);
    return 0;
}
