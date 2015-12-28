#include "MCStatistics.h"

StatisticsMean::StatisticsMean()
	: RunningSum{ 0.0 }, PathsDone{ 0UL }
{
}

void StatisticsMean::DumpOneResult(double result)
{
	RunningSum += result;
	PathsDone++;
}

std::vector<std::vector<double>> StatisticsMean::GetResultSoFar() const
{
	std::vector<std::vector<double>> Results{ 1 };
	Results[0].resize(1);
	Results[0][0] = RunningSum / PathsDone;
	return Results;
}

StatisticsMC* StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}
