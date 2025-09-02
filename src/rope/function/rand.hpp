/**
* RANDOM CLASSIC
* this random use the random c++ include
* v 0.1.0
* 2020-2020
*
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/
#ifndef R_RAND_H
# define R_RAND_H

#pragma once

#include <iostream>
#include <cmath>
#include <random>

float random(float max);
float random(float min, float max);
float random(float min, float max, std::default_random_engine &generator);

double random_double(double max);
double random_double(double min, double max);
double random_double(double min, double max, std::default_random_engine &generator);

long double random_long_double(long double max);
long double random_long_double(long double min, long double max);
long double random_long_double(long double min, long double max, std::default_random_engine &generator);

bool random_bool();
bool random_bool(std::default_random_engine &generator);

int random_int(int max);
int random_int(int min, int max);
int random_int(int min, int max, std::default_random_engine &generator);

long random_long(long max);
long random_long(long min, long max);
long random_long(long min, long max, std::default_random_engine &generator);

char random_char(char max);
char random_char(char min, char max);
char random_char(char min, char max, std::default_random_engine &generator);

double random_normal(double max);
double random_normal(double min, double max);
double random_normal(double min, double max, std::default_random_engine &generator);

int random_geom(double arg);
int random_geom(double arg, std::default_random_engine &generator);

double random_exp(double arg);
double random_exp(double arg, std::default_random_engine &generator);

#endif