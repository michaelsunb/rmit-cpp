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
	int *x1,*y1,*x2,*y2;
public:
	Maze();
	Maze(int &seed);
	Maze(int &seed,int &width,int &height);
	void LoadBinary(char *filename);
	void SaveSVG(char *filename);
};

#endif /* MAZE_HPP_ */
