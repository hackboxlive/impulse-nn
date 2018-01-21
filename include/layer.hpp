#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include <vector>
#include "neuron.hpp"
#include "matrix.hpp"

using namespace std;

class layer	{

	public:
		layer(int size);
		void set_value(int pos, double v);
		matrix *vector_to_matrix();
		matrix *vector_to_activated_matrix();
		matrix *vector_to_derived_matrix();

	private:
		int size;
		vector<neuron *> neurons;
};
#endif