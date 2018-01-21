#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <iostream>
#include "matrix.hpp"
#include "layer.hpp"

using namespace std;

class network	{

	public:

		network(vector<int> topology);
		void set_input(vector<double> input);
		void print_network();

	private:
		int size;

		vector<int> topology;
		vector<layer *> layers;
		vector<matrix *> weights;
		vector<double> input;
};
#endif