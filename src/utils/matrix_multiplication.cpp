#include "../../include/utils/matrix_multiplication.hpp"

utils::matrix_multiplication::matrix_multiplication(matrix *a,matrix *b)	{
	this->a = a;
	this->b = b;

	if(a->get_cols() != b->get_rows())	{
		cerr << a->get_cols() << " not qual to " << b->get_rows() << endl;
		assert(false);
	}

	this->res = new matrix(a->get_rows(),b->get_cols(),false);
}

matrix *utils::matrix_multiplication::execute()	{
	for(int i = 0; i < this->res->get_rows(); i++)	{
		for(int j = 0; j < this->res->get_cols(); j++)	{
			double v = 0.0;
			for(int k = 0; k < this->a->get_cols(); k++)	{
				v += this->a->get_value(i,k) * this->b->get_value(k,j);
			}
			this->res->set_value(i,j,v);
		}
	}
	return this->res;
}