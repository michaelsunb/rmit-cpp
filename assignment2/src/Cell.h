/*
 * Cell.h
 *
 *  Created on: 18 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

struct Cell
{
	/**
	 * Need x and y to get 
	 * current position
	 */
	int x2;
	int y2;

	Cell(int x2,int y2): x2(x2), y2(y2) {};
	Cell(): x2(0), y2(0) {};
};

struct VisitedCell : public Cell
{
	bool visited;

	VisitedCell(bool iVisited,int iX2, int iY2)
	{
		visited = iVisited;
		x2 = iX2;
		y2 = iY2;
	}
};
