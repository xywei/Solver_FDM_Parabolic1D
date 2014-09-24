// Name        : Tridiagonal_Matrix.cpp
// Author      : Xiaoyu WEI
// Version     :
// Copyright   : Your copyright notice
// Description : Realization of Tridiagonal_Matrix class
//============================================================================

#include "Tridiagonal_Matrix.h"

Tridiagonal_Matrix::Tridiagonal_Matrix()
{
	N = 0;
}

Tridiagonal_Matrix::Tridiagonal_Matrix( int n )
{
	N = n;
	diag.resize(n,1);
	upperdiag.resize(n-1,1);
	lowerdiag.resize(n-1,1);
}

int Tridiagonal_Matrix::resize(int n)
{
	if(n>=1)
	{
		N = n;
		diag.resize(n,1);
		upperdiag.resize(n-1,1);
		lowerdiag.resize(n-1,1);
	}
	else if(n==0)
	{
		N = 0;
		diag.resize(0,1);
		upperdiag.resize(0,1);
		lowerdiag.resize(0,1);
	}
	else
		return 1;

	return 0;
}

double Tridiagonal_Matrix::val(int m, int n)
{
	if( (m<=n+1)&&(n<=m+1) )
	{
		switch(m-n)
		{
		case -1: /** Upper sub-diagonal line */
			return upperdiag(m);
		case 0: /** Diagonal line */
			return diag(m);
		case 1: /** Lower sub-diagonal line */
			return lowerdiag(n);
		}
	}
	else
	{
		std::cout << "Error: Ilegal input of index for val(int, int)." << std::endl;
		return 1;
	}
	return 0;
}

int Tridiagonal_Matrix::setval(int m, int n, double v)
{
	if( (m<=n+1)&&(n<=m+1) )
	{
		switch(m-n)
		{
		case -1: /** Upper sub-diagonal line */
			upperdiag(m) = v;
			break;
		case 0: /** Diagonal line */
			diag(m) = v;
			break;
		case 1: /** Lower sub-diagonal line */
			lowerdiag(n) = v;
			break;
		}
	}
	else
	{
		std::cout << "Error: Illegal input of index for setval(int, int, double)." << std::endl;
		return 1;
	}
	return 0;
}

int Tridiagonal_Matrix::setdiag(int k, double v)
{
	if( k<-1 || k>1 )
	{
		std::cout << "Error: Illegal input of index for setdiag(int, double)." << std::endl;
		return 1;
	}
	else
	{
		switch(k)
		{
		case 1:
			for(int i=0;i<N-1;i++) upperdiag(i) = v;
			break;
		case 0:
			for(int i=0;i<N;i++) diag(i) = v;
			break;
		case -1:
			for(int i=0;i<N-1;i++) lowerdiag(i) = v;
			break;
		}
	}
	return 0;
}
