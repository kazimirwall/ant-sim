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
#include "AntResources.h"

class World {
private:
	const int HEIGHT;
	const int WIDTH;

	GridData **gridData;

public:
	World(const int &height = 100, const int &width = 100);

	virtual ~World();

	void deltaPheromone(Pheromone pheromone, Location location, int change);

	void debug();

	const int getHeight() const { return HEIGHT; }

	const int getWidth() const { return WIDTH; }
};
#endif /* WORLD_H_ */
