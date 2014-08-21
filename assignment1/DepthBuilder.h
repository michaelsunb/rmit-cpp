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

	/**
	 * enum of direction indicating that
	 * x increment go east
	 * y increment go north
	 * x decrement go west
	 * y decrement go south
	 */
	enum DIR {xIncrementGoEast,
		yIncrementGoNorth,
		xDecrementGoWest,
		yDecrementGoSouth};

	/**
	 * To store which allowed direction
	 */
	std::vector<DIR> allowableNeighbours;
	int currentX = 0;
	int currentY = 0;

	/**
	 * Private methods because why do
	 * other classes need to access
	 * these methods
	 */
	void CheckNeighbours();
	void ChooseRandomNeighbour();
public:
	/**
	 * Build method as stated in lab 4
	 */
	void Build(Maze &maze,int width, int height,int seed);
};



#endif /* DEPTHBUILDER_H_ */
