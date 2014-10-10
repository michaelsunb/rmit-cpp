/*
 * Assignment1.cpp
 *
 *  Created on: 2 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "DepthBuilder.h"
#include "Maze.h"
#include "Kruskal.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "Cell.h"

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
	Maze *aMazeIn = new Maze();
	bool doNotContinue = true;
	Node root;
	try
	{
		for(int i = 1; i < argc ; i++)
		{
			/**
			 * strcmp from the <string.h> library
			 * to compare 2 strings together
			 */
			if(doNotContinue)
			{
				if(strcmp(argv[i], "--gr") == 0)
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
					 * Instantiate the Maze class here to1
					 * input in the DepthBuilder().build
					 * parameters
					 */
					root = DepthBuilder().build(*aMazeIn,width,height,seed);
					doNotContinue = false;
				}
				else if(strcmp(argv[i], "--gk") == 0)
				{
					const int seed = atoi(argv[++i]);
					const int width = atoi(argv[++i]);
					const int height = atoi(argv[++i]);

					root = Kruskal().build(*aMazeIn,width,height,seed);
					doNotContinue = false;
				}
			}

			if(strcmp(argv[i], "--pd") == 0)
			{
				if(doNotContinue)
				{
					throw "Could not solve maze";
				}
				DepthFirstSearch().computePath(*aMazeIn,root);
			}

			if(strcmp(argv[i], "--pb") == 0)
			{
				if(doNotContinue)
				{
					throw "Could not solve maze";
				}
				BreadthFirstSearch().computePath(*aMazeIn,root);
			}

			if(strcmp(argv[i], "--lb") == 0)
			{
				/**
				 * Or instantiate the Maze class here
				 * To load a binary file.
				 */
				aMazeIn->loadBinary(argv[++i]);
				doNotContinue = false;
			}

			if(strcmp(argv[i], "--sb") == 0)
			{
				if(doNotContinue)
				{
					throw "Could not save to binary";
				}
				aMazeIn->saveBinary(argv[++i]);
			}

			if(strcmp(argv[i], "--sv") == 0)
			{
				if(doNotContinue)
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

	return 0;
}
