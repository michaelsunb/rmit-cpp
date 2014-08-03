/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Maze.hpp"

Maze::Maze()
{
	seed = width = height = numOfLInes = 0;
}

Maze::Maze(int &seed)
{
	this->seed = seed;

	width = height = numOfLInes = 0;
}

Maze::Maze(int &seed,int &width,int &height)
{
	this->seed = seed;
	this->width = width;
	this->height = height;

	numOfLInes = 0;
}
