/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.h"
#include "Maze.h"

using namespace std;

vector<vector<Cell>> & Maze::mazeCellArray()
{
	return twoDCell;
}

vector<Edges> & Maze::mazeEdgeArray()
{
	return eArray;
}

void Maze::setWidth(int width)
{
	this->width = width;
}

void Maze::setHeight(int height)
{
	this->height = height;
}

void Maze::setNumOfEdges(int numOfEdges)
{
	this->numOfEdges = numOfEdges;
}
