#include <iostream>
#include "SimpleMC.h"
#include "DoubleDigital.h"
using namespace std;

int main()
{
	double Expiry;
	double LowerLevel, UpperLevel;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter lower level\n";
	cin >> LowerLevel;

	cout << "\nEnter upper level\n";
	cin >> UpperLevel;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOffDoubleDigital payOffDoubleDigital{ LowerLevel, UpperLevel };
	VanillaOption theOption(payOffDoubleDigital, Expiry);

	double result = SimpleMonteCarlo(theOption, Spot, Vol, r, NumberOfPaths);

	cout << "the price is " << result << endl;
}
