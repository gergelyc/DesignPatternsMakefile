#ifndef VANILLA_H
#define VANILLA_H
#include "PayOff.h"
#include "Wrapper.h"

class VanillaOption
{
public:
	VanillaOption(const Wrapper<PayOff>& ThePayOff_, double Expiry_);
	double GetExpiry() const
	{
		return Expiry;
	}
	double OptionPayOff(double Spot) const
	{
		return ThePayOff->operator ()(Spot);
	}

private:
	double Expiry;
	Wrapper<PayOff> ThePayOff;
};

#endif
