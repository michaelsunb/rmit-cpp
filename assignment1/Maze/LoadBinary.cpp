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
const int numberOfEdgesBinary = 2;
const int everyForthBinary = 4;

using namespace std;

void Maze::LoadBinary(char *fileName)
{
	cout << "Loading maze: " << fileName << endl;

	ifstream dataFile(fileName,ios::binary);

	if(!dataFile.is_open())
	{
		throw "Maze binary file was not found";
	}

	/**
	 * Use binaryElement to get the first
	 * three binary numbers.
	 */
	int binaryElement = 0;
	int xyBinaryElement = 0;

	int x = 0;

	while(!dataFile.eof())
	{
		/**
		 * Read the binary file and
		 * set the read value into x
		 */
		dataFile.read((char*)&x,sizeof(int));

		/**
		 * None of the binary values should
		 * be less than zero. None!
		 */
		if(x < 0)
		{
			throw "Invalid binary file";
		}

		if(binaryElement == widthBinary)
		{
			this->setWidth(x);
		}
		else if(binaryElement == heightBinary)
		{
			this->setHeight(x);
		}
		else if(binaryElement == numberOfEdgesBinary)
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
			/**
			 * After setting the width, height and number
			 * of Edges, we now set the x1,y1,x2,y2 values
			 *
			 * So we minus in the order u see below and
			 * divide and get the remainder to get the
			 * correct binary number.
			 * [w][h][E]
			 * [0][1][2][ (3 - 3) / 4 r 0 ]
			 * [0][1][2][3][ 4 / 4 r 0 ]
			 * [0][1][2][3][4][ (5 - 1) / 4 r 0 ]
			 * [0][1][2][3][4][5][ (6 - 2) /4 r 0 ]
			 *
			 * Start over again...
			 * [0][1][2][3][4][5][6][ (7 - 3) /4 r 0 ]
			 */
			if(xyBinaryElement < numOfEdges)
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
				}
			}

			/**
			 * Need this outside from above
			 * if(((binaryElement - 2) % everyForthBinary) == 0)
			 * because if the binary file is greater
			 * than the size of the vector, then it
			 * will cause an error
			 */
			if(((binaryElement - 2) % everyForthBinary) == 0)
			{
				xyBinaryElement++;
			}

			if(xyBinaryElement > numOfEdges)
			{
				throw "Invalid binary file";
			}
		}
		binaryElement++;
	}
	dataFile.close();

	if(xyBinaryElement != this->numOfEdges)
	{
		throw "Invalid binary file";
	}
}

