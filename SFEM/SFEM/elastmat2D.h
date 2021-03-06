#pragma once

#include "shapequad.h"
class elastmat2D : shapequad
{
public:
	elastmat2D(Doub young, Doub nu, Doub thickness, Doub bodyforce, Int planestress, Int order);
	elastmat2D(Doub young, Doub nu, Doub thickness, Doub bodyforce, Int planestress, Int order, MatDoub  HHAT);
	elastmat2D();
	~elastmat2D();

	void Contribute(MatDoub &ek, MatDoub &ef, Doub xi, Doub eta, Doub w, MatDoub elcoords);
	void CacStiff(MatDoub &ek, MatDoub &ef, const MatDoub  &elcoords);
	void Assemble(MatDoub &KG, MatDoub &FG, const vector<vector< vector<Doub > > > &allcoords, const MatDoub &meshnodes, const MatInt meshtopology);
	void assembleBandN(MatDoub &B, MatDoub &N, const MatDoub &psis, const MatDoub &GradPhi);
	void assembleConstitutiveMatrix(MatDoub &C, Doub mult);
	void GetElCoords(vector<vector< vector<Doub > > > allcoords, Int el, MatDoub & elcoords);
	void DirichletBC(MatDoub &KG, MatDoub & FG, vector<int> ids, Int  dir, Int val);
	void ContributeLineNewan(MatDoub &KG, MatDoub & FG, vector<int> ids, Int  dir, Int val);
	void SolPt(const vector<vector< vector<Doub > > > &allcoords,
		const MatInt &meshtopology, const Int &el, const  MatDoub &solG, const Doub &xi, const Doub &eta, MatDoub &xycoords, MatDoub &sol);

	void PostProcess(const vector<vector< vector<Doub > > > &allcoords,
		const MatInt &meshtopology, const MatDoub & nodalsol, vector<vector<double>> &solx, vector<vector<double>> &soly);
	void PostProcess(const vector<vector< vector<Doub > > > &allcoords,
		const MatInt &meshtopology, const MatDoub & nodalsol, vector<vector<double>> &sol);


private:
	Doub fyoung;
	Doub fnu;
	Doub fbodyforce;
	Int fplanestress;
	Doub fthickness;
	Int fOrder;
public:
	MatDoub fHHAT;
	MatDoub fhhatvel;
};

