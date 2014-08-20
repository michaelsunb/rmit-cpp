/*
 * Build.cpp
 *
 *  Created on: 20 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "DepthBuilder.h"
#include "Maze.h"
#include <stack>

using namespace std;

void DepthBuilder::Build(Maze &maze,int width, int height,int seed)
{
	srand(seed);
	this->buildMaze = &maze;
	this->width = width;
	this->height = height;

	cout << "Generating maze with seed: " << seed
			<< ", width: " << width
			<< ", height: " << height << endl;

	vector<Edges> & mazeEdges = this->buildMaze->mazeEdgeArray();
	vector<vector<Cell>> & mazeArray = this->buildMaze->mazeCellArray();
	this->buildMaze->setWidth(width);
	this->buildMaze->setHeight(height);
	this->buildMaze->setNumOfEdges((width * height) - 1);

	// initialise first dimension with width
	mazeArray.resize(width);
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			mazeArray[x].push_back({false,x, y});
		}
	}

	stack<Cell> trail;
	trail.push(mazeArray[currentX][currentY]);

	while(trail.empty()==false)
	{
		this->CheckNeighbours();

		if(allowableNeighbours.empty()==false)
		{
			int prevX = currentX;
			int prevY = currentY;

			this->ChooseRandomNeighbour();

			mazeEdges.push_back({prevX,prevY,currentX,currentY});
			mazeArray[currentX][currentY].visited = true;

			trail.push(mazeArray[currentX][currentY]); // use stack
		}
		else
		{
			// If the trail stack is not empty, set curX and curY to refer to the
			// position of the top item in the trail stack.
			if(trail.empty()==false) {
				currentX=trail.top().x2;
				currentY=trail.top().y2;
			}
			// Pop the top item from the trail stack
			trail.pop();
		}
	}
}
