#ifndef _MATRIX_TO_VECTOR_HPP_
#define _MATRIX_TO_VECTOR_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

using namespace std;

namespace utils	{
	class matrix_to_vector	{
		public:
			matrix_to_vector(matrix *a);

			vector<double> *execute();

		private:
			matrix *a;
	};
}

#endif