/**
* Rope C++
* v 0.1.0
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/
#ifndef ROPE_H
# define ROPE_H

#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <limits>
#include <string>

#include "./template/utils/r_utils.hpp"
#include "./class/R_Lexicon.hpp"
#include "./template/vec/vec3.hpp"

// class Singleton Rope
class Rope : public R_Lexicon {
private:
	static Rope *instance;
	Rope();
public:
	static Rope *get_instance() {
		if (!instance) {
			instance = new Rope;
		}
		return instance;
	}
	


	bool colorModeScale; // = true;
	float colorModeA = 255.0f;
	float colorModeX = 255.0f;
	float colorModeY = 255.0f;
	float colorModeZ = 255.0f;
	int _colorMode = 1;


	// color
	int color(int c);
	int color(float gray);
	int color(int c, float alpha);
	int color(float gray, float alpha);
	int color(float v1, float v2, float v3);
	int color(float v1, float v2, float v3, float a);

	float red() const;
	float gre() const;
	float blu() const;

	float hue() const;
	float sat() const;
	float bri() const;

	float alp() const;

	int color() const;

	int colorMode();
	void colorMode(int mode, float x, float y, float z, float a);
	void colorMode(int mode, float x, float y, float z);
	void colorMode(int mode, float gray, float a);
	void colorMode(int mode, float arg);
	void colorMode(int mode);


protected:
	bool calcAlpha = true;

	int calcColor = 0;

	int calcAi = 0;
	int calcRi = 0;
	int calcGi = 0;
	int calcBi = 0;

	float calcA = 0;
	float calcR = 0;
	float calcG = 0;
	float calcB = 0;

	void colorCalc(int &rgb);
	void colorCalc(int &rgb, float &alpha);
	void colorCalc(float &gray);
	void colorCalc(float &gray, float &alpha);
	void colorCalc(float &x, float &y, float &z);
	void colorCalc(float &x, float &y, float &z, float &a);

	// color calc ARGB
	void colorCalcARGB(int &argb, float &alpha);

	vec3<float>	rgb_to_hsb_calc() const;
};


#endif