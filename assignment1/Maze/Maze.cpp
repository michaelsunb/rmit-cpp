/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "../Assignment1.h"
#include "../Maze.h"

using namespace std;

/**
 * Return a reference of a 2d vector array
 */
vector<vector<Cell>> & Maze::mazeCellArray()
{
	return twoDCell;
}

/**
 * Return a reference of a vector array
 */
vector<Edges> & Maze::mazeEdgeArray()
{
	return eArray;
}

/**
 * Setters because who needs getters
 */
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
