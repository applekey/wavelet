#include "waveletTransform.h"
#include "waveletFilter.h"
2
class waveletDWT {
private;
    waveletFilter filter;
    waveletTransform transform;
public:
	//assume that the signal length is an odd
	void DWT1D(double * inputSignal, int signalLength
			   double * lowCoeff, double * highCoeff) {
		//get the filter low and high and apply
		double * lowFilter = filter.getLowPassFilter();
		double * highFilter = filter.getHighPassFilter();

		//calculate length

		//get fitler
		//apply fitler to convolution kernel
		for(int i = 0; i<signalLength;i++) {
			double * filter = (i % 2 ! = 0) ? lowFilter : highFilter;
			transform.applyConvolution();
		}

	}
};