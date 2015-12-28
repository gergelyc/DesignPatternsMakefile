#include "Vanilla.h"

VanillaOption::VanillaOption(const Wrapper<PayOff>& ThePayOff_, double Expiry_)
	: Expiry{ Expiry_ }, ThePayOff{ ThePayOff_ }
{
}
