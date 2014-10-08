/*
 * DepthFirstSearch.h
 *
 *  Created on: 7 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once


#include "Edge.h"
#include "Cell.h"
#include "Maze.h"
#include <vector>
#include <stack>

using namespace std;

class DepthFirstSearch
{
private:
	Maze* buildMaze;

	void dFS(Node root, Node goal);
public:
	//DepthFirstSearch() : buildMaze(0), width(0), height(0), mazeEdges(0),mazeArray(0){};
	void computePath(Maze &maze,Node root);
};

