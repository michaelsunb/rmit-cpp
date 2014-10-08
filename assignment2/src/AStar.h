/*
 * AStar.h
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

#include "SearchCell.h"
#include <vector>

class AStar
{
	void setStartGoal(SearchCell start, SearchCell goal);
	void pathOpened(int x,int y, float newCost, SearchCell * parent);
	SearchCell *getNextCell();
	void continuePath();

	SearchCell * startCell;
	SearchCell * goalCell;
	std::vector<SearchCell*> openList;
	std::vector<SearchCell*> visitedList;
	std::vector<SearchCell*> endPathGoal;

public:
	AStar();

	void findPath(SearchCell curPos, SearchCell tarPos);
//	SearchCell nextPathPos();
	void clearOpenList() { openList.clear(); }
	void clearVisitedList() { visitedList.clear(); }
	void clearPathGoal() { endPathGoal.clear(); }
	bool initialisedStartGoal;
	bool foundGoal;
};
