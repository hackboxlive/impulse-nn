#include <iostream>
#include <cmath>
#include "../include/neuron.hpp"

//Contructor definition
neuron::neuron(double val)	{
	this->val = val;
	activate();
	derivative();
}

//based on fast sigmoid function
//f(x) = x / (1 + |x|)
//f'(x) = f(x) * (1 - f(x))

void neuron::activate()	{
	this->activated_val = this->val / (1 + abs(this->val));
}

void neuron::derivative()	{
	this->derived_val = this->activated_val * (1 - this->activated_val);
}

void neuron::set_val(double val)	{
	this->val = val;
	this->activate();
	this->derivative();
}