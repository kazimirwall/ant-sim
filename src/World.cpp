/*
 * World.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#include "World.h"

World::World(const int &height, const int &width)
		: HEIGHT(height), WIDTH(width) {

	// Check inputs
	assert(height > 0);
	assert(width > 0);

	// Create 2D grid data struct array
	gridData = new GridData *[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
		gridData[i] = new GridData[WIDTH];

}

World::~World() {

	// Deallocate all dynamically allocated data.
	for (int i = 0; i < HEIGHT; i++)
		delete[] gridData[i];
	gridData = 0;
}


/**
 * Changes the given pheromone at a given location by the given amount (change).
 */
void World::deltaPheromone(Pheromone pheromone, Location location, int change) {
	// Create a reference to the grid location for easy access following
//	GridData &gridLoc = gridData[location.y][location.x];

	// Depending on pheromone
	switch (pheromone) {
	case FOOD:
//		gridLoc.homePheromone += change;
		break;
	case HOME:
//		gridLoc.foodPheromone += change;
		break;
	}
}


void World::debug() {
	using namespace std;

	cout << "Height: " << HEIGHT << endl;
	cout << "Width:  " << WIDTH << endl;
}

