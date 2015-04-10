//============================================================================
// Name        : Ant.cpp
// Author      : Ross Jones
// Version     :
// Copyright   : OpenGL 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "World.h"
using namespace std;

int main() {
	cout << "Lets make antz" << endl; // prints Lets make antz

	World world(10, 10, true);

	world.showGrid();

	return 0;
}




