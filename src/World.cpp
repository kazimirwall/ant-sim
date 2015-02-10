/*
 * World.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#include "World.h"
#include <cassert>

World::World(const int &height, const int &width)
		: HEIGHT(height), WIDTH(width) {

	// Check inputs
	assert(height > 0);
	assert(width > 0);

	// TODO Auto-generated constructor stub

}

World::~World() {
	// TODO Auto-generated destructor stub
}

