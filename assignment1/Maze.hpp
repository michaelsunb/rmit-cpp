/*
 * Maze.hpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include "Assignment1.hpp"
#include "Edges.hpp"

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
	std::vector<Edges> eArray;
public:
	Maze(): Maze(defaultSeed,defaultWidth,defaultHeight)
	{}; // Default constructor
	Maze(const int &seed,const int &width,const int &height);
	void LoadBinary(char *filename);
	void SaveSVG(char *filename);
};

#endif /* MAZE_HPP_ */
