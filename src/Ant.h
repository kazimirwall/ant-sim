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

	World *world;			// I use a pointer here so that each ant doesn't copy the world
	Location location;
	Direction dirOriented;
	int ID;

	// When the class is initialized with this set to true, "debug mode" will be
	// activated, printing information with each method.
	const bool DEBUG;

	// Keeps track of the number of Ant objects made and delegates IDs
	// in the constructor.
	static int numAnts;

	void move(Direction direction);

	Location translateDirection(const Location &loc, Direction direction);

public:

	Ant(World *pWorld, Location pLoc, Direction pOrient = NORTH, bool debug = false);

	virtual ~Ant();

	void layPheromone(Pheromone pheromone, int amount);

	void update();

	std::vector<Location> isLookingAt();
};

#endif /* ANT_H_ */
