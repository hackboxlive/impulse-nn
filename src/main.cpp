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
	topology.push_back(2);
	topology.push_back(3);

	network *nn = new network(topology);
	nn->set_input(input);
	nn->set_target(input);

	for(int i=0;i<1000000;i++)	{
		cout<<"Epoch: #"<<i<<endl;
		nn->feed_forward();
		nn->set_errors();
		cout<<"Total error = "<<nn->get_total_error()<<endl;
		nn->back_propagation();
	}
	return 0;
}