#include <iostream>
#include <vector>
#include "waveletCompressor.h"

void printCoefficients(std::vector<int>& coefficientLengths, double * outputSignal) {
    int coefficientLevels = coefficientLengths.size();
    for(int i = 0; i< coefficientLevels;i++) {
        
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
    double * highCoefficients = compressor.compressWave(inputSignal, signalLength, 
                                                        levelsToCompress, coefficientLengths);
    return 0;
}
