/*
 * World.h
 *
 *  Created on: Feb 10, 2015
 *      Author: Ross
 */

#ifndef WORLD_H_
#define WORLD_H_

class World {
private:
	const int HEIGHT;
	const int WIDTH;

public:
	World(const int &height, const int &width);
	virtual ~World();
};

#endif /* WORLD_H_ */
