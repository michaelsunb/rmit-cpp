/*
 * Maze.hpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#ifndef MAZE_HPP_
#define MAZE_HPP_

const int defaultSeed = 0;
const int defaultWidth = 0;
const int defaultHeight = 0;

class Maze {
	int seed;
	int width;
	int height;
	int numOfLInes;
	int *x1,*y1,*x2,*y2 = 0;
public:
	Maze(): Maze(defaultSeed,defaultWidth,defaultHeight){};
	Maze(const int &seed,const int &width,const int &height);
	void LoadBinary(char *filename);
	void SaveSVG(char *filename);
};

#endif /* MAZE_HPP_ */
