/*
 * Ant.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Ross
 */

#ifndef ANT_H_
#define ANT_H_

#include "AntResources.h"
#include "World.h"

class Ant {
private:
	const World world;

	Location location;
	Direction direction;


public:

	Ant(const World &pWorld, Location pLoc, Direction pDir = NORTH);


	virtual ~Ant();
};

#endif /* ANT_H_ */
