/*
 * Ant.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Ross
 */

#include "Ant.h"

Ant::Ant(World pWorld, Location pLoc, Direction pOrient)
		: world(pWorld), location(pLoc), dirOriented(pOrient) {

	// Check inputs


	// TODO Auto-generated constructor stub

//	if (!pLoc) {
//		// pLoc is null
//		pLoc.x = 0;
//		pLoc.y = 0;
//	}

}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}


void Ant::layPheromone(Pheromone pheromone, int amount) {
	world.deltaPheromone(pheromone, location, amount);
}


void Ant::move(Direction direction) {
	using namespace std;

	switch (direction) {
	case NORTH:
		cout << "Moving north" << endl;
		location.y--;
		break;
	case NORTHEAST:
		cout << "Moving northeast" << endl;
		location.x++;
		location.y--;
		break;
	case EAST:
		cout << "Moving east" << endl;
		location.x++;
		break;
	case SOUTHEAST:
		cout << "Moving southeast" << endl;
		location.x++;
		location.y++;
		break;
	case SOUTH:
		cout << "Moving south" << endl;
		location.y++;
		break;
	case SOUTHWEST:
		cout << "Moving southwest" << endl;
		location.y++;
		location.x--;
		break;
	case WEST:
		cout << "Moving west" << endl;
		location.x--;
		break;
	case NORTHWEST:
		cout << "Moving northwest" << endl;
		location.y--;
		location.x--;
		break;
	}
}
