/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "../Assignment1.h"
#include "../Maze.h"

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
	if(width < 0)
	{
		throw "Invalid args";
		return;
	}
	this->width = width;
}

void Maze::setHeight(int height)
{
	if(height < 0)
	{
		throw "Invalid args";
		return;
	}
	this->height = height;
}

void Maze::setNumOfEdges(int numOfEdges)
{
	if(numOfEdges < 0)
	{
		throw "Invalid args";
		return;
	}
	this->numOfEdges = numOfEdges;
}
