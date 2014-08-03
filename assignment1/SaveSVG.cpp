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

	for(int ip = 0; ip < this->numOfLInes  ; ip++)
	{
		cout << ip << "\tx1: " << x1[ip] << "\t" << flush;
		cout << "\ty1: " << y1[ip] << "\t" << flush;
		cout << "\tx2: " << x2[ip] << "\t" << flush;
		cout << "\ty2: " << y2[ip] << "\t" << endl;
	}
}



