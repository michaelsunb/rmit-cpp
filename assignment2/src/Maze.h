/*
 * Maze.h
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#pragma once

#include "Assignment2.h"
#include "Edge.h"
#include "Cell.h"

#include <iostream>

class Maze
{
private:
	int seed;
	int width;
	int height;
	int numOfEdges;
	
	/**
	 * for recursive backtracker
	 */
	std::vector<SVGEdge> eArray;
	
public:
	void loadBinary(char *filename);
	void saveBinary(char *filename);
	void saveSVG(char *filename);

	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();
	void setNumOfEdges(int height);

	/**
	 * for recursive backtracker
	 */
	std::vector<SVGEdge> & mazeEdgeArray();
	std::vector<std::vector<VisitedCell>> & mazeCellArray();
};
