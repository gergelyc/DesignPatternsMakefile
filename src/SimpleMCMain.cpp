#include <iostream>
#include "SimpleMC.h"

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	int PutOrCall;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << endl << "Put (0) or call (1): " << endl;
	cin >> PutOrCall;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOff* thePayOffPtr;

	if (PutOrCall)
	{
		thePayOffPtr = new PayOffPut(Strike);
	}
	else
	{
		thePayOffPtr = new PayOffCall(Strike);
	}

	double result = SimpleMonteCarlo(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);

	delete thePayOffPtr;

	cout << "the price is " << result << endl;
}
