/*
 * BreadthFirstSearch.h
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

#include "Cell.h"
#include "Maze.h"

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class BreadthFirstSearch
{
private:
	Maze* buildMaze;

	void bFS(Node root, Node goal);
public:
	void computePath(Maze &maze,Node root);
};
