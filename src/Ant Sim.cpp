//============================================================================
// Name        : Ant.cpp
// Author      : Ross Jones
// Version     :
// Copyright   : OpenGL 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "World.h"
#include "Ant.h"

// I need this to not immediately crash - it has something to do with gcc compiler not
// handling exceptions like g++ would.
void *__gxx_personality_v0;

// Forward declarations for this file
void testWorld();
void testAnt();


int main() {
	using namespace std;

	cout << "Lets make antz!" << endl << endl; // prints Lets make antz

	testWorld();
	testAnt();

	return 0;
}


/*
 * For testing the World class.
 */
void testWorld() {
	using namespace std;

	cout << "Testing World..." << endl << endl;

	// Create world
	int height = 10;
	int width = 10;
	bool debug = true;
	World world(height, width, debug);

	// Apply a pheromon change
	Pheromone pher = FOOD;
	Location loc;
	loc.x = 5;
	loc.y = 5;
	int change = 3;
	world.deltaPheromone(pher, loc, change);

	// Show the world grid
	world.showGrid();
}

/*
 * For testing the Ant class.
 */
void testAnt() {
	using namespace std;

	cout << "Testing Ant..." << endl << endl;

	// Create world
	int height = 10;
	int width = 10;
	bool debug = true;
	World world(height, width, debug);

	// Create ant in world
	World *worldPtr = &world;
	Location antLoc;
	antLoc.x = 1;
	antLoc.y = 1;
	Direction orient = SOUTHEAST;
	// debug already declared
	Ant ant(worldPtr, antLoc, orient, debug);

	// Update the ant (prints out what it is looking at in debug mode)
	ant.update();
}
