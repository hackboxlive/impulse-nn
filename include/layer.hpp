#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <iostream>
#include <vector>
#include "neuron.hpp"

using namespace std;

class layer	{

	public:
		layer(int size);

	private:
		int size;
		vector<neuron *> neurons;
};
#endif