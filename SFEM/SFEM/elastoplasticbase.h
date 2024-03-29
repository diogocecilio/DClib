#pragma once
#include "nr3.h"
class elastoplasticbase
{
public:

	~elastoplasticbase();

	virtual void closestpointproj(TensorDoub epst, TensorDoub epsp, TensorDoub & projstress, TensorDoub & projstrain, MatDoub & Dep, Doub & projgamma)=0;
	//virtual Doub yield(Doub J2)=0;
	virtual MatDoub GetElasticMatrix()=0;
	virtual MatDoub GetInverseElasticMatrix()=0;
	//virtual MatDoub F1HWCylVonMises(Doub xisol, Doub rho, Doub betasol)=0;
	virtual MatDoub HW(MatDoub sig)=0;
	virtual MatDoub stressrecosntruction(MatDoub val, MatDoub vec)=0;
	virtual MatDoub dadsig(TensorDoub sigprojvoigt)=0;
	virtual MatDoub P()=0;
};

