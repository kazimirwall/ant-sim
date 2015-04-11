/*
 * World.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#include "World.h"

World::World(const int &height, const int &width, bool debug)
		: HEIGHT(height), WIDTH(width), DEBUG(debug) {

	using namespace std;

	// Check inputs
	assert(height > 0);
	assert(width > 0);

	// Create 2D grid data struct array
	for (int i = 0; i < HEIGHT; i++) {
		vector<GridData> row;
		for (int j = 0; j < WIDTH; j++) {
			GridData g;
			g.foodPheromone = 0;
			g.homePheromone = 0;
			g.isHive = false;
			g.nFood = 0;
			row.push_back(g);
		}
		gridData.push_back(row);
	}


	// Debugging output
	if (DEBUG) {
		cout << "Height: " << HEIGHT << endl;
		cout << "Width:  " << WIDTH << endl;
		cout << "gridData size: " << gridData.size() << endl;
		cout << "gridData[0] size: " << gridData[0].size() << endl;
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
	GridData &point = gridData[location.y][location.x];

	// Depending on pheromone
	switch (pheromone) {
	case FOOD:
		point.foodPheromone += change;
		break;
	case HOME:
		point.homePheromone += change;
		break;
	}
}


void World::showGrid() {

	using namespace std;

	// Prints out information for each grid point
//	for (int i = 0; i < HEIGHT; i++) {
//		for (int j = 0; j < WIDTH; j++) {
//			GridData g = gridData[i][j];
//			cout << "Location " << i << ", " << j << ": " << endl;
//			cout << "Food Pheromone: " << g.foodPheromone << endl;
//			cout << "Home Pheromone: " << g.homePheromone << endl;
//			cout << "isHive:         " << g.isHive << endl;
//			cout << "nFood:          " << g.nFood << endl;
//		}
//	}

	cout << "Test" << endl;
	for (auto &row : gridData) {
		for (auto &col : row) {
			cout << "F" << col.foodPheromone;
			cout << "H" << col.homePheromone;
			cout << "L" << col.isHive;
			cout << "N" << col.nFood << " ";
		}
		cout << endl;
	}
	cout << "Test 2" << endl;
}
