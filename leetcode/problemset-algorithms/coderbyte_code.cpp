#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
using namespace std;

double approxPi(int nSamples) {
  int nPointsInCircle = 0;
  double pointX, pointY;

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);

  uniform_real_distribution<double> distribution(0.0,1.0);

  for(int i = 0; i<nSamples; i++) {
    pointX = distribution(generator);
    pointY = distribution(generator);
    if(pointX*pointX + pointY*pointY <= 1.0) {
      nPointsInCircle++;
    }
  }
  double sPi = (4.0 * nPointsInCircle)/nSamples;
  return sPi;
}

int main() {
  int nSamples = 10000, nCount = 10;
  double sumXi = 0.0, sumXi2 = 0.0, sPi;
  for(int i = 0; i<nCount; i++) {
    sPi     = approxPi(nSamples);
    sumXi  += sPi;
    sumXi2 += (sPi*sPi);
  }
  double mean     = sumXi/nCount;
  double variance = sumXi2/nCount - (mean*mean);
  double stdDeviation = sqrt(variance);
  cout<<"mean: "<<mean<<" standard deviation: "<<stdDeviation<<"\n";
  return 0;
}
