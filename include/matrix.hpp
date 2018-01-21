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

		void set_value(int r,int c,int v);

		double get_value(int r,int c);

		void print_mat();

		double get_random_number();

	private:
		int rows;
		int cols;
		vector<vector<double> > mat;
};

#endif