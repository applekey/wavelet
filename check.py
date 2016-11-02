import pywt
inputSignal = [1] * 64
(a, d) = pywt.dwt(inputSignal, 'bior4.4', 'zero')
print len(a)
print len(d)
