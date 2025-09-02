/**
* ROPE CLASS
* v 0.2.0
* 2020-2020
*/
#include "rope.hpp"

Rope::Rope() {
	return;
}
/**
* Rope::color 
* adaptation from Processing PGraphics.java part of core
* and an adaptation of this code
* https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-bot
* to catch hsb value from int Rope::rgb_to_hsb_calc()
* v 0.1.0
*/

// color
int Rope::color(int c) {
	colorCalc(c);
	return calcColor;
}

int Rope::color(float gray) {
	colorCalc(gray);
	return calcColor;
}

int Rope::color(int c, float alpha) {
	colorCalc(c, alpha);
	return calcColor;
}

int Rope::color(float gray, float alpha) {
	colorCalc(gray, alpha);
	return calcColor;
}

int Rope::color(float v1, float v2, float v3) {
	colorCalc(v1, v2, v3);
	return calcColor;
}

int Rope::color(float v1, float v2, float v3, float a) {
	colorCalc(v1, v2, v3, a);
	return calcColor;
}


// colocCalc
void Rope::colorCalc(int &rgb) {
	if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {
		// this line is weird, 
		// because in this case I have a feeling 
		// that's can became an infinity loop ?
		// plus, idon't understand well this part : ((rgb & 0xff000000) == 0)
		colorCalc(rgb);
	} else {
		colorCalcARGB(rgb, colorModeA);
	}
}


void Rope::colorCalc(int &rgb, float &alpha) {
	if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {
		colorCalc(rgb, alpha);
	} else {
		colorCalcARGB(rgb, alpha);
	}
}
	
void Rope::colorCalc(float &gray) {
	colorCalc(gray, colorModeA);
}

void Rope::colorCalc(float &gray, float &alpha) {
	if (gray > colorModeX)
		gray = colorModeX;
	if (alpha > colorModeA)
		alpha = colorModeA;

	if (gray < 0)
		gray = 0;
	if (alpha < 0)
		alpha = 0;

	calcR = colorModeScale ? (gray / colorModeX) : gray;
	calcG = calcR;
	calcB = calcR;
	calcA = colorModeScale ? (alpha / colorModeA) : alpha;

	calcRi = (int)(calcR * 255.0f); 
	calcGi = (int)(calcG * 255.0f);
	calcBi = (int)(calcB * 255.0f); 
	calcAi = (int)(calcA * 255.0f);
	calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
	calcAlpha = (calcAi != 255);
}
	
void Rope::colorCalc(float &x, float &y, float &z) {
	colorCalc(x, y, z, colorModeA);
}

void Rope::colorCalc(float &x, float &y, float &z, float &a) {
	if (x > colorModeX) x = colorModeX;
	if (y > colorModeY) y = colorModeY;
	if (z > colorModeZ) z = colorModeZ;
	if (a > colorModeA) a = colorModeA;

	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (z < 0) z = 0;
	if (a < 0) a = 0;

	switch (_colorMode) {
	case RGB:
		if (colorModeScale) {
			calcR = x / colorModeX;
			calcG = y / colorModeY;
			calcB = z / colorModeZ;
			calcA = a / colorModeA;
		} else {
			calcR = x; 
			calcG = y; 
			calcB = z; 
			calcA = a;
		}
		break;

	case HSB:
		x /= colorModeX; // h
		y /= colorModeY; // s
		z /= colorModeZ; // b

		calcA = colorModeScale ? (a/colorModeA) : a;

		if (y == 0) {  // saturation == 0
			calcR = calcG = calcB = z;
		} else {
			float which = (x - (int)x) * 6.0f;
			float f = which - (int)which;
			float p = z * (1.0f - y);
			float q = z * (1.0f - y * f);
			float t = z * (1.0f - (y * (1.0f - f)));

			switch ((int)which) {
			case 0: calcR = z; calcG = t; calcB = p; break;
			case 1: calcR = q; calcG = z; calcB = p; break;
			case 2: calcR = p; calcG = z; calcB = t; break;
			case 3: calcR = p; calcG = q; calcB = z; break;
			case 4: calcR = t; calcG = p; calcB = z; break;
			case 5: calcR = z; calcG = p; calcB = q; break;
			}
		}
		break;
	}
	calcRi = (int)(255 * calcR); 
	calcGi = (int)(255 * calcG);
	calcBi = (int)(255 * calcB); 
	calcAi = (int)(255 * calcA);
	calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
	calcAlpha = (calcAi != 255);
}

/**
* Final method to convert int value + alpha to rgbs component value can be used
*/
void Rope::colorCalcARGB(int &argb, float &alpha) {
	if (alpha == colorModeA) {
		calcAi = (argb >> 24) & 0xff;
		calcColor = argb;
	} else {
		calcAi = (int) (((argb >> 24) & 0xff) * constrain((alpha / colorModeA), 0.0f, 1.0f));
		calcColor = (calcAi << 24) | (argb & 0xFFFFFF);
	}
	calcRi = (argb >> 16) & 0xff;
	calcGi = (argb >> 8) & 0xff;
	calcBi = argb & 0xff;
	calcA = calcAi / 255.0f;
	calcR = calcRi / 255.0f;
	calcG = calcGi / 255.0f;
	calcB = calcBi / 255.0f;
	calcAlpha = (calcAi != 255);
}

/**
* colorMode
*/
int Rope::colorMode() {
	return _colorMode;
}

void Rope::colorMode(int mode, float x, float y, float z, float a) {
	_colorMode = mode;
	colorModeX = x;
	colorModeY = y;
	colorModeZ = z;
	colorModeA = a;
}

void Rope::colorMode(int mode, float x, float y, float z) {
	_colorMode = mode;
	colorModeX = x;
	colorModeY = y;
	colorModeZ = z;
}

void Rope::colorMode(int mode, float gray, float a) {
	_colorMode = mode;
	colorModeX = gray;
	colorModeY = gray;
	colorModeZ = gray;
	colorModeA = a;
}

void Rope::colorMode(int mode, float arg) {
	_colorMode = mode;
	colorModeX = arg;
	colorModeY = arg;
	colorModeZ = arg;
	colorModeA = arg;
}

void Rope::colorMode(int mode) {
	_colorMode = mode;
}


int Rope::color() const {
	return calcColor;
}

float Rope::red() const {
	return calcR * colorModeX;
}

float Rope::gre() const {
	return calcG * colorModeY;
}

float Rope::blu() const {
	return calcB * colorModeZ;
}

float Rope::alp() const {
	return calcA * colorModeA;
}

float Rope::hue() const {
	return rgb_to_hsb_calc().hue() * colorModeX;
}

float Rope::sat() const {
	return rgb_to_hsb_calc().sat() * colorModeY;
}

float Rope::bri() const {
	return rgb_to_hsb_calc().bri() * colorModeZ;
}

// https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-bot
vec3<float> Rope::rgb_to_hsb_calc() const {
	vec3<float>	temp;
	float	min, max, delta;

	min = calcR < calcG ? calcR : calcG;
	min = min  < calcB ? min : calcB;

	max = calcR > calcG ? calcR : calcG;
	max = max  > calcB ? max  : calcB;

	temp.bri(max); // v
	delta = max - min;
	if(delta < 0.000001f) {
		temp.sat(0.0f);
		temp.hue(0.0f); // undefined, maybe nan?
		return temp;
	}

	if(max > 0.0f) { // NOTE: if Max is == 0, this divide would cause a crash
		temp.sat(delta / max);                  // s
	} else {           
		temp.sat(0.0f);
		temp.hue(NAN);	// its now undefined
		return temp;
	}

	if(calcR >= max) {	// > is bogus, just keeps compilor happy
		temp.hue((calcG - calcB) / delta);	// between yellow & magenta
	} else if(calcG >= max) {
		temp.hue(2.0f + (calcB - calcR) / delta);	// between cyan & yellow
	} else {
		temp.hue(4.0f + (calcR - calcG) / delta);	// between magenta & cyan
	}
	temp.hue(temp.hue() * 0.16666666f);
	if(temp.hue() < 0.0f) {
		temp.hue(temp.hue() + 1.0f);
	}
	return temp;
}







