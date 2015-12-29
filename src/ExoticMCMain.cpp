#include <iostream>
#include "SimpleMC.h"
#include "DoubleDigital.h"
#include "ConvergenceTable.h"
#include "ParkMiller.h"
#include "AntiThetic.h"
#include "PathDependentAsian.h"
#include "ExoticBSEngine.h"

using namespace std;

int main()
{
	double Expiry;
	double LowerLevel, UpperLevel;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	unsigned long NumberOfDates;

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

	cout << "\nNumber of dates\n";
	cin >> NumberOfDates;

	vector<double> LookAtTimes(NumberOfDates);
	for (unsigned long i = 0; i < NumberOfDates; i++)
	{
		cout << "Look at date " << i << ": ";
		cin >> LookAtTimes[i];
	}

	//set up path dependent option
	PayOffDoubleDigital payOffDoubleDigital{ LowerLevel, UpperLevel };
	PathDependentAsian TheAsianDoubleDigital(LookAtTimes, Expiry, payOffDoubleDigital);

	//set up exotic engine
	ParametersConstant VolParam{ Vol };
	ParametersConstant rParam{ r };
	ParametersConstant dParam{ 0.0 };

	RandomParkMiller ParkMillerGenerator(1);
	AntiThetic generator(ParkMillerGenerator);

	ExoticBSEngine TheBSEngine(TheAsianDoubleDigital,
		rParam,
		dParam,
		VolParam,
		generator,
		Spot);

	//set up statistics gatherer
	StatisticsMean gathererMean;
	ConvergenceTable gathererMeanConvTable(gathererMean);

	//run simulation
	TheBSEngine.DoSimulation(gathererMeanConvTable, NumberOfPaths);
	vector<vector<double>> results = gathererMeanConvTable.GetResultSoFar();

	cout << "For the double digital the results are:" << endl;

	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
		cout << endl;
	}
}
