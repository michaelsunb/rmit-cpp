/*
 * LoadBinary.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include "../Assignment1.h"
#include "../Maze.h"

const int widthBinary = 0;
const int heightBinary = 1;
const int numberOfLinesBinary = 2;
const int everyForthBinary = 4;

using namespace std;

void Maze::LoadBinary(char *fileName)
{
	cout << "Loading maze: " << fileName << endl;

	ifstream dataFile;
	dataFile.open(fileName,ios::binary);

	/**
	 * Check if the file can be opened
	 */
	if(!dataFile.is_open())
	{
		throw "Maze binary file was not found";
		return;
	}

	int binaryElement = 0;
	int xyBinaryElement = 0;

	int x = 0;

	/**
	 * Loop the binary file
	 * until the end of file
	 */
	while(!dataFile.eof())
	{
		/**
		 * Read the binary file and
		 * set the read value into x
		 */
		dataFile.read((char*)&x,sizeof(int));

		if(binaryElement == widthBinary)
		{
			this->setWidth(x);
		}
		else if(binaryElement == heightBinary)
		{
			this->setHeight(x);
		}
		else if(binaryElement == numberOfLinesBinary)
		{
			this->setNumOfEdges(x);
			/**
			 * Initialise edge vector
			 * Create an array size based on
			 * the number of edges
			 */
			eArray.resize(this->numOfEdges);
		}
		else
		{
			if(((binaryElement - 3) % everyForthBinary) == 0)
			{
				eArray[xyBinaryElement].x1 = x;
			}
			if(((binaryElement) % everyForthBinary) == 0)
			{
				eArray[xyBinaryElement].y1 = x;
			}
			if(((binaryElement - 1) % everyForthBinary) == 0)
			{
				eArray[xyBinaryElement].x2 = x;
			}
			if(((binaryElement - 2) % everyForthBinary) == 0)
			{
				eArray[xyBinaryElement].y2 = x;
				xyBinaryElement++;
			}
		}
		binaryElement++;
	}
}

