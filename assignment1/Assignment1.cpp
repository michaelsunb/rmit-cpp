/*
 * Assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include <string.h>
#include "Assignment1.hpp"
#include "Maze.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc <= 1)
	{
		cout << "./exe --lb filename.maze --ss filename.svg \n"
				"./exe -g seed --sb filename.maze\n"
				"./exe -g seed --sv filename.svg\n"
				"./exe -g seed --sb filename.maze --sv filename.svg" << endl;
		return 0;
	}

	Maze a;
	for(int i = 1; i < argc ; i++)
	{
		if(strcmp(argv[i], "--lb") == 0)
		{
			a.LoadBinary(argv[++i]);
		}

		if(strcmp(argv[i], "--sv") == 0)
		{
			a.SaveSVG(argv[++i]);
		}
	}

	return 0;
}
