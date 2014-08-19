/*
 * DepthBuilder.h
 *
 *  Created on: 16 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#ifndef DEPTHBUILDER_H_
#define DEPTHBUILDER_H_


#include "Assignment1.h"
#include "Maze.h"

class DepthBuilder
{
private:
	int seed;
	int width;
	int height;
	Maze buildMaze;
	enum DIR { xIncrementGoEast, yIncrementGoNorth, xDecrementGoWest, yDecrementGoSouth};
public:
	DepthBuilder();
	void Build(Maze maze,int width, int height,int seed);
	void display();
};



#endif /* DEPTHBUILDER_H_ */
