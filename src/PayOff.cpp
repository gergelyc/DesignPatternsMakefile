/*
 * PayOff.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: gergelyc
 */

#include "PayOff.h"
#include <algorithm>

using namespace std;

PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
	: TheOptionsType{ TheOptionsType_ }, Strike{ Strike_ }       
{
}

double PayOff::operator()(double Spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return max(Spot - Strike, 0.0);
	case put:
		return max(Strike - Spot, 0.0);
	default:
		throw("Unknown option type found.");
	}
}


