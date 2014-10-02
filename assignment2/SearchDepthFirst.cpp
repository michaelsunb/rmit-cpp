/*
 * SearchDepthFirst.cpp
 *
 *  Created on: 1 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */


#include "Maze.h"
#include <vector>

using namespace std;

class SearchDepthFirst
{


public:
	void findM(int xy1,int xy2);
	void unionM(int xy1, int xy2); // merge

	void computePath(Maze &maze)
	{
		Maze* aNewMaze = &maze;
		//vector<Edges> & mazeEdges = maze->mazeEdgeArray();
		vector<vector<Cell>> & mazeArray = aNewMaze->mazeCellArray();
		mazeArray.resize(10);
		for(int x=0;x<10;x++)
		{
			for(int y=0;y<10;y++)
			{
				/**
				 * we can initialise (resize) the vector
				 * in the for loop before this but
				 * just use push_back because we need
				 * to the cell struct to false and
				 * the current x and y value
				 */
				mazeArray[x].push_back({false,x, y});
			}
		}
	}
};
