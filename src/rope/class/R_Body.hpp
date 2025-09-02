/**
* R_BODY
* v 0.2.1
* 2020-2020
*/
#ifndef R_BODY_H
# define R_BODY_H
#pragma once

#include <iostream>
#include "../template/vec/vec3.hpp"
#include "../template/math/r_geom.hpp"

class R_Body {
	public:
		R_Body();
		R_Body(float x, float y, float z);
		~R_Body();

		// info
		static int get_instance();
		static void warning(bool is);
		static bool warning();
		
		// get
		float x() const;
		float y() const;
		float z() const;
		vec3<float> pos() const;

		// costume
		float size() const;
		// geom
		float dir() const;
		float speed() const;

		// set
		void x(float x);
		void y(float y);
		void z(float z);
		void set(float x, float y, float z = 0);
		void set(vec2<float> pos);
		void set(vec3<float> pos);

		void size(float size);

		void dir(float dir);
		void speed(float speed);

		void translate(float x, float y, float z = 0);
		void translate(vec2<float> value);
		void translate(vec3<float> value);

		bool follow(float x, float y, float z = 0);
		bool follow(vec2<float> dst);
		bool follow(vec3<float> dst);

		// follow on spherical surface >>> don't work
		bool follow_orthodromy(float lat, float lon, float alt);
		bool follow_orthodromy(vec2<float> dst, float alt);



	protected:
		static int instance;
		static bool _warning;

	private:
		float _x = 0.0f;
		float _y = 0.0f;
		float _z = 0.0f;

		float _size = 1.0f;

		float _dir = 0.0f;

		float _speed = 0.0f;
}; 

#endif