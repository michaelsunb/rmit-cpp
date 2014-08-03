/*
 * SaveSVG.cpp
 *
 *  Created on: 3 Aug 2014
 *      Author: Rollide
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

using namespace std;

void Maze::SaveSVG(char *fileName)
{
	// TODO
	cout << "\n--ss " << flush;
	cout << fileName << endl;

	cout << "svg width: " << this->width << endl;
	cout << "svg height: " << this->height << endl;
	cout << "svg number of lines: " << this->numOfLInes << endl;
	cout << sizeof(this->x1) << endl;
}



