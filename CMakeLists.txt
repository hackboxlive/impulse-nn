cmake_minimum_required(VERSION 3.0)
project(impulse-nn)

set(CMAKE_BUILD_TYPE	DEBUG)
set(CMAKE_CXX_FLAGS		"${CMAKE_CXX_FLAGS} -std=c++14")

#main app
add_executable(
	impulse
	src/main.cpp
	src/neuron.cpp
)