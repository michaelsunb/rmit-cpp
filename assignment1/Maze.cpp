/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Maze.hpp"

Maze::Maze()
{
	seed,width,height,numOfLInes = 0;
	x1,y1,x2,y2 = 0;
}

Maze::Maze(int &seed,int &width,int &height)
{
	this->seed = seed;
	this->width = width;
	this->height = height;

	this->numOfLInes = 0;
	x1,y1,x2,y2 = 0;
}
