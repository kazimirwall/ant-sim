/*
 * Ant.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Ross
 */

#ifndef ANT_H_
#define ANT_H_

#include <cassert>
#include <iostream>
#include "AntResources.h"
#include "World.h"

class Ant {
private:

	World world;
	Location location;
	Direction dirOriented;
	int ID;

	// Keeps track of the number of Ant objects made and delegates IDs
	// in the constructor.
	static int numAnts;

	void move(Direction direction, bool debug = false);

	Location translateDirection(const Location &loc, Direction direction, bool debug = false);

public:

	Ant(World pWorld, Location pLoc, Direction pOrient = NORTH);

	virtual ~Ant();

	void layPheromone(Pheromone pheromone, int amount, bool debug = false);

	void update(bool debug = false);

	Location* isLookingAt(bool debug = false);
};

#endif /* ANT_H_ */
