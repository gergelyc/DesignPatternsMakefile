#include "Vanilla.h"

VanillaOption::VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_)
	: Expiry{ Expiry_ }, ThePayOff{ ThePayOff_ }
{
}
