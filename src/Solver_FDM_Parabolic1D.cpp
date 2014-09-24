//============================================================================
// Name        : Solver_FDM_Parabolic1D.cpp
// Author      : Xiaoyu WEI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Eigen/Dense>
#include "Tridiagonal_Linear_Solver.h"

using namespace std;
using namespace Eigen;

int main() {
	Eigen::VectorXd x;
	VectorXd b(4);
	b << 3,4,4,3;
	std::cout << b << std::endl;
	Tridiagonal_Linear_Solver S(b, x);
	S.setA(1.0, 2.0, 1.0);
	S.solve();
	std::cout << x << std::endl;
	return 0;
}
