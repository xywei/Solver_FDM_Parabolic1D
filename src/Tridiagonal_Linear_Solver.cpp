/*
 * Tridiagonal_Linear_Solver.cpp
 *
 *  Created on: Sep 24, 2014
 *      Author: xweiaf
 */

#include "Tridiagonal_Linear_Solver.h"

Tridiagonal_Linear_Solver::Tridiagonal_Linear_Solver(Eigen::VectorXd & rhs, Eigen::VectorXd & solu)
: b(rhs)
, x(solu)
{
	N = rhs.size();
}

int Tridiagonal_Linear_Solver::setA(double l, double d, double u)
{
	A.resize(N);
	A.setdiag(-1, l);
	A.setdiag(0, d);
	A.setdiag(1, u);
	return 0;
}

Eigen::VectorXd & Tridiagonal_Linear_Solver::solve()
{
	/**
	 * Using Thomas' algorithm to solve the system.
	 */
	double ratio;
	x.resize(N);
	x = b;
	/**
	 * First step: Reduce the system to upper triangular.
	 */
	for(int i=0;i<N-1;i++)
	{
		ratio = - A.val(i+1,i) / A.val(i,i);
		// A.setval(i+1, i, A.val(i+1,i) + ratio * A.val(i,i) );
		A.setval(i+1, i+1, A.val(i+1,i+1) + ratio * A.val(i,i+1) );
		x(i+1) = x(i+1) + ratio * x(i);
	}
	/**
	 * Sencond step: Back substitution.
	 */
	for(int i=N-1;i>0;i--)
	{
		ratio = - A.val(i-1,i) / A.val(i,i);
		// A.setval(i-1, i, A.val(i-1,i) + ratio * A.val(i,i));
		x(i-1) = x(i-1) + ratio * x(i);

		ratio = 1.0 / A.val(i,i);
		// A.setval(i, i, ratio * A.val(i,i));
		x(i) = ratio * x(i);

		if(i==1)
		{
			x(0) = x(0) / A.val(0,0);
		}
	}

	return x;
}



