#include "Parabolic_Eqn_1D.h"
#include <iostream>
#include <fstream>

Parabolic_Eqn_1D_Solver::Parabolic_Eqn_1D_Solver( )
{
	M = 0;
	N = 0;
	ready = 0;
	dx = 0.0;
	dt = 0.0;
	t_F = 0.0;
}

int Parabolic_Eqn_1D_Solver::Set_Initial_Condition( Eigen::VectorXd & init )
{
	if(M==0)
	{
		std::cout << "Please set dt, M and t_F first." << std::endl;
		return 1;
	}
	int n = init.size();
	N = n;
	U.resize(M, N);
	for(int i=0;i<N;i++)
		U(0, i) = init(i);

	return 0;
}

int Parabolic_Eqn_1D_Solver::Set_Delta_X(double h)
{
	dx = h;
	return 0;
}

int Parabolic_Eqn_1D_Solver::Set_Delta_T(double h)
{
	dt = h;
	return 0;
}

int Parabolic_Eqn_1D_Solver::Set_Finishing_T(double tf)
{
	t_F = tf;
	return 0;
}

int Parabolic_Eqn_1D_Solver::Init(int m, int n, double T, Eigen::VectorXd init)
{
	Set_Finishing_T(T);
	M = m;
	N = n;
	Set_Delta_T(T/(M-1));
	Set_Delta_X(1.0/(N-1));
	Set_Initial_Condition(init);
	ready = 1;
	return 0;
}

int Parabolic_Eqn_1D_Solver::Solve_explicitly()
{
	double gamma = dt / (dx * dx);
	double nu = 1.0 - 2.0 * gamma;
	for(int j=0;j<M-1;j++)
	{
		U(j+1,0) = 0.0;
		U(j+1,N-1) = 0.0;
		for(int k=1;k<N-1;k++)
		{
			U(j+1, k) = nu * U(j,k) + gamma * (U(j,k-1) + U(j,k+1));
		}
	}
	return 0;
}

int Parabolic_Eqn_1D_Solver::Solve_implicitly()
{
	double gamma = dt / (dx * dx);
	Eigen::VectorXd b, x;
	b.resize(N,1);
	x.resize(N,1);
	for(int i=0;i<M-1;i++)
	{
		for(int k=0;k<N;k++)
			b(k) = U(i,k);
		Tridiagonal_Linear_Solver S(b, x);
		S.setA(-gamma, 1.0 + 2.0 * gamma, -gamma);
		S.solve();
		U.row(i+1) = x;
	}
	return 0;
}

int Parabolic_Eqn_1D_Solver::Save_Data(std::string filename)
{
	std::ofstream myfile;
	myfile.open(filename.c_str());
	myfile << "# M = " << M << ", N = " << N << ", t_F = " << t_F << std::endl;
	myfile << "# dx = " << dx << ", dt = " << dt << std::endl;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			myfile << dt * (double)i << '\t';
			myfile << dx * (double)j << '\t';
			myfile << U(i,j) << std::endl;
		}
		myfile << std::endl;
	}
	myfile.close();
	return 0;
}
