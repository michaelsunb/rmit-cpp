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
	 * vector of non-visited neighbours
	 */
	allowableNeighbours.clear();

	/**
	 * Check if the current stack x and y values
	 * are less than the width or height
	 * respectively because we don't want to check
	 * if we have neighbours over the width and
	 * height.
	 *
	 * Then we check if when we increment x and/or
	 * y it is not visited, then we can add to
	 * allowableNeighbours vector
	 */
	if(currentX < width-1)
	{
		if(!mazeArray[currentX+1][currentY].visited)
		{
			allowableNeighbours.push_back(xIncrementGoEast);
		}
	}

	if(currentY < height-1)
	{
		if(!mazeArray[currentX][currentY+1].visited)
		{
			allowableNeighbours.push_back(yIncrementGoNorth);
		}
	}

	/**
	 * Check if the current stack x and y values
	 * are greater than zero because we don't
	 * want to check if we have neighbours below
	 * the value of zero
	 *
	 * Then we check if when we decrement x and/or
	 * y it is not visited, then we can add to
	 * allowableNeighbours vector
	 */
	if(currentX > 0)
	{
		if(!mazeArray[currentX-1][currentY].visited)
		{
			allowableNeighbours.push_back(xDecrementGoWest);
		}
	}

	if(currentY > 0)
	{
		if(!mazeArray[currentX][currentY-1].visited)
		{
			allowableNeighbours.push_back(yDecrementGoSouth);
		}
	}
}
