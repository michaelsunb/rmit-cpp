/*
 * ChooseRandomNeighbour.cpp
 *
 *  Created on: 20 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */


#include "../DepthBuilder.h"


void DepthBuilder::chooseNeighbour()
{
	/**
	 * randomly choose a neighbour based
	 * on how many is not visited
	 */
	int howManyNeighbours = allowableNeighbours.size();
	switch(allowableNeighbours[rand() % howManyNeighbours])
	{
	case xIncrementGoEast:
		++currentX;
		break;
	case yIncrementGoNorth:
		++currentY;
		break;
	case xDecrementGoWest:
		--currentX;
		break;
	case yDecrementGoSouth:
		--currentY;
		break;
	}
}
