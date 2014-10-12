/*
 * BreadthFirstSearch.cpp
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */


#include "../Cell.h"
#include "../BreadthFirstSearch.h"

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Breadth First Search and Depth First
 * Search algorithm are very similar,
 * I could of used some inheritance
 */
void BreadthFirstSearch::bFS(Node root, Node goal)
{
	/**
	 * Breadth First Search we use a queue
	 */
	std::queue<Node> Q;
	std::vector<Node> children;

	int prevX;
	int prevY;
	int curX = root.x2;
	int curY = root.y2;
	vector<SVGEdge> & newMazeEdges = buildMaze->mazeEdgeArray();

	Q.push(root);

	while(!Q.empty())
	{
		prevX = curX;
		prevY = curY;
		Node t = Q.front();
		curX = t.x2;
		curY = t.y2;

		/**
		 * Find in the maze edges and set
		 * the colour from white to red.
		 *
		 * Problem with kruskal being
		 * un-order and bi-directional
		 * needed to create an adjacency
		 * list
		 */
		for(SVGEdge & mEdge : newMazeEdges)
		{
			if((mEdge.x1 == prevX) && (mEdge.y1 == prevY) && (mEdge.x2 == curX) && (mEdge.y2 == curY))
			{
				mEdge.colour = "red";
				break;
			}
		}

		Q.pop();

		if(t == goal)
		{
			return;
		}

		children = t.getChildren();

		for (size_t i = 0; i < children.size(); ++i)
		{
			Q.push(children[i]);
		}
	}
}

void BreadthFirstSearch::computePath(Maze &maze,Node root)
{
	buildMaze = &maze;

	int width = buildMaze->getWidth();
	int height = buildMaze->getHeight();

	cout << "Solving path from {0,0} to {9,9} using "
			"Breadth First Search Algorithm" << endl;
	bFS(root, Node(width-1,height-1));
}
