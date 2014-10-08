/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "../Maze.h"

using namespace std;

vector<SVGEdge> & Maze::mazeEdgeArray()
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

int Maze::getWidth()
{
	return width;
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

int Maze::getHeight()
{
	return height;
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
