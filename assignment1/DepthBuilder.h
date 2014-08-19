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
	int width = 0;
	int height = 0;
	Maze* buildMaze;

	enum DIR { xIncrementGoEast, yIncrementGoNorth, xDecrementGoWest, yDecrementGoSouth};
	std::vector<DIR> allowableNeighbours; // to store which allowed direction
	int currentX = 0;
	int currentY = 0;

	void CheckNeighbours();
	void ChooseRandomNeighbour();
public:
	void Build(Maze &maze,int width, int height,int seed);
};



#endif /* DEPTHBUILDER_H_ */
