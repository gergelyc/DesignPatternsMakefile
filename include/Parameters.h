#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "Wrapper.h"

class ParametersInner
{
public:
	ParametersInner(){}
	virtual ParametersInner* clone() const = 0;
	virtual ~ParametersInner(){}

	virtual double Integral(double time1, double time2) const = 0;
	virtual double IntegralSquare(double time1, double time2) const = 0;

private:
};

class Parameters
{
public:
	Parameters(const ParametersInner& innerObject);

	inline double Integral(double time1, double time2) const;
	inline double IntegralSquare(double time1, double time2) const;

	double Mean(double time1, double time2) const;
	double RootMeanSquare(double time1, double time2) const;

private:
	Wrapper<ParametersInner> InnerObject;
};

inline double Parameters::Integral(double time1, double time2) const
{
	return InnerObject->Integral(time1, time2);
}

inline double Parameters::IntegralSquare(double time1, double time2) const
{
	return InnerObject->IntegralSquare(time1, time2);
}

class ParametersConstant : public ParametersInner
{
public:
	ParametersConstant(double constant);
	virtual ParametersInner* clone() const;

	virtual double Integral(double time1, double time2) const;
	virtual double IntegralSquare(double time1, double time2) const;

private:
	double Constant;
	double ConstantSquare;
};

#endif
