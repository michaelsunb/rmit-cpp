/*
 * AStar.cpp
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../AStar.h"

using namespace std;

AStar::AStar()
{
	initialisedStartGoal = false;
	foundGoal= false;

	goalCell = 0;
	startCell = 0;
}

void AStar::findPath(SearchCell curPos, SearchCell tarPos)
{
	if(!initialisedStartGoal)
	{
		for(int i; i < openList.size() ; i++)
		{
			delete openList[i];
		}
		openList.clear();

		for(int i; i < visitedList.size() ; i++)
		{
			delete visitedList[i];
		}
		visitedList.clear();

		for(int i; i < endPathGoal.size() ; i++)
		{
			delete endPathGoal[i];
		}
		endPathGoal.clear();

		//start
		SearchCell start;
		start.x = curPos.x;
		start.y = curPos.y;

		//goal
		SearchCell goal;
		goal.x = tarPos.x;
		goal.y = tarPos.y;

		setStartGoal(start,goal);
		initialisedStartGoal = true;
	}

	if(initialisedStartGoal)
	{
		continuePath();
	}
}

void AStar::setStartGoal(SearchCell start,SearchCell goal)
{
	startCell = new SearchCell(start.x,start.y, nullptr);
	goalCell = new SearchCell(goal.x,goal.y,&goal);

	startCell->G = 0;
	startCell->H = startCell->mamHattanDetance(goalCell);
	startCell->parent = nullptr;

	openList.push_back(startCell);
}

SearchCell * AStar::getNextCell()
{
	float bestF = 999999999.0f;
	int cellIndex = -1;

	SearchCell * nextCell = nullptr;

	for(int i = 0; i < openList.size(); i++)
	{
		if(openList[i]->getF() < bestF)
		{
			bestF = openList[i]->getF();
			cellIndex = i;
		}
	}

	if(cellIndex >=0)
	{
		nextCell = openList[cellIndex];
		visitedList.push_back(nextCell);

		openList.erase(openList.begin() + cellIndex);
	}

	return nextCell;
}

void AStar::pathOpened(int x,int y, float newCost, SearchCell * parent)
{
	int id = y * WORLDSIZE + x;
	for(int i; i < visitedList.size() ; i++)
	{
		if(id == visitedList[i]->id)
		{
			return;
		}
	}

	SearchCell * newChild = new SearchCell(x,y,parent);
	newChild->G = newCost;
	newChild->H = parent->mamHattanDetance(goalCell);

	for(int i; i < openList.size() ; i++)
	{
		if(id == openList[i]->id)
		{
			float newF = newChild->G + newCost + openList[i]->H;

			if(openList[i]->getF() > newF)
			{
				openList[i]->G = newChild->G + newCost;
				openList[i]->parent = newChild;
			}
			else
			{
				delete newChild;
				return;
			}

		}
	}

	openList.push_back(newChild);
}

void AStar::continuePath()
{
	if(openList.empty())
	{
		return;
	}

	SearchCell * curCell = getNextCell();

	if(curCell->id == goalCell->id)
	{
		goalCell->parent = curCell->parent;

		SearchCell * getPath;

		for(getPath = goalCell; getPath != nullptr;getPath = getPath->parent )
		{
			endPathGoal.push_back(new SearchCell(getPath->x,getPath->y));
		}

		foundGoal = true;
		return;
	}

	pathOpened(curCell->x + 1,curCell->y, curCell->G + 1, curCell);
	pathOpened(curCell->x - 1,curCell->y, curCell->G + 1, curCell);
	pathOpened(curCell->x,curCell->y+1, curCell->G + 1, curCell);
	pathOpened(curCell->x,curCell->y-1, curCell->G + 1, curCell);

	for(int i; i < openList.size() ; i++)
	{
		if(curCell->id == openList[i]->id)
		{
			openList.erase(openList.begin() + i);

		}
	}
}

//SearchCell AStar::nextPathPos()
//{
//	int index = 1;
//
//	SearchCell nextPos;
//	nextPos.x = endPathGoal[endPathGoal.size() - index]->x;
//	nextPos.y = endPathGoal[endPathGoal.size() - index]->y;
//
//	SearchCell distance = nextPos - pos;
//
//	if(index < endPathGoal.size())
//	{
//		if(distance.Length() < radius)
//		{
//			endPathGoal.erase(endPathGoal.end() - index);
//		}
//	}
//
//	return nextPos;
//}
