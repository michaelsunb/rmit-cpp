/*
 * Assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc <= 1)
	{
		cout << "./exe --lb filename.maze --ss filename.svg \n"
				"./exe -g seed width height --sb filename.maze\n"
				"./exe -g seed width height --sv filename.svg\n"
				"./exe -g seed width height --sb filename.maze "
				"--sv filename.svg" << endl;
		return 0;
	}

	Maze *a;
	for(int i = 1; i < argc ; i++)
	{
		if(strcmp(argv[i], "-g") == 0)
		{
			/*
			 * atoi to convert a string in
			 * a specific array into an int
			 */
			const int seed = atoi(argv[++i]);
			const int width = atoi(argv[++i]);
			const int height = atoi(argv[++i]);
			a = new Maze(seed,width,height);
		}

		if(strcmp(argv[i], "--lb") == 0)
		{
			a = new Maze();
			a->LoadBinary(argv[++i]);
		}

		if(strcmp(argv[i], "--sv") == 0)
		{
			a->SaveSVG(argv[++i]);
		}
	}

	return 0;
}
