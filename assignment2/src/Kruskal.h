/*
 * Kruskal.cpp
 *
 *  Created on: 4 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "Cell.h"
#include "Edge.h"
#include "Maze.h"


class Kruskal
{
	int numOfLines;
	Cell newCell;
	/**
	 * PARENT[x1][y1] = Cell
	 * so we get Cell.x2 & Cell.y2
	 */
	Cell** parent;
	/**
	 * RANK[x2][y2] = weight
	 */
	int** rank;

	std::vector<KruskalEdge> edges;

public:
	void randomiseEdgeWeight(int x,int y);

	Cell findSet(Cell vertex);

	void makeSet(Cell vertex);

	void unionSet(Cell root1, Cell root2); // merge;

	Node build(Maze &maze,int width, int height,int seed);
};
