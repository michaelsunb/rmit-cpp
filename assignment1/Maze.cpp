/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

Maze::Maze(const int &seed,const int &width,const int &height)
{
	this->seed = seed;
	this->width = width;
	this->height = height;

	if(seed == defaultSeed && width ==  defaultWidth &&
			height ==  defaultHeight)
	{
		this->numOfLInes = 0;
		return;
	}

	this->numOfLInes = (width * height) -1;
	vectors=new Edges[numOfLInes];
}
