/*
 * Maze.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.h"
#include "Maze.h"

using namespace std;

Maze::Maze(const int &seed,const int &width,const int &height)
{
	this->seed = seed;
	this->width = width;
	this->height = height;

	if(seed == defaultSeed && width ==  defaultWidth &&
			height ==  defaultHeight)
	{
		this->numOfEdges = 0;
		return;
	}

	// initialise first dimension with width
	twoDCell.resize(width);
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			twoDCell[x].push_back({false,x, y});
		}
	}

	this->numOfEdges = (width * height) -1;
	eArray.resize(this->numOfEdges, {0,0,0,0});
}

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
