#ifndef VANILLA_H
#define VANILLA_H
#include "PayOff.h"
#include "PayOffBridge.h"

class VanillaOption
{
public:
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
	double GetExpiry() const
	{
		return Expiry;
	}
	double OptionPayOff(double Spot) const
	{
		return ThePayOff(Spot);
	}

private:
	double Expiry;
	PayOffBridge ThePayOff;
};

#endif
