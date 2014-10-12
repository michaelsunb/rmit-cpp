/*
 * Build.cpp
 *
 *  Created on: 20 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../DepthBuilder.h"
#include <stack>

using namespace std;

Node DepthBuilder::build(Maze &maze,int width, int height,int seed)
{
	srand(seed);

	cout << "Generating DepthBuilder maze with seed: " << seed
			<< ", width: " << width
			<< ", height: " << height << endl;

	this->buildMaze = &maze;
	this->width = width;
	this->height = height;

	this->buildMaze->setWidth(width);
	this->buildMaze->setHeight(height);
	this->buildMaze->setNumOfEdges((width * height) - 1);

	/**
	 * Get the reference so that any
	 * modifications to mazeEdges &
	 * mazeArray will affect the
	 * Maze class
	 */
	vector<SVGEdge> & mazeEdges = this->buildMaze->mazeEdgeArray();

	/**
	 * initialise first dimension with width
	 */
	mazeArray.resize(width);
	for(int x=0;x<width;x++)
	{
		mazeArray[x].resize(height);
	}

	/**
	 * Vectors? Why not try something different.
	 * Let's use a stack!
	 */
	stack<VisitedCell> trail;
	trail.push(mazeArray[currentX][currentY]);

	Node root(0,0);

	while(trail.empty()==false)
	{
		Node newNode = Node(currentX,currentY);
		/**
		 * Go to ChooseRandomNeighbour method
		 * to generate a vector of neighbours
		 * not visited yet
		 */
		this->checkNeighbours();

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
			this->chooseNeighbour();

			mazeEdges.push_back(SVGEdge(prevX,prevY,currentX,currentY,"white"));
			mazeArray[currentX][currentY] = VisitedCell(true,currentX,currentY);

			/**
			 * Create a stack and go back to the start
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
		root.addChild(newNode);
	}
	return root;
}
