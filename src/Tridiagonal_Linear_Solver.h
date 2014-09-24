/*
 * Tridiagonal_Linear_Solver.h
 *
 *  Created on: Sep 24, 2014
 *      Author: xweiaf
 */

#ifndef TRIDIAGONAL_LINEAR_SOLVER_H_
#define TRIDIAGONAL_LINEAR_SOLVER_H_

#include "Tridiagonal_Matrix.h"
#include "Eigen/Dense"

/**
 *\brief Tridiagonal_Linear_Solver is a class handling problems of solving a tridiagonal linear system Ax=b.
 */
class Tridiagonal_Linear_Solver{
public:
	/**
	 * A constructor (vectors storing RHS and solution are needed as parameters).
	 */
	Tridiagonal_Linear_Solver(Eigen::VectorXd & rhs, Eigen::VectorXd & solu);
	/**
	 * Set up the right hand side vector.
	 * @param rhs The vector b.
	 * @return 0 If succeeded.
	 */
	int setA(double l, double d, double u);
	/**
	 * Solve the system.
	 * @return Reference to the solution vector x.
	 */
	Eigen::VectorXd & solve();

private:
	/**
	 * Size of the system.
	 */
	int N;
	/**
	 * Right hand side of the equation.
	 */
	Eigen::VectorXd & b;
	/**
	 * Solution of the equation.
	 */
	Eigen::VectorXd & x;
	/**
	 * Coefficient matrix (tridiagonal).
	 */
	Tridiagonal_Matrix A;
};




#endif /* TRIDIAGONAL_LINEAR_SOLVER_H_ */
