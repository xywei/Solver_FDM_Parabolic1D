/*
 * Parabolic_Eqn_1D.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Xiaoyu
 */

#ifndef PARABOLIC_EQN_1D_H_
#define PARABOLIC_EQN_1D_H_

#include <Eigen/Dense>
#include "Tridiagonal_Linear_Solver.h"

/*
 * The class Parabolic_Eqn_1D_Solver.
 * Domain = [0,1]X[0,t_F].
 * Initial condition is given by user.
 * Boundary condition is: u(0,t) = u(1,t) = 0.
 */

class Parabolic_Eqn_1D_Solver {
public:
	/**
	 * A constructor.
	 */
	Parabolic_Eqn_1D_Solver( ); /** Constructor */
	/**
	 * Set the initial condition.
	 * \param init The vector containing discrete initial condition.
	 * \return 0 If succeeded.
	 */
	int Set_Initial_Condition( Eigen::VectorXd & init );
	/**
	 * Set space step size.
	 * \param h Step size.
	 * \return 0 if secceeded.
	 */
	int Set_Delta_X( double h );
	/**
	 * Set time step size.
	 * \param h Step size.
	 * \return 0 if secceeded.
	 */
	int Set_Delta_T( double h );
	/**
	 * Set finalizing time.
	 * \param tf Final time.
	 * \return 0 If succeed;
	 */
	int Set_Finishing_T( double tf );
	/**
	 * Initialization of the solver.
	 *
	 */
	int Init(int m, int n, double T, Eigen::VectorXd init);
	/**
	 * Solve the problem using implicit method.
	 */
	int Solve_implicitly();
	/**
	 * Solve the problem using explicit method.
	 */
	int Solve_explicitly();
	/**
	 * Save the data in files.
	 * \param filename File to save.
	 * \return 0 If succeeded.
	 */
	int Save_Data( std::string filename );
//private:
	/**
	 * \brief Spatial step size.
	 */
	double dx;
	/**
	 * \brief Time step size.
	 */
	double dt;
	/**
	 * \brief Final time point.
	 */
	double t_F;
	/**
	 * \brief Number of points in spatial dimension.
	 */
	int N;
	/**
	 * \brief Number of points in time axis.
	 */
	int M;
	/**
	 * \brief U[m][n] is the value of u on (n+1)-th point at the (m)-th time step (because time starts at 0).
	 */
	Eigen::MatrixXd U;
	/**
	 * \brief Flag var, = 1 if the problem is ready to solve, otherwise = 0.
	 */
	int ready;
};

#endif /* PARABOLIC_EQN_1D_H_ */
