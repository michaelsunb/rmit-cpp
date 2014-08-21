/*
 * Maze.h
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#ifndef MAZE_H_
#define MAZE_H_

#include "Assignment1.h"
#include "Edges.h"
#include "Cell.h"

class Maze
{
private:
	int seed;
	int width;
	int height;
	int numOfEdges;
	
	/**
	 * for recursive backtracker
	 */
	std::vector<Edges> eArray;
	std::vector<std::vector<Cell>> twoDCell;
	
public:
	void LoadBinary(char *filename);
	void SaveBinary(char *filename);
	void SaveSVG(char *filename);

	void setWidth(int width);
	void setHeight(int height);
	void setNumOfEdges(int height);

	/**
	 * for recursive backtracker
	 */
	std::vector<Edges> & mazeEdgeArray();
	std::vector<std::vector<Cell>> & mazeCellArray();
};

#endif /* MAZE_H_ */
