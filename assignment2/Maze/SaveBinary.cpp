/*
 * SaveBinary.cpp
 *
 *  Created on: 21 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../Maze.h"

using namespace std;

void Maze::saveBinary(char *fileName)
{
	cout << "Saving binary maze: " << fileName << endl;

	fstream dataFile(fileName, ios::out | ios::binary);

	/**
	 * First 3 are width, height and number of edges
	 * respectively
	 */
	dataFile.write((char*)&width,sizeof(int));
	dataFile.write((char*)&height,sizeof(int));
	dataFile.write((char*)&numOfEdges,sizeof(int));

	for(int i = 0; i < numOfEdges; i++)
	{
		/**
		 * Now we write x1,y1,x2,y2 in this order
		 * to the binary file.
		 */
		dataFile.write((char*)&eArray[i].x1,sizeof(int));
		dataFile.write((char*)&eArray[i].y1,sizeof(int));
		dataFile.write((char*)&eArray[i].x2,sizeof(int));
		dataFile.write((char*)&eArray[i].y2,sizeof(int));
	}
	dataFile.close();
}
