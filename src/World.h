/*
 * World.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <cassert>
#include <iostream>
#include <vector>
#include "AntResources.h"

class World {
private:
	const int HEIGHT;
	const int WIDTH;

	// GridData is defined in AntResources, and stores infomation about food, pheromones,
	// etc that are at a particular grid location in a struct.
	std::vector<std::vector<GridData> > gridData;

	// When the class is initialized with this set to true, "debug mode" will be
	// activated, printing information with each method.
	const bool DEBUG;

public:
	World(const int &height = 100, const int &width = 100, bool debug = true);

	virtual ~World();

	void deltaPheromone(Pheromone pheromone, Location location, int change);

	const int getHeight() const { return HEIGHT; }

	const int getWidth() const { return WIDTH; }

	void showGrid();
};

#endif /* WORLD_H_ */
