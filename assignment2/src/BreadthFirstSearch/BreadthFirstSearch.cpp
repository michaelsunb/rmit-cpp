/*
 * BreadthFirstSearch.cpp
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */



#include "../BreadthFirstSearch.h"


using namespace std;

void BreadthFirstSearch::bFS(Node root, Node goal)
{
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

		for(SVGEdge & mEdge : newMazeEdges)
		{
			if((mEdge.x1 == prevX) && (mEdge.y1 == prevY) && (mEdge.x2 == curX) && (mEdge.y2 == curY))
			{
				mEdge.colour = "red";
			}
		}

		Q.pop();

		if(t == goal)
		{
			return;
		}

		children = t.getChildren();

		for (int i = 0; i < children.size(); ++i)
		{
			Q.push(children[i]);
		}
	}
}

void BreadthFirstSearch::computePath(Maze &maze,Node root)
{
	buildMaze = &maze;
	vector<vector<VisitedCell>> mazeA = buildMaze->mazeCellArray();

	int width = mazeA.size();
	int height = mazeA[0].size();

	bFS(root, Node(width-1,height-1));
}
