#pragma once
#include "nr3.h"
#include <math.h>
#include <cmath>
#include "elastoplasticbase.h"


class vonmises : elastoplasticbase
{
public:
	vonmises(Doub young,Doub nu, Doub sigy);
	vonmises();
	~vonmises();

	void closestpointproj(TensorDoub epst, TensorDoub epsp, TensorDoub & projstress, TensorDoub & projstrain, MatDoub & Dep, Doub & projgamma);
	Doub yield(Doub J2);
	MatDoub GetElasticMatrix();
	MatDoub GetInverseElasticMatrix();
	MatDoub F1HWCylVonMises(Doub xisol, Doub rho, Doub betasol);
	MatDoub HW(MatDoub sig);
	MatDoub stressrecosntruction(MatDoub val, MatDoub vec);
	MatDoub dadsig(TensorDoub sigprojvoigt);
	MatDoub P();
	inline void setup(Doub young, Doub nu, Doub sigy) {
		fyoung = young;
		fsigy = sigy;
		fnu = nu;
		fG = young / (2.* (1. + nu));
		fK = young / (3.* (1. - 2.* nu));
	}

	inline void GetElasticParameters(Doub young, Doub nu, Doub sigy, Doub K, Doub G)
	{
		young = fyoung;
		nu = fnu;
		sigy = fsigy;
		K = fK;
		G = fG;
	}
	inline void updateatributes(NRvector<MatDoub> mult)
	{
		fyoung0 = fyoung;
		fnu0 = fnu;
		fsigy0 = fsigy;
		Doub newyoung = fyoung + mult[0][0][0]*fyoung;
		setup(newyoung, fnu, fnu);
	}
	inline void restoreoriginalatributes()
	{
		setup(fyoung0, fnu0, fsigy0);
	}

	Doub fyoung;
	Doub fnu;
	Doub fyoung0;
	Doub fnu0;
private:
	Doub fsigy0;
	Doub fsigy;
	Doub fK;
	Doub fG;
};

