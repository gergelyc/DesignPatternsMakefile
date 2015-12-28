#ifndef PARKMILLER_H
#define PARKMILLER_H
#include "Random.h"

class ParkMiller
{
public:
	ParkMiller(unsigned long Seed = 1);

	long GetOneRandomInteger();
	void SetSeed(unsigned long Seed);

	static unsigned long Max();
	static unsigned long Min();

private:
	unsigned long Seed;
};

class RandomParkMiller : public RandomBase
{
public:
	RandomParkMiller(unsigned long Dimensionality, unsigned long Seed = 1);

	virtual RandomBase* clone() const;
	virtual void GetUniforms(std::vector<double>& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void Reset();
	virtual void ResetDimensionality(unsigned long NewDimensionality);

private:
	ParkMiller InnerGenerator;
	unsigned long InitialSeed;
	double Reciprocal;
};

#endif