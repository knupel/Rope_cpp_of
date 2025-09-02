/**
* RANDOM CLASSIC
* this random use the random c++ include
* v 0.1.1
* 2020-2025
*/


#include "./rand.hpp"


/**
* RANDOM
*/
/**
* Random function to compute few sort or random result.
* v 0.1.0
* http://www.cplusplus.com/reference/random/uniform_real_distribution/
*/
// rand float

float random(float max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random(0, max, generator);
}

float random(float min, float max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random(min, max, generator);
}

float random(float min, float max, std::default_random_engine &generator) {
	std::uniform_real_distribution<float> gen_rand_float(min,max);
	return gen_rand_float(generator); 
}

// rand double
double random_double(double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_double(0,max,generator);
}

double random_double(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_double(min,max,generator);
}

double random_double(double min, double max, std::default_random_engine &generator) {
	std::uniform_real_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

//rand long double
long double random_long_double(long double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_long_double(0,max,generator);
}

long double random_long_double(long double min, long double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_long_double(min,max,generator);
}

long double random_long_double(long double min, long double max, std::default_random_engine &generator) {
	std::uniform_real_distribution<long double> gen_rand_long_double(min,max);
	return gen_rand_long_double(generator); 
}


// rand bool
bool random_bool() {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_bool(generator);
}

bool random_bool(std::default_random_engine &generator) {
	std::uniform_int_distribution<int> gen_rand_int(0,1);
	return gen_rand_int(generator); 
}

// rand char 
/**
 * This function cause a problem in 2025
 * */
// char random_char(char max) {
// 	std::random_device seed;
// 	std::default_random_engine generator(seed());
// 	return random_char('a',max,generator);
// }

// char random_char(char min, char max) {
// 	std::random_device seed;
// 	std::default_random_engine generator(seed());
// 	return random_char(min,max,generator);
// }



// char random_char(char min, char max, std::default_random_engine &generator) {
// 	std::uniform_int_distribution<char> gen_rand_int(min,max);
// 	return (gen_rand_int(generator));
// }

// rand int
int random_int(int max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_int(0,max,generator);
}

int random_int(int min, int max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_int(min,max,generator);
}

int random_int(int min, int max, std::default_random_engine &generator) {
	std::uniform_int_distribution<int> gen_rand_int(min,max);
	return gen_rand_int(generator); 
}

// random long 
/**
 * This function cause a problem in 2025
 * */
// long random_long(long max) {
// 	std::random_device seed;
// 	std::default_random_engine generator(seed());
// 	return random_long(0,max,generator);
// }

// long random_long(long min, long max) {
// 	std::random_device seed;
// 	std::default_random_engine generator(seed());
// 	return random_long(min,max,generator);
// }

// long random_long(long min, long max, std::default_random_engine &generator) {
// 	std::uniform_int_distribution<long> gen_rand_int(min,max);
// 	return gen_rand_int(generator); 
// }


// rand normal
double random_normal(double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_normal(0,max,generator);
}

double random_normal(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_normal(min,max,generator);
}

double random_normal(double min, double max, std::default_random_engine &generator) {
	std::normal_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

// rand geom
int random_geom(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_geom(arg,generator);
}

int random_geom(double arg, std::default_random_engine &generator) {
	std::geometric_distribution<int> gen_rand_int(std::abs(arg));
	return gen_rand_int(generator); 
}

double random_exp(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_exp(arg,generator);
}

double random_exp(double arg, std::default_random_engine &generator) {
	std::exponential_distribution<double> gen_rand_double(std::abs(arg));
	return gen_rand_double(generator); 
}
