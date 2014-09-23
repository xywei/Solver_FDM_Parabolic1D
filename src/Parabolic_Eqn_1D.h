/*
 * Parabolic_Eqn_1D.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Xiaoyu
 */

#ifndef PARABOLIC_EQN_1D_H_
#define PARABOLIC_EQN_1D_H_

#include <vector>
#include <string>

/**
 * The class Parabolic_Eqn_1D_Solver.
 * Domain = [0,1]X[0,+\infty].
 */

class Parabolic_Eqn_1D_Solver {
public:
	Parabolic_Eqn_1D_Solver( ); /** Constructor */
	int Set_Initial_Condition();
	int Set_Delta_X( double );
	int Set_Delta_T( double );
	int Set_Finishing_T( double );
	int Step_Init();
	int Step_Forward_implicitly();
	int Step_Forward_explicitly();
	int Save_Data( std::string );
private:
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
	 * \brief U[m][n] is the value of u on n-th point at the (m-1)-th time step (because time starts at 0).
	 */
	std::vector<std::vector<double>> U;
};



#endif /* PARABOLIC_EQN_1D_H_ */
