/*
 * Ant.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Ross
 */

#ifndef ANT_H_
#define ANT_H_

#include <iostream>
#include <cassert>
#include "AntResources.h"
#include "World.h"

class Ant {
private:

	World world;
	Location location;
	Direction dirOriented;


public:

	Ant(World pWorld, Location pLoc, Direction pOrient = NORTH);

	virtual ~Ant();

	void layPheromone(Pheromone pheromone, int amount);

	void move(Direction direction);
};

#endif /* ANT_H_ */
