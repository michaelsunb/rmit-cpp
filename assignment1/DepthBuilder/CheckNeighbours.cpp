/*
 * CheckNeighbours.cpp
 *
 *  Created on: 20 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../Cell.h"
#include "../DepthBuilder.h"
#include "../Assignment1.h"

void DepthBuilder::CheckNeighbours()
{
	std::vector<std::vector<Cell>> mazeArray =
			buildMaze->mazeCellArray();

	/**
	 * Clear allowableNeighbours so we can set a new
	 * bunch of neighbours that can make an edge
	 */
	allowableNeighbours.clear();

	if(currentX < width-1)
	{
		//check if increment of x is visited
		if(!mazeArray[currentX+1][currentY].visited)
		{
			allowableNeighbours.push_back(xIncrementGoEast);
		}
	}

	if(currentY < height-1)
	{
		//check if increment of y is visited
		if(!mazeArray[currentX][currentY+1].visited)
		{
			allowableNeighbours.push_back(yIncrementGoNorth);
		}
	}

	if(currentX > 0)
	{
		//check if decrement of x is visited
		if(!mazeArray[currentX-1][currentY].visited)
		{
			allowableNeighbours.push_back(xDecrementGoWest);
		}
	}

	if(currentY > 0)
	{
		//check if decrement of y is visited
		if(!mazeArray[currentX][currentY-1].visited)
		{
			allowableNeighbours.push_back(yDecrementGoSouth);
		}
	}
}
