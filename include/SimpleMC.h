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
#include "Parameters.h"
#include "MCStatistics.h"

void SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	Parameters Vol,
	Parameters r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer);

#endif /* INCLUDE_SIMPLEMC_H_ */
