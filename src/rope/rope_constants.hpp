#ifndef ROPE_CONSTANTS_H
# define ROPE_CONSTANTS_H

#pragma once

#include <glm/gtc/constants.hpp>

const int ROPE_VERSION = 0;

const int NOTHING = 0;
const int NONE = 0;
// const int NULL = 0;
const int BLANK = 0;

const int NORMAL = 1;
const int LINEAR = 1;

// PI and TWO PI still existe in Open Framework
const float TAU = glm::two_pi<float>();

const float NORTH = -(glm::pi<float>() *0.5f);
const float NORTH_EAST = -(glm::pi<float>() *0.25f);
const float EAST = 0;
const float SOUTH_EAST = glm::pi<float>() *0.25f;
const float SOUTH = glm::pi<float>() * 0.5f;
const float SOUTH_WEST = glm::pi<float>() * 0.75f;
const float WEST = glm::pi<float>();
const float NORTH_WEST = -(glm::pi<float>() * 0.75f);

// Processing Value 0, 1, 2, 3
// enum Dir { CORNER, CORNERS, RADIUS, DIAMETER };

const int CENTER  = 3; // processing value
const int SIDE  = 9;

// enum Dir{ TOP = 101, BOTTOM };

// enum Dir{ OPEN = 1, CLOSE }; // processing value

// enum Dir { BEGIN = 701, END } ;
// enum Dir { START = 701, STOP };
// enum Dir { FIRST = 701, LAST, NEXT, PREVIOUS };

// enum Dir { FLUID = 200, GRAVITY, MAGNETIC };
	
// enum Dir { PERLIN = 887, CHAOS, ORDER, EQUATION };

const int RAND = 888;
const int RANDOM = 888;

// enum Dir { SIN = 350, COS, TAN };

// enum Dir { POW = 2, SQUARE };

// DRAW = 400
// enum Dir { FIT = 401, SCALE, SCALE_HORIZONTAL, SCALE_VERTICAL };

// enum Dir { CARTESIAN = 500, POLAR };
	
// enum Dir { HORIZONTAL = 550, VERTICAL, DIAGONAL, CIRCULAR, SPIRAL, WAVE };

// enum Dir { MIX = 600, SPLIT } ;

// enum Dir { QUARTER = 700, THIRD, HALF, TWO_THIRD, THREE_QUARTER, FULL };

// enum Dir { SEED = 900, ROOT, TREE, LEAF, FLOWER };

// enum Dir { STATIC = 1000, DYNAMIC };


#endif