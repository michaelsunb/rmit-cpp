/*
 * DepthBuilder.h
 *
 *  Created on: 16 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once


#include "Assignment2.h"
#include "Maze.h"
#include "Cell.h"
#include <random>

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

	void chooseNeighbour();
	void checkNeighbours();
public:
	/**
	 * Build method as stated in lab 4
	 * For object orientation
	 * Used to generate a new maze
	 */
	Node build(Maze &maze,int width, int height,int seed);
};
