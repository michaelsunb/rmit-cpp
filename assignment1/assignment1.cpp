/*
 * assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "assignment1.hpp"
#include "Maze.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc > 0)
	{
		Maze a;
		a.LoadBinary(argv[1]);
	}
	return 0;
}
