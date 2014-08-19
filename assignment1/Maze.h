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

const int defaultSeed = 0;
const int defaultWidth = 0;
const int defaultHeight = 0;

class Maze
{
private:
	int seed;
	int width;
	int height;
	int numOfLInes;
	
	// for recursive backtracker
	std::vector<Edges> eArray;
	std::vector<std::vector<Cell>> twoDCell;
	
public:
	Maze(): Maze(defaultSeed,defaultWidth,defaultHeight)
	{}; // Default constructor
	Maze(const int &seed,const int &width,const int &height);
	void LoadBinary(char *filename);
	void SaveSVG(char *filename);
	
	std::vector<Edges> & mazeEdgeArray();
	std::vector<std::vector<Cell>> & mazeCellArray();
	//void setCellArray(Cell inCell);
	//void setEdgeArray(Edges inEdge);
};

#endif /* MAZE_H_ */
