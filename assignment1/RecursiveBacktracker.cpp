/*
 * RecursiveBacktracker.cpp
 *
 *  Created on: 18 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Cell.hpp"
#include "Maze.hpp"

using namespace std;

enum DIR { xIncrement, yIncrement, xDecrement, yDecrement};

int main()
{
	const int width = 30;
	const int height = 30;
	int seed = 2;
	srand(seed);

	vector<vector<Cell>> maze;
	// initialise first dimension with width
	maze.resize(width);
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			maze[x].push_back({x, y,false});
		}
	}

	//Create curX and curY variables and set them to a random position in the maze.
	int curX = rand() % width;
	int curY = rand() % height;

	vector<Edges> eArray;
	vector<Cell> trail;
	vector<DIR> live;
	trail.push_back(maze[curX][curY]);

	while(trail.empty()==false)
	{
		live.clear();

		if(curX<width-1)
		{
			if(!maze[curX+1][curY].visited)
			{
				//check if increment of x is visited
				live.push_back(xIncrement);
			}
		}

		if(curY<height-1)
		{
			if(!maze[curX][curY+1].visited)
			{
				//check if increment of y is visited
				live.push_back(yIncrement);
			}
		}

		if(curX > 0)
		{
			if(!maze[curX-1][curY].visited)
			{
				//check if decrement of x is visited
				live.push_back(xDecrement);
			}
		}

		if(curY > 0)
		{
			if(!maze[curX][curY-1].visited)
			{
				//check if decrement of y is visited
				live.push_back(yDecrement);
			}
		}

		if(live.empty()==false)
		{
			int prevX = curX;
			int prevY = curY;

			switch(live[rand() % live.size()])
			{
			case xIncrement:
				++curX;
				break;
			case yIncrement:
				++curY;
				break;
			case xDecrement:
				--curX;
				break;
			case yDecrement:
				--curY;
				break;
			}
			eArray.push_back(
				{
					prevX,
					prevY,
					curX,
					curY
				}
			);
			maze[curX][curY].visited = true;

			trail.push_back(maze[curX][curY]);
		}
		else
		{
			// If the trail stack is not empty, set curX and curY to refer to the
			// position of the top item in the trail stack.
			if(trail.empty()==false) {
				curX=trail.back().x2;
				curY=trail.back().y2;
			}
			// Pop the top item from the trail stack
			trail.pop_back();

		}
	}

	ofstream svgFile("testtt.svg", ofstream::out);
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' "
			"xmlns='http://www.w3.org/2000/svg'>\n"
			"<rect width='1' height='1' style='fill: black' />" << endl;

	for(Edges & vectors : eArray)
	{

		// We want to cast the x,y arrays to float
		// before we divide by the width,height.
		//
		// Use float to reduce memory consumption

		svgFile << "<line stroke='white' stroke-width='0.005'"
				" x1='" << float(vectors.x1)/width << "'"
				" y1='" << float(vectors.y1)/height << "'"
				" x2='" << float(vectors.x2)/width << "'"
				" y2='" << float(vectors.y2)/height << "'/>" << endl;
	}

	svgFile << "</svg>" << flush;
	svgFile.close();

	cout << "width: "<< width << "\theight: " << height << endl;
	cout << "Saving svg maze: testtt.svg" << endl;

	return 0;
}
