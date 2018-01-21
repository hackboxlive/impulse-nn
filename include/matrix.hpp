#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <random>

using namespace std;

class matrix	{

	public:
		matrix(int r,int c,bool rd);

		matrix *transpose();

		void set_value(int r,int c,double v)	{
			this->mat[r][c] = v;
		}

		double get_value(int r,int c)	{
			return this->mat[r][c];
		}

		void print_mat();

		double get_random_number();

		int get_rows()	{
			return this->rows;
		}

		int get_cols()	{
			return this->cols;
		}

	private:
		int rows;
		int cols;
		vector<vector<double> > mat;
};

#endif