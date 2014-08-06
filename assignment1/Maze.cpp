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

	if((defaultSeed && defaultWidth && defaultHeight) == 0)
	{
		this->numOfLInes = 0;
		return;
	}
}
