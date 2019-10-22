#include <iostream>
#include <cmath>
#include "UTNormals.h"
#include "UTRandom1.h"


using namespace std;

double SimpleMonteCarlo1(double Expiry,
	double Strike,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths)
{

	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*std::exp(r*Expiry + itoCorrection);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp(rootVariance*thisGaussian);
		double thisPayoff = thisSpot - Strike;
		thisPayoff = thisPayoff >0 ? thisPayoff : 0;
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r*Expiry);
	return mean;
}

double blackSholesCall(double Expiry,
	double Strike,
	double Spot,
	double Vol,
	double r)
{

	double variance = Vol*Vol*Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;

	double movedSpot = Spot*std::exp(r*Expiry + itoCorrection);
	double thisSpot;

	double thisGaussian = GetOneGaussianByBoxMuller();
    thisSpot = movedSpot*exp(rootVariance*thisGaussian);
    double d1 = (log(thisSpot/Strike) + r*Expiry - itoCorrection)/rootVariance;
    double d2 = d1-rootVariance; 
    double V = thisSpot*CumulativeNormal(d1) - Strike*exp(-r*Expiry)*CumulativeNormal(d2);
    return V;
}

int main()
{

	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

    cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	double result1 = SimpleMonteCarlo1(Expiry,
		Strike,
		Spot,
		Vol,
		r,
		NumberOfPaths);

    double result2 = blackSholesCall(
        Expiry,
		Strike,
		Spot,
		Vol,
		r
    );

	cout << "the price is " << result1 << "\n";

    cout << "the price is " << result2 << "\n";

	double tmp;
	cin >> tmp;

	return 0;
}