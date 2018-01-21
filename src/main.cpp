#include <iostream>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/network.hpp"
using namespace std;

int main(int argc, char **argv)	{
	vector<double> input;
	input.push_back(1);
	input.push_back(0);
	input.push_back(1);
	vector<int> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	network *nn = new network(topology);
	nn->set_input(input);
	nn->feed_forward();

	nn->print_network();
	return 0;
}