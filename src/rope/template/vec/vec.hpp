#ifndef VEC_H
# define VEC_H

#pragma once
/*
* vec
* v 0.1.1
* 2020-2020
* Template Vec adapted from Rope Vector, Processing PVector, Openframework and GLSL
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "../../function/rand.hpp"
#include "../utils/r_utils.hpp"

template <class T>
class vec {
protected:
	unsigned short size = 0;
	char type = 0;
public:
	vec ();
	std::vector<T*> v_list;
	virtual ~vec();
	unsigned short get_size() const;
	char get_type() const;

	std::vector<T*> ref() const;
	std::vector<T> list();
	T sum() const;
	T average() const;
	T min() const;
	T max() const;


	T mag_sq() const;
	double mag() const;

};




template <class T>
vec<T>::vec() {
	// set type
	if(std::is_same<T, char>::value) {
		type = 'c';
	} else if(std::is_same<T, uint8_t>::value) {
		type = 'c';
	} else if(std::is_same<T, unsigned char>::value) {
		type = 'c';
	} 
		else if(std::is_same<T, bool>::value) {
		type = 'b';
	} 
		else if(std::is_same<T, short>::value) {
		type = 's';
	} else if(std::is_same<T, uint16_t>::value) {
		type = 's';
	} else if(std::is_same<T, unsigned short>::value) {
		type = 's';
	} 
		else if(std::is_same<T, int>::value) {
		type = 'i';
	} else if(std::is_same<T, uint32_t>::value) {
		type = 'i';
	} else if(std::is_same<T, unsigned int>::value) {
		type = 'i';
	} 
		else if(std::is_same<T, long>::value) {
		type = 'l';
	} else if(std::is_same<T, uint64_t>::value) {
		type = 'l';
	} else if(std::is_same<T, unsigned long>::value) {
		type = 'l';
	}
		else if(std::is_same<T, float>::value) {
		type = 'f';
	} else if(std::is_same<T, double>::value) {
		type = 'd';
	} else if(std::is_same<T, long double>::value) {
		type = 'h';
	} else {
		type = 'x';
	}
}

template <class T>
vec<T>::~vec() {
	//
}

template <class T>
unsigned short vec<T>::get_size() const {
	return size;
}

template <class T>
char vec<T>::get_type() const {
	return type;
}

template <class T>
std::vector<T> vec<T>::list() {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return temp;
}

template <class T>
std::vector<T*> vec<T>::ref() const {
	return v_list;
}

template <class T>
T vec<T>::sum() const {
	T res = 0;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		res += v_list.at(i)[0];
	}
	return res;
}

template <class T>
T vec<T>::average() const {
	return vec<T>::sum() * (1.0 / vec<T>::get_size());
}

template <class T>
T vec<T>::min() const {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return *std::min_element(temp.begin(), temp.end());
}

template <class T>
T vec<T>::max() const {
	std::vector<T> temp;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		temp.push_back(v_list.at(i)[0]);
	}
	return *std::max_element(temp.begin(), temp.end());
}



template <class T>
T vec<T>::mag_sq() const {
	T res = 0;
	for(size_t i = 0 ; i < v_list.size() ; i++) {
		res += (v_list.at(i)[0] * v_list.at(i)[0]);
	}
	return res;
}

template <class T>
double vec<T>::mag() const {
	return ::sqrt(vec<T>::mag_sq());
}


#endif