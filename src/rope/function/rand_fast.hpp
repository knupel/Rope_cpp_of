/**
* Rope C++
* v 0.1.0
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/
#ifndef R_RAND_FAST_H
# define R_RAND_FAST_H

#pragma once

#include <iostream>


#include "../template/vec/vec4.hpp"

float random_fast_128(vec4<uint32_t> &seed, float max);
float random_fast_128(vec4<uint32_t> &seed, float min, float max);
uint32_t random_fast_128(vec4<uint32_t> &seed);

float random_fast_32(uint32_t seed, float max);
float random_fast_32(uint32_t seed, float min, float max);
uint32_t random_fast_32(uint32_t seed);

double random_fast_64(uint32_t seed, double max);
double random_fast_64(uint32_t seed, double min, double max);
uint64_t random_fast_64(uint32_t seed);

#endif