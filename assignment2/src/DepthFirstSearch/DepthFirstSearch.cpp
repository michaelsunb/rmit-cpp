/*
 * main.cpp
 *
 *  Created on: 8 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../Cell.h"
//#include "Maze.h"
#include "../DepthFirstSearch.h"

//#include <iostream>
#include <string>
#include <vector>
//#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void DepthFirstSearch::dFS(Node root, Node goal)
{
	std::stack<Node> Q;
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
		Node t = Q.top();
		curX = t.x2;
		curY = t.y2;

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
		std::reverse(children.begin(),children.end());

		for (int i = 0; i < children.size(); ++i)
		{
			Q.push(children[i]);
		}
	}
}

void DepthFirstSearch::computePath(Maze &maze,Node root)
{
	buildMaze = &maze;
	int width = buildMaze->getWidth();
	int height = buildMaze->getWidth();

	dFS(root, Node(width-1,height-1));
}
