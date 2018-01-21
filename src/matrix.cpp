#include "../include/matrix.hpp"

using namespace std;

double matrix::get_random_number()	{
	random_device r;
	mt19937 gen(r());
	uniform_real_distribution<> dis(0, 1);

	return dis(gen);
}

void matrix::print_mat()	{
	for(int i = 0; i < this->rows; i++)	{
		for(int j = 0; j < this->cols; j++)	{
			cout << this->mat[i][j] << " ";
		}
		cout << endl;
	}
}

matrix::matrix(int r,int c,bool rd)	{
	this->rows = r;
	this->cols = c;
	if(rd == true)	{
		for(int i = 0; i < r; i++)	{
			vector<double> vals;
			for(int j = 0; j < c; j++)	{
				vals.push_back(this->get_random_number());
			}
			this->mat.push_back(vals);
		}
	}
	else	{
		for(int i = 0; i < r; i++)	{
			vector<double> vals;
			for(int j = 0; j < c; j++)	{
				vals.push_back(0);
			}
			this->mat.push_back(vals);
		}
	}
}

matrix *matrix::transpose()	{
	matrix * m = new matrix(this->cols, this->rows, false);
	for(int i = 0; i < this->rows; i++)	{
		for(int j = 0; j < this->cols; j++)	{
			m->mat[j][i] = this->mat[i][j];
		}
	}
	return m;
}