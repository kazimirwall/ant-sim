/*
 * World.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#include "World.h"

World::World(const int &height, const int &width, bool debug)
		: HEIGHT(height), WIDTH(width), DEBUG(debug) {

	// Check inputs
	assert(height > 0);
	assert(width > 0);

	// Create 2D grid data struct array
	for (int i = 0; i < HEIGHT; i++) {
		std::vector<GridData> gridRow;
		for (int j = 0; j < WIDTH; j++) {
			GridData g;
			gridRow.push_back(g);
		}
	}

	if (DEBUG) {
		using namespace std;
		cout << "Height: " << HEIGHT << endl;
		cout << "Width:  " << WIDTH << endl;
	}
}

World::~World() {

	// Deallocate all dynamically allocated data.

}


/**
 * Changes the given pheromone at a given location by the given amount (change).
 */
void World::deltaPheromone(Pheromone pheromone, Location location, int change) {
	// Create a reference to the grid location for easy access following
	GridData &gridLoc = gridData[location.y][location.x];

	// Depending on pheromone
	switch (pheromone) {
	case FOOD:
		gridLoc.homePheromone += change;
		break;
	case HOME:
		gridLoc.foodPheromone += change;
		break;
	}
}


void World::showGrid() {

	using namespace std;


	// Todo there seems to be some strange issue here
	for (int i = 0; i < WIDTH; i++) {
		std::vector<GridData> gridRow = gridData[i];
		for (int j = 0; j < HEIGHT; j++) {
			GridData gridPoint = gridRow[j];
			cout << "Location " << i << ", " << j << ": " << endl;
			cout << "Food Pheromone: " << gridPoint.foodPheromone << endl;
			cout << "Home Pheromone: " << gridPoint.homePheromone << endl;
			cout << "isHive:         " << gridPoint.isHive << endl;
			cout << "nFood:          " << gridPoint.nFood << endl;
		}
	}
}
