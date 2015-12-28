#include "PayOff.h"
#include <algorithm>

using namespace std;

PayOffCall::PayOffCall(double Strike_) : Strike{ Strike_ }
{
}

PayOff* PayOffCall::clone() const
{
	return new PayOffCall(*this);
}

double PayOffCall::operator()(double Spot) const
{
	return max(Spot - Strike, 0.0);
}

PayOffPut::PayOffPut(double Strike_) : Strike{ Strike_ }
{
}

PayOff* PayOffPut::clone() const
{
	return new PayOffPut(*this);
}

double PayOffPut::operator()(double Spot) const
{
	return max(Strike - Spot, 0.0);
}
