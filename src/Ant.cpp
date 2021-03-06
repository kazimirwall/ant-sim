/*
 * Ant.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Ross
 */

#include "Ant.h"

int Ant::numAnts = 0;


Ant::Ant(World *pWorld, Location pLoc, Direction pOrient, bool debug)
		: world(pWorld), location(pLoc), dirOriented(pOrient), DEBUG(debug) {

	// Check inputs


	// TODO Auto-generated constructor stub
	ID = numAnts++; // Creates an ID for this Ant and increments. First Ant === 0


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

	if (DEBUG) {
		using namespace std;
		cout << "Laying pheromone " << pheroName(pheromone) << " at location: ";
		cout << location.x << ", " << location.y << endl;
	}

	world->deltaPheromone(pheromone, location, amount);
}


void Ant::update() {
	using namespace std;

	vector<Location> lookingAt = isLookingAt();

	if (DEBUG) {
		cout << "Looking at:" << endl;
		cout << "L: " << lookingAt[0].x << ", " << lookingAt[0].y << endl;
		cout << "C: " << lookingAt[1].x << ", " << lookingAt[1].y << endl;
		cout << "R: " << lookingAt[2].x << ", " << lookingAt[2].y << endl;
	}
}


/**
 * Returns the three grid locations in front of the ant that it can see.
 *
 * Eg, if facing north at location [12, 15], then the function will return
 * the locations with x/y values: [
 */
std::vector<Location> Ant::isLookingAt() {

	using namespace std;

	// The numer of directions is 8, so use that and mod algebra to figure out
	// the directions to the right and left of the direction currently oriented.
	Direction left = (Direction) ((dirOriented + 1) % NUM_DIRECTIONS);
	Direction right = (Direction) ((dirOriented - 1) % NUM_DIRECTIONS);

	// Translate to new locations
	vector<Location> lookingAt(3);
	lookingAt[0] = translateDirection(location, left);
	lookingAt[1] = translateDirection(location, dirOriented);
	lookingAt[2] = translateDirection(location, right);

	return lookingAt;
}


/**
 * Moves the ant in the given direction.
 */
void Ant::move(Direction direction) {

	if (DEBUG) {
		using namespace std;
		cout << "X Location: " << location.x << endl;
		cout << "Y Location: " << location.y << endl;
	}

	Location newLoc = translateDirection(location, direction);

	// Set fields
	location.x = newLoc.x;
	location.y = newLoc.y;

	if (DEBUG) {
		using namespace std;
		cout << "Updated X: " << location.x << endl;
		cout << "Updated Y: " << location.y << endl;
	}
}


/**
 * Translates the given x and y coordinates after into the given direction.
 *
 * Note that there is no return - the parameters themselves are changed.
 *
 * The given x and y will not be changed if the change would cause them to
 * go outside of the world frame.
 */
Location Ant::translateDirection(const Location &loc, Direction direction) {

	// Print direction translating
	if (DEBUG) {
		using namespace std;
		cout << "Translating " << dirName(direction) << endl;
	}

	// Copy x and y coordinates from given location so not to change them.
	int x = loc.x;
	int y = loc.y;

	switch (direction) {
		case NORTH:
			if (y > 0)
				y--;
			break;
		case NORTHEAST:
			if (x < world->getWidth() - 1)
				x++;
			if (y > 0)
				y--;
			break;
		case EAST:
			if (x < world->getWidth() - 1)
				x++;
			break;
		case SOUTHEAST:
			if (x < world->getWidth() - 1)
				x++;
			if (y < world->getWidth() - 1)
				y++;
			break;
		case SOUTH:
			if (y < world->getWidth() - 1)
				y++;
			break;
		case SOUTHWEST:
			if (y < world->getWidth() - 1)
				y++;
			if (x > 0)
				x--;
			break;
		case WEST:
			if (x > 0)
				x--;
			break;
		case NORTHWEST:
			if (y > 0)
				y--;
			if (x > 0)
				x--;
			break;
	}

	// Create and return new Location
	Location returnLoc;
	returnLoc.x = x;
	returnLoc.y = y;
	return returnLoc;
}
