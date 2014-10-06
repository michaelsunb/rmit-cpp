/*
 * Assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "DepthBuilder.h"
#include "Maze.h"
//#include "Kruskal.h"

using namespace std;

int main(int argc, char ** argv)
{
	if(argc <= 1)
	{
		cout << "./exe --lb filename.maze --ss filename.svg \n"
				"./exe --gr seed width height --sb filename.maze\n"
				"./exe --gr seed width height --sv filename.svg\n"
				"./exe --gr seed width height --sb filename.maze "
				"--sv filename.svg"

				"./exe --gk seed width height --sb filename.maze\n"
				"./exe --gk seed width height --sv filename.svg\n"
				"./exe --gk seed width height --sb filename.maze "
				"--sv filename.svg" << endl;
		return 0;
	}

	/**
	 * Use nullptr so we can check if the
	 * Maze class has been instantiated.
	 */
	Maze *aMazeIn = nullptr;
	try
	{
		for(int i = 1; i < argc ; i++)
		{
			/**
			 * strcmp from the <string.h> library
			 * to compare 2 strings together
			 */
			if(strcmp(argv[i], "-g") == 0)
			{
				 /**
				  * atoi from the <stdlib.h> library
				  * to convert a string in a
				  * specific array into an int
				  */
				const int seed = atoi(argv[++i]);
				const int width = atoi(argv[++i]);
				const int height = atoi(argv[++i]);

				/**
				 * Instantiate the Maze class here to
				 * input in the DepthBuilder().build
				 * parameters
				 */
				aMazeIn = new Maze();
				DepthBuilder().build(*aMazeIn,width,height,seed);
			}

			if(strcmp(argv[i], "--lb") == 0)
			{
				/**
				 * Or instantiate the Maze class here
				 * To load a binary file.
				 */
				aMazeIn = new Maze();
				aMazeIn->loadBinary(argv[++i]);
			}

			if(strcmp(argv[i], "--sb") == 0)
			{
				if(aMazeIn == nullptr)
				{
					throw "Could not save to binary";
				}
				aMazeIn->saveBinary(argv[++i]);
			}

			if(strcmp(argv[i], "--sv") == 0)
			{
				if(aMazeIn == nullptr)
				{
					throw "Could not save to svg";
				}
				aMazeIn->saveSVG(argv[++i]);
			}
		}

		delete aMazeIn;
	}
	catch (char const* param)
	{
		cout << param << ".\nMissing generated maze." << endl;
	}

//	Kruskal().build(10,10,1);

	return 0;
}
