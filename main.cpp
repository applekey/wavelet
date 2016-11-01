#include <iostream>
#include <vector>
#include "waveletCompressor.h"

int main(int argc, const char * argv[]) {
    waveletCompressor compressor;
    //generate constant signal that is power of 2, 64
    int signalLength = 64;
    double inputSignal[64];
    for(int i = 0; i < 64; i++ ) {
        inputSignal[0] = 1.0;
    }
    //void compressWave(double * inputSignal, int signalLength
    //int levelsToCompress, std::vector<int> & coefficentIndicies) {
    std::vector<int> coefficientLengths;
    int levelsToCompress = 1;

    compressor.compressWave(inputSignal, signalLength, levelsToCompress, coefficientLengths);

    return 0;
}

