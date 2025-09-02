/**
* header
* Rope math geom C++
* v 0.0.6
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*
*/

#ifndef R_GEOM_H
# define R_GEOM_H


#pragma once

#include <iostream>
#include <cmath>
#include "../vec/vec3.hpp"

/**
* polar system extends to spherical one.
* by convention
* first we use latitude and in second longitude and radius or altitude.
* latitude is phi
* longitude is lambda or theta
*/
// https://en.wikipedia.org/wiki/List_of_common_coordinate_transformations#From_spherical_coordinates
template<typename T>
void coord_polar(T &x, T &y, T dir) {
	x = sin(dir);
	y = cos(dir);
}

template<typename T>
void coord_polar(T &x, T &y, T dir, T radius) {
	x = sin(dir) * radius;
	y = cos(dir) * radius;
}

template<typename T>
vec2<T> coord_polar(T dir) {
	return vec2<T>(sin(dir),cos(dir));
}


template<typename T>
vec2<T> coord_polar(T dir, T radius) {
	return (vec2<T>(sin(dir),cos(dir)) * radius);
}


// https://fr.wikipedia.org/wiki/Coordonn%C3%A9es_polaires
template<typename T>
vec3<T> coord_sphere_math(T lat, T lon) {
	double tau = 2.0 *M_PI;
	double theta = fmod(lon,tau);
	double phi = fmod(lat,tau);

	T x = static_cast<T>(sin(theta) * cos(phi));
	T y = static_cast<T>(sin(theta) * sin(phi));
	T z = static_cast<T>(cos(theta));

	return vec3<T>(x,y,z);
}


template<typename T>
vec3<T> coord_sphere_math(T lat, T lon, T radius) {
	double tau = 2.0 *M_PI;
	double theta = fmod(lon,tau);
	double phi = fmod(lat,tau);

	T x = static_cast<T>(radius * sin(theta) * cos(phi));
	T y = static_cast<T>(radius * sin(theta) * sin(phi));
	T z = static_cast<T>(radius * cos(theta));

	return vec3<T>(x,y,z);
}

template<typename T>
vec3<T> to_cartesian(T lat, T lon, T radius) {
	double tau = 2.0 *M_PI;
	double theta = fmod(lon,tau);
	double phi = fmod(lat,tau);

	T x = static_cast<T>(radius * sin(theta) * cos(phi));
	T y = static_cast<T>(radius * sin(theta) * sin(phi));
	T z = static_cast<T>(radius * cos(theta));

	return vec3<T>(x,y,z);
}

template<typename T>
vec3<T> to_cartesian(T lat, T lon) {
	double tau = 2.0 *M_PI;
	double theta = fmod(lon,tau);
	double phi = fmod(lat,tau);

	T x = static_cast<T>(sin(theta) * cos(phi));
	T y = static_cast<T>(sin(theta) * sin(phi));
	T z = static_cast<T>(cos(theta));

	return vec3<T>(x,y,z);
}

template<typename T>
vec2<T> to_polar(T x, T y, T z) {
	double r = sqrt(x * x + y * y + z * z);
	double theta = atan2(y, x);
	double phi = acos(z / r);

	T lat = static_cast<T>(theta);
	T lon = static_cast<T>(phi);
	return vec2<T>(lat,lon);
}

/**
* orthodromy, loxodromy is the science to compute distance, position on Sphere.
* very very complexe.
* and that's don't work for me.
*/
// template<typename T>
// T dist_orthodromy(T lat_1, T lon_1, T lat_2, T lon_2, T radius) {
// 	T u;
// 	T v;
// 	u = sin((lat_2 - lat_1) * 0.5);
// 	v = sin((lon_2 - lon_1) * 0.5);
// 	return 2.0 * radius * asin(sqrt(u * u + cos(lat_1) * cos(lat_2) * v * v));
// }
template<typename T>
T dist_orthodromy(T lat_1, T lon_1, T lat_2, T lon_2, T radius) {
	vec3<T> a = coord_sphere_math(lat_1, lon_1);
	vec3<T> b = coord_sphere_math(lat_2, lon_2);
	// T sum_product = (a.x() * b.x()) + (a.y() * b.y()) + (a.z() * b.z());
	T sum_product = a.cross(b).sum();
	return radius * acos(sum_product / (radius *radius));
	// return acos((a *b) / (radius *radius));
	//return asin((a *b) / (radius *radius));
}


template<typename T>
T dist_orthodromy(vec2<T> a, vec2<T> b, T radius) {
	return dist_orthodromy(a.x(), a.y(), b.x(), b.x(), radius);
}



#endif
