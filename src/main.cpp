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
	topology.push_back(3);

	network *nn = new network(topology);
	nn->set_input(input);
	nn->set_target(input);
	nn->feed_forward();
	nn->set_errors();
	nn->print_network();

	cout << "Total error: " << nn->get_total_error() << endl;
	return 0;
}