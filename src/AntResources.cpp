/*
 * AntResources.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Ross
 */

#include "AntResources.h"

/**
 * Returns the given direction as a string.
 */
std::string dirName(Direction direction) {
	switch (direction) {
		case NORTH:
			return "North";
		case NORTHEAST:
			return "Northeast";
		case EAST:
			return "East";
		case SOUTHEAST:
			return "Southeast";
		case SOUTH:
			return "South";
		case SOUTHWEST:
			return "Southwest";
		case WEST:
			return "West";
		case NORTHWEST:
			return "Northwest";
	}
};


/**
 * Returns the given pheromone as a string.
 */
std::string pheromoneName(Pheromone pheromone) {
	switch (pheromone) {
		case FOOD:
			return "Food";
		case HOME:
			return "Home";
	}
};
