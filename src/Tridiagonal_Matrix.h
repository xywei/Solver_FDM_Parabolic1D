 /**
 * Tridiagonal_Matrix.h
 *
 *  Created on: Sep 24, 2014
 *      Author: Xiaoyu
 */

#ifndef TRIDIAGONAL_MATRIX_H_
#define TRIDIAGONAL_MATRIX_H_

#include <Eigen/Dense>

/**
 * \brief Tridiagonal_Matrix is the class for storing tridiagonal matrices.
 */
class Tridiagonal_Matrix{
public:
	/**
	 * A constructor.
	 */
	Tridiagonal_Matrix();
	/**
	 * Another constructor.
	 * @param n Size of the matrix.
	 */
	Tridiagonal_Matrix(int n);
	/**
	 * Reading value of an element.
	 * @param m Row index.
	 * @param n Column index.
	 * @return The value of [m][n].
	 */
	double val(int m, int n);
	/**
	 * Set value of an element.
	 * @param m Row index.
	 * @param n Column index.
	 * @return 0 If succeeded.
	 */
	int setval(int m, int n, double v);
	/**
	 * Set value of elements on a (sub)diagonal line.
	 * @param k 0, 1 or -1, indicating which line to set.
	 * @param b Value to be set.
	 * @return 0 If succeeded.
	 */
	int setdiag(int k, double v);
	/**
	 * Reset the size of the the matrix (data deprecated).
	 * @param n New size of the matrix.
	 * @return 0 if secceeded.
	 */
	int resize(int n);
private:
	/**
	 * \brief Size of the matrix.
	 */
	int N;
	/**
	 * \brief The diagonal elements.
	 */
	Eigen::VectorXd diag;
	/**
	 * \brief The upper subdiagonal elements.
	 */
	Eigen::VectorXd upperdiag;
	/**
	 * \brief The lower subdiagonal elements.
	 */
	Eigen::VectorXd lowerdiag;
};


#endif
