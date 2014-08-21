/*
 * Build.cpp
 *
 *  Created on: 20 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../DepthBuilder.h"
#include "../Maze.h"
#include <stack>

using namespace std;

void DepthBuilder::Build(Maze &maze,int width, int height,int seed)
{
	/**
	 * enter seed in srand
	 */
	srand(seed);

	cout << "Generating maze with seed: " << seed
			<< ", width: " << width
			<< ", height: " << height << endl;

	/**
	 * Set these class members for the other methods
	 */
	this->buildMaze = &maze;
	this->width = width;
	this->height = height;

	/**
	 * Set the width, height, number of edges in
	 * the Maze class.
	 */
	this->buildMaze->setWidth(width);
	this->buildMaze->setHeight(height);
	this->buildMaze->setNumOfEdges((width * height) - 1);

	vector<Edges> & mazeEdges = this->buildMaze->mazeEdgeArray();
	vector<vector<Cell>> & mazeArray = this->buildMaze->mazeCellArray();

	/**
	 * initialise first dimension with width
	 */
	mazeArray.resize(width);
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			/**
			 * we can initialise (resize) the vector
			 * in the for loop before this but
			 * just use push_back
			 */
			mazeArray[x].push_back({false,x, y});
		}
	}

	/**
	 * Vectors? Why not try something different.
	 * Let's use a stack!
	 */
	stack<Cell> trail;
	trail.push(mazeArray[currentX][currentY]);

	while(trail.empty()==false)
	{
		/**
		 * Go to ChooseRandomNeighbour method
		 * to generate a vector of neighbours
		 * not visited yet
		 */
		this->CheckNeighbours();

		/**
		 * The above method will set an array
		 * of allowableNeighbours. So we can
		 * check if there is at least 1
		 * direction we can go
		 */
		if(!allowableNeighbours.empty())
		{
			int prevX = currentX;
			int prevY = currentY;

			/**
			 * Randomly choose whether to go
			 * North, South East, West
			 */
			this->ChooseRandomNeighbour();

			mazeEdges.push_back({prevX,prevY,currentX,currentY});
			mazeArray[currentX][currentY].visited = true;

			/**
			 * Create a stack and head back to the start
			 * of the loop
			 */
			trail.push(mazeArray[currentX][currentY]);
		}
		else
		{
			/**
			 * If the allowableNeighbours is empty, it means
			 * that the trail is not allowed to go in any
			 * direction.
			 * So we set the currentX and currentY to refer
			 * to the position of the top of the stack in
			 * the trail.
			 */
			if(!trail.empty()) {
				currentX=trail.top().x2;
				currentY=trail.top().y2;
			}
			/**
			 * Pop the top stack from the trail go back one
			 * and head back to the start of the loop
			 */
			trail.pop();
		}
	}
}
