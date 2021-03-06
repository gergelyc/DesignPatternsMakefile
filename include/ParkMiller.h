#ifndef PARKMILLER_H
#define PARKMILLER_H
#include "Random.h"

class ParkMiller
{
public:
	ParkMiller(long Seed = 1);

	long GetOneRandomInteger();
	void SetSeed(long Seed);

	static unsigned long Max();
	static unsigned long Min();

private:
	long Seed;
};

class RandomParkMiller : public RandomBase
{
public:
	RandomParkMiller(unsigned long Dimensionality, long Seed = 1);

	virtual RandomBase* clone() const;
	virtual void GetUniforms(std::vector<double>& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(long Seed);
	virtual void Reset();
	virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
	ParkMiller InnerGenerator;
	long InitialSeed;
	double Reciprocal;
};

#endif
