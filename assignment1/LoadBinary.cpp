/*
 * LoadBinary.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

const int widthBinary = 0;
const int heightBinary = 1;
const int numberOfLinesBinary = 2;
const int everyForthBinary = 4;

using namespace std;

void Maze::LoadBinary(char *fileName)
{
	ifstream dataFile;
	dataFile.open(fileName,ios::binary);

	int binaryNumber = 0;
	int xyBinaryLine = 0;

	int x = 0;

	if(!dataFile.is_open())
	{
		return;
	}
	while(!dataFile.eof())
	{
		dataFile.read((char*)&x,sizeof(int));

		if(binaryNumber == widthBinary)
		{
			this->width = x;
		}
		else if(binaryNumber == heightBinary)
		{
			this->height = x;
		}
		else if(binaryNumber == numberOfLinesBinary)
		{
			this->numOfLInes = x;
			this->x1=new int[numOfLInes];
			this->y1=new int[numOfLInes];
			this->x2=new int[numOfLInes];
			this->y2=new int[numOfLInes];
		}
		else
		{
			if(((binaryNumber - 3) % everyForthBinary) == 0)
			{
				this->x1[xyBinaryLine] = x;
			}
			if(((binaryNumber) % everyForthBinary) == 0)
			{
				this->y1[xyBinaryLine] = x;
			}
			if(((binaryNumber - 1) % everyForthBinary) == 0)
			{
				this->x2[xyBinaryLine] = x;
			}
			if(((binaryNumber - 2) % everyForthBinary) == 0)
			{
				this->y2[xyBinaryLine] = x;
				xyBinaryLine++;
			}
		}
		binaryNumber++;
	}
}

