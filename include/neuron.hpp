#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <cmath>

using namespace std;

class neuron	{

	public:
		neuron(double val);
		
		void set_val(double val);

		void activate();
		
		void derivative();
		
		double get_val()	{
			return this->val;
		}
		
		double get_activated_val()	{
			return this->activated_val;
		}
		
		double get_derived_val()	{
			return this->derived_val;
		}

	private:
		double val;
		double activated_val;	//stores range compressed value of val
		double derived_val;	//stores derivative of val

};
#endif