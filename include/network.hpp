#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <iostream>
#include <vector>

#include "matrix.hpp"
#include "layer.hpp"
#include "utils/matrix_multiplication.hpp"

using namespace std;

class network	{

	public:

		network(vector<int> topology);
		void set_input(vector<double> input);
		void print_network();
		void feed_forward();
		void set_errors();

		void set_target(vector<double> target)	{
			this->target = target;
		}

		matrix *get_neuron_matrix(int id)	{
			return this->layers[id]->vector_to_matrix();
		}

		matrix *get_activated_neuron_matrix(int id)	{
			return this->layers[id]->vector_to_activated_matrix();
		}

		matrix *get_derived_neuron_matrix(int id)	{
			return this->layers[id]->vector_to_derived_matrix();
		}

		matrix *get_weight_matrix(int id)	{
			return this->weights[id];
		}

		void set_neuron_value(int id_layer,int id_neuron, double val)	{
			this->layers[id_layer]->set_value(id_neuron, val);
		}

		double get_total_error()	{
			return this->error;
		}

		vector<double> get_error_vector()	{
			return this->errors;
		}
		
	private:
		int size;

		vector<int> topology;
		vector<layer *> layers;
		vector<matrix *> weights;
		vector<double> input;
		vector<double> errors;
		double error;
		vector<double> error_history;
		vector<double> target;
};

#endif