/*
 * SimpleMC.h
 *
 *  Created on: Dec 3, 2015
 *      Author: gergelyc
 */

#ifndef INCLUDE_SIMPLEMC_H_
#define INCLUDE_SIMPLEMC_H_

#include "PayOff.h"
#include "Vanilla.h"

double SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);

#endif /* INCLUDE_SIMPLEMC_H_ */
