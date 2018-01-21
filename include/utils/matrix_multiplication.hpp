#ifndef _MATRIX_MULTIPLICATION_HPP_
#define _MATRIX_MULTIPLICATION_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

using namespace std;

namespace utils	{
	class matrix_multiplication	{
		public:
			matrix_multiplication(matrix *a,matrix *b);

			matrix *execute();

		private:
			matrix *a;
			matrix *b;
			matrix *res;
	};
}

#endif