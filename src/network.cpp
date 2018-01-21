#include "../include/network.hpp"

network::network(vector<int> topology)	{
	this->size = topology.size();
	this->topology = topology;

	for(int i = 0; i < this->size; i++)	{
		layer *l = new layer(topology[i]);
		this->layers.push_back(l);
	}

	for(int i = 0; i < this->size - 1; i++)	{
		matrix *m = new matrix(topology[i], topology[i + 1], true);
		this->weights.push_back(m);
	}
}

void network::set_input(vector<double> input)	{
	this->input = input;
	for(int i = 0; i < input.size(); i++)	{
		this->layers[0]->set_value(i, input[i]);
	}
}

void network::print_network()	{
	for(int i = 0; i < this->layers.size(); i++)	{
		cout << "Layer at " << i <<endl;
		if(i == 0)	{
			matrix *m = this->layers[i]->vector_to_matrix();
			m->print_mat();
		}
		else	{
			matrix *m = this->layers[i]->vector_to_activated_matrix();
			m->print_mat();			
		}
		cout << "=============================" << endl;
		if(i < this->layers.size() - 1)	{
			cout << "Weight Matrix: " << i <<endl;
			this->get_weight_matrix(i)->print_mat();
		}
		cout << "=============================" << endl;

	}
}

void network::feed_forward()	{
	for(int i = 0; i < (this -> layers.size() - 1); i++)	{
		matrix *a = this->get_neuron_matrix(i);
	
		if(i != 0)	{
			a = this->get_activated_neuron_matrix(i);
		}

		matrix *b = this->get_weight_matrix(i);
		matrix *c = (new utils::matrix_multiplication(a,b))->execute();

		for(int j = 0; j < c->get_cols(); j++)	{
			this->set_neuron_value(i + 1, j, c->get_value(0,j));
		}
	}
}