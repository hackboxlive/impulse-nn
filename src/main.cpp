#include <iostream>
#include "../include/neuron.hpp"
using namespace std;

int main(int argc, char **argv)	{
	neuron *n = new neuron(0.9);

	cout<<n->get_val()<<endl;
	return 0;
}