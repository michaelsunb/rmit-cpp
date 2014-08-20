/*
 * Assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "DepthBuilder.h"
#include "Maze.h"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc <= 1)
	{
		cout << "./exe --lb filename.maze --ss filename.svg \n"
				"./exe -g seed width height --sb filename.maze\n"
				"./exe -g seed width height --ss filename.svg\n"
				"./exe -g seed width height --sb filename.maze "
				"--sv filename.svg" << endl;
		return 0;
	}

	Maze *aMazeIn = new Maze();
	for(int i = 1; i < argc ; i++)
	{
		if(strcmp(argv[i], "-g") == 0)
		{
			 /**
			  * atoi to convert a string in
			  * a specific array into an int
			  */
			const int seed = atoi(argv[++i]);
			const int width = atoi(argv[++i]);
			const int height = atoi(argv[++i]);

			DepthBuilder mazeGen = DepthBuilder();
			mazeGen.Build(*aMazeIn,width,height,seed);
		}

		if(strcmp(argv[i], "--lb") == 0)
		{
			aMazeIn->LoadBinary(argv[++i]);
		}

		if(strcmp(argv[i], "--sb") == 0)
		{
			aMazeIn->SaveBinary(argv[++i]);
		}

		if(strcmp(argv[i], "--ss") == 0)
		{
			aMazeIn->SaveSVG(argv[++i]);
		}
	}

	return 0;
}
