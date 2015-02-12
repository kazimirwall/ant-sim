/*
 * AntResources.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#ifndef ANTRESOURCES_H_
#define ANTRESOURCES_H_


/**
 * Directions define the orientation of an ant. North is up, east is right, etc.
 * So this means south and east are oriented towards higher coordinate values.
 */
enum Direction {
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST
};


/**
 * Pheromones trigger ant movements depending on their current task.
 */
enum Pheromone {
	FOOD,
	HOME
};


/**
 * A location struct defines the x and y coordinates of an object in the world.
 */
struct Location {
	int x;
	int y;
};


/**
 * A struct that keeps track of the data for the grid.
 */
struct GridData {
	int homePheromone;
	int foodPheromone;
	int nFood;
	bool isHome;		// If you can think of a better name then yeah
};


#endif /* ANTRESOURCES_H_ */
