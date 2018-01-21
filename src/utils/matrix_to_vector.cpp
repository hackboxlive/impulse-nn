#include "../../include/utils/matrix_to_vector.hpp"

utils::matrix_to_vector::matrix_to_vector(matrix *a)	{
	this->a = a;
}

vector<double> *utils::matrix_to_vector::execute()	{
	vector<double> res;
	for(int i = 0; i < this->a->get_rows(); i++)	{
		for(int j = 0; j < this->a->get_cols(); j++)	{
			res.push_back(this->a->get_value(i,j));
		}
	}
	return res;
}