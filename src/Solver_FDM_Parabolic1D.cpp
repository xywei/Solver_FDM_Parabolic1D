//============================================================================
// Name        : Solver_FDM_Parabolic1D.cpp
// Author      : Xiaoyu WEI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Eigen/Dense>
#include "Parabolic_Eqn_1D.h"

using namespace std;
using namespace Eigen;

int main() {
	const int M = 101;
	const int N = 21;
	const double T = 1;
	VectorXd IC(N);
	for(int i=0;i<N/2;i++)
	{
		IC(i) = 2.0 * i / (N-1);
	}
	for(int i=N/2;i<N;i++)
	{
		IC(i) = 2.0 - 2.0 * i / (N-1);
	}
	Parabolic_Eqn_1D_Solver S1, S2;
	S1.Init(M, N, T, IC);
	S2.Init(M, N, T, IC);
	S1.Solve_explicitly();
	S2.Solve_implicitly();
	S1.Save_Data("S1.dat");
	S2.Save_Data("S2.dat");
	Parabolic_Eqn_1D_Solver Er;
	Er.Init(M, N, T, IC);
	Er.U = S1.U - S2.U;
	Er.Save_Data("Er.dat");
	cout << "Done." << endl;
	return 0;
}
