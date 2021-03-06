#pragma once
#include "nr3.h"
class shapequad
{
public:
	shapequad(int order, int type)
	{
		forder = order;
		ftype = type;
	}

	shapequad()
	{
	}
	~shapequad()
	{

	}

	void shapequad::shapes(MatDoub&psis, MatDoub &gradpsis, Doub xi, Doub eta)
	{
		switch (forder)
		{
		case 1:
			psis.resize(4, 1);
			gradpsis.resize(2, 4);
			psis[0][0] = ((1 - eta)*(1 - xi)) / 4.;
			psis[1][0] = ((1 - eta)*(1 + xi)) / 4.;
			psis[2][0] = ((1 + eta)*(1 + xi)) / 4.;
			psis[3][0] = ((1 + eta)*(1 - xi)) / 4.;

			gradpsis[0][0] = 1. / 4. *(-1. + eta);
			gradpsis[0][1] = (1. - eta) / 4.;
			gradpsis[0][2] = (1. + eta) / 4.;
			gradpsis[0][3] = 1. / 4. *(-1. - eta);

			gradpsis[1][0] = 1. / 4. * (-1. + xi);
			gradpsis[1][1] = 1. / 4. *(-1. - xi);
			gradpsis[1][2] = (1. + xi) / 4.;
			gradpsis[1][3] = (1. - xi) / 4.;
			break;
		case 2:
			psis.assign(8, 1, 0.0000);
			gradpsis.assign(2, 8, 0.000);

			psis[0][0] = 1. / 4. *(1. - eta) *(1. - xi)* (-1. - eta - xi);
			psis[1][0] = 1. / 4. *(1. - eta)* (1. + xi) *(-1. - eta + xi);
			psis[2][0] = 1. / 4.*(1. + eta) *(1. + xi) *(-1. + eta + xi);
			psis[3][0] = 1. / 4. *(1. + eta)* (1. - xi) *(-1. + eta - xi);
			psis[4][0] = 1. / 2. * (1. - eta) *(1 - xi *xi);
			psis[5][0] = 1. / 2. *(1. - eta *eta)* (1. + xi);
			psis[6][0] = 1. / 2. *(1. + eta)* (1. - xi *xi);
			psis[7][0] = 1. / 2. * (1. - eta *eta) * (1. - xi);


			gradpsis[0][0] = -((1 - eta)*(1 - xi)) / 4. - ((1 - eta)*(-1 - eta - xi)) / 4.;
			gradpsis[0][1] = ((1 - eta)*(1 + xi)) / 4. + ((1 - eta)*(-1 - eta + xi)) / 4.;
			gradpsis[0][2] = ((1 + eta)*(1 + xi)) / 4. + ((1 + eta)*(-1 + eta + xi)) / 4.;
			gradpsis[0][3] = -((1 + eta)*(1 - xi)) / 4. - ((1 + eta)*(-1 + eta - xi)) / 4.;
			gradpsis[0][4] = (-1 + eta)*xi;
			gradpsis[0][5] = (1 - eta*eta) / 2.;
			gradpsis[0][6] = (-1 - eta)*xi;
			gradpsis[0][7] = (-1 + pow(eta, 2)) / 2.;

			gradpsis[1][0] = -((1 - eta)*(1 - xi)) / 4. - ((1 - xi)*(-1 - eta - xi)) / 4.;
			gradpsis[1][1] = -((1 - eta)*(1 + xi)) / 4. - ((1 + xi)*(-1 - eta + xi)) / 4.;
			gradpsis[1][2] = ((1 + eta)*(1 + xi)) / 4. + ((1 + xi)*(-1 + eta + xi)) / 4.;
			gradpsis[1][3] = ((1 + eta)*(1 - xi)) / 4. + ((1 - xi)*(-1 + eta - xi)) / 4.;
			gradpsis[1][4] = (-1 + xi*xi) / 2.;
			gradpsis[1][5] = -eta*(1. + xi);
			gradpsis[1][6] = 1. / 2. *(1. - xi *xi);
			gradpsis[1][7] = -eta*(1. - xi);
			break;
		}

	}

	void shapequad::shapes1D(MatDoub&psis, MatDoub &gradpsis, Doub xi)
	{
		switch (forder)
		{
		case 1:
			psis.resize(2, 1);
			gradpsis.resize(2, 1);
			psis[0][0] = 0.5 - 0.5*xi;
			psis[1][0] = 0.5 * (1. + xi);

			gradpsis[0][0] = (1 - xi) / 2;
			gradpsis[1][0] = (1 + xi) / 2;
			break;
		case 2:
			psis.resize(3, 1);
			psis[0][0] = -0.5 * xi + 0.5 * xi*xi;
			psis[1][0] = 1. - 1. * xi *xi;
			psis[2][0] = 0.5 * xi * (1. + xi);


			//List(((-1 + xi)*xi) / 2., 1 - Power(xi, 2), (xi*(1 + xi)) / 2.)

			gradpsis.resize(3, 1);
			gradpsis[0][0] = -0.5 + xi;
			gradpsis[1][0] = -2.* xi;
			gradpsis[2][0] = 0.5 + xi;
			break;
		case 3:
			//{-0.0625 + 0.0625 xi + 0.5625 xi ^ 2 - 0.5625 xi ^ 3,
			//	0.5625 - 1.6875 xi - 0.5625 xi ^ 2 +
			//	1.6875 xi ^ 3, -1.6875 (0.333333 + xi) (1. + xi) (-1. + 1. xi),
			//	0.5625 (-0.333333 + xi) (0.333333 + xi) (1. + xi)}
			break;
		}

	}

	void pointsandweigths(MatDoub & pts)
	{
		if (forder == 1)
		{

		
		double co[9][3] = { { -0.774597, 0.774597, 0.308642 },{ 0., 0.774597, 0.493827 },{ 0.774597,
			0.774597, 0.308642 },{ -0.774597, 0., 0.493827 },{ 0., 0.,
			0.790123 },{ 0.774597, 0., 0.493827 },{ -0.774597, -0.774597,
			0.308642 },{ 0., -0.774597, 0.493827 },{ 0.774597, -0.774597,
			0.308642 } };
		pts.resize(9, 3);
		for (Int i = 0;i < 9; i++)
		{
			for (Int j = 0;j < 3;j++)
			{
				pts[i][j] = co[i][j];
			}
		}
		}
		else {

		double co[16][3] = { {-0.861136, 0.861136, 0.121003}, { -0.339981, 0.861136,
			0.226852 }, { 0.339981, 0.861136, 0.226852 }, { 0.861136, 0.861136,
			0.121003 }, { -0.861136, 0.339981, 0.226852 }, { -0.339981, 0.339981,
			0.425293 }, { 0.339981, 0.339981, 0.425293 }, { 0.861136, 0.339981,
			0.226852 }, { -0.861136, -0.339981, 0.226852 }, { -0.339981, -0.339981,
			0.425293 }, { 0.339981, -0.339981, 0.425293 }, { 0.861136, -0.339981,
			0.226852 }, { -0.861136, -0.861136, 0.121003 }, { -0.339981, -0.861136,
			0.226852 }, { 0.339981, -0.861136, 0.226852 }, { 0.861136, -0.861136,
			0.121003 } };
		pts.resize(16, 3);
		for (Int i = 0;i < 16; i++)
		{
			for (Int j = 0;j < 3;j++)
			{
				pts[i][j] = co[i][j];
			}
		}
		}
	}

	void pointsandweigths1D(MatDoub & pts)
	{
		//double co[4][2] = { { -0.861136, 0.347855 },{ -0.339981, 0.652145 },{ 0.339981,
	//		0.652145 },{ 0.861136, 0.347855 } };

		double co[7][2] = { {-0.949108, 0.129485}, { -0.741531, 0.279705 }, { -0.405845,
			0.38183 }, { 0., 0.417959 }, { 0.405845, 0.38183 }, { 0.741531,
			0.279705 }, { 0.949108, 0.129485 } };

		pts.resize(7, 2);
		for (Int i = 0;i < pts.nrows(); i++)
		{
			for (Int j = 0;j < 2;j++)
			{
				pts[i][j] = co[i][j];
			}
		}
	}



protected:
	int forder;
	int ftype;

};


