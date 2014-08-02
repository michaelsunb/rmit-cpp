/*
 * Maze.hpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#ifndef MAZE_HPP_
#define MAZE_HPP_

class Maze {
	int seed;

	int width;
	int height;
	int numOfLInes;
	int * x1, * y1, * x2, * y2;
public:
	Maze();
	Maze(int &);
	Maze(int &,int &,int &);
	void LoadBinary(char *);
};

#endif /* MAZE_HPP_ */
