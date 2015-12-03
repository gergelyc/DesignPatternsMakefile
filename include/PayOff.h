/*
 * PayOff.h
 *
 *  Created on: Dec 3, 2015
 *      Author: gergelyc
 */

#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
	enum OptionType {call, put};
	PayOff(double Strike_, OptionType TheOptionsType_);
	double operator()(double Spot) const;

private:
	OptionType TheOptionsType;
	double Strike;
};


#endif /* INCLUDE_PAYOFF_H_ */
