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

	for(int i = 0; i < topology[topology.size() - 1]; i++)	{
		this->errors.push_back(0.0);
	}

	this->error = 0.0;
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

void network::set_errors()	{
	if(this->target.size() == 0)	{
		cerr << "No target for the neural network" << endl;
		assert(false);
	}

	if(this->target.size() != this->layers[this->layers.size() - 1]->get_neurons().size())	{
		cerr << "Target sie not equal to output layer size\n";
		assert(false);
	}

	this->error = 0.0;
	vector<neuron *> output = this->layers[this->layers.size() - 1]->get_neurons();
	for(int i = 0; i < target.size(); i++)	{
		double temp = (output[i]->get_activated_val() - target[i]);
		this->errors[i] = temp;
		this->error += temp;
	}
	error_history.push_back(this->error);
}

void network::back_propagation()	{
	vector<matrix *> new_weights;
	matrix *grad;
	//output to hidden
	int output_layer_id = this->layers.size() - 1;
	matrix *derived_y_to_z = this->layers[output_layer_id]->vector_to_derived_matrix();
	matrix *gradient_y_to_z = new matrix(1, this->layers[output_layer_id]->get_neurons().size(), false);
	for(int i = 0; i < this->errors.size(); i++)	{
		gradient_y_to_z->set_value(0, i, derived_y_to_z->get_value(0, i)*(this->errors[i]));
	}
	int last_hidden_layer_id = output_layer_id - 1;
	layer *last_hidden_layer = this->layers[last_hidden_layer_id];
	matrix *weights_output_to_hidden = this->weights[last_hidden_layer_id];
	matrix *delta_output_to_hidden = (new utils::matrix_multiplication(gradient_y_to_z->transpose(), last_hidden_layer->vector_to_activated_matrix()))->execute()->transpose();
	matrix *new_weights_output_to_hidden = new matrix(delta_output_to_hidden->get_rows(), delta_output_to_hidden->get_cols(), false);
	for(int i = 0; i < delta_output_to_hidden->get_rows(); i++)	{
		for(int j = 0; j < delta_output_to_hidden->get_cols(); j++)	{
			new_weights_output_to_hidden->set_value(i, j, weights_output_to_hidden->get_value(i, j) - delta_output_to_hidden->get_value(i, j));
		}
	}
	new_weights.push_back(new_weights_output_to_hidden);
	grad = new matrix(gradient_y_to_z->get_rows(), gradient_y_to_z->get_cols(), false);
	for(int i = 0; i < gradient_y_to_z->get_rows(); i++)	{
		for(int j = 0; j < gradient_y_to_z->get_cols(); j++)	{
			grad->set_value(i, j, gradient_y_to_z->get_value(i, j));
		}
	}
	for(int i = last_hidden_layer_id; i > 0; i--)	{
		layer *l = this->layers[i];
		matrix *derived_hidden = l->vector_to_derived_matrix();
		matrix *activated_hidden = l->vector_to_activated_matrix();
		matrix *derived_gradient = new matrix(1, l->get_neurons().size(), false);
		matrix *matrix_latter = this->weights[i];
		matrix *matrix_former = this->weights[i - 1];
		for(int j = 0; j < matrix_latter->get_rows(); j++)	{
			double sum = 0.0;
			for(int k = 0; k < matrix_latter->get_cols(); k++)	{
				sum += grad->get_value(0, k) * matrix_latter->get_value(j,k);
			}
			derived_gradient->set_value(0, j, sum * activated_hidden->get_value(0, j));
		}

	}
	reverse(new_weights.begin(),new_weights.end());
	this->weights = new_weights;
}