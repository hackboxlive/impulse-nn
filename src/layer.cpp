#include "../include/layer.hpp"

layer::layer(int size)	{
	this->size = size;
	for(int i = 0; i < size; i++)	{
		neuron * n = new neuron(0.0);
		this->neurons.push_back(n);
	}
}

void layer::set_value(int pos,double v)	{
	this->neurons[pos]->set_val(v);
}

matrix *layer::vector_to_matrix()	{
	matrix *m = new matrix(1, this->neurons.size(), false);
	for(int i = 0; i < this->neurons.size(); i++)	{
		m->set_value(0, i, this->neurons[i]->get_val());
	}
	return m;
}

matrix *layer::vector_to_activated_matrix()	{
	matrix *m = new matrix(1, this->neurons.size(), false);
	for(int i = 0; i < this->neurons.size(); i++)	{
		m->set_value(0, i, this->neurons[i]->get_activated_val());
	}
	return m;
}

matrix *layer::vector_to_derived_matrix()	{
	matrix *m = new matrix(1, this->neurons.size(), false);
	for(int i = 0; i < this->neurons.size(); i++)	{
		m->set_value(0, i, this->neurons[i]->get_derived_val());
	}
	return m;
}