/*
 * Kruskal.cpp
 *
 *  Created on: 5 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include <vector>

#include "../Kruskal.h"
#include "../Maze.h"

using namespace std;

Cell Kruskal::findSet(Cell vertex)
{
	int x2 = vertex.x2;
	int y2 = vertex.y2;

	if((parent[x2][y2].x2 == x2)
			&& (parent[x2][y2].y2 == y2))
	{
		return parent[x2][y2];
	}
	else
	{
		return findSet(parent[x2][y2]);
	}
}

void Kruskal::makeSet(Cell vertex)
{
	int x2 = vertex.x2;
	int y2 = vertex.y2;

	parent[x2][y2] = {x2,y2};
	rank[x2][y2] = 0;
}

void Kruskal::unionSet(Cell root1, Cell root2) // merge
{
	int x1 = root1.x2;
	int y1 = root1.y2;

	int x2 = root2.x2;
	int y2 = root2.y2;

	if(rank[x1][y1] > rank[x2][y2])
	{
		parent[x2][y2] = root1;//x1,y1
	}
	else if(rank[x2][y2] > rank[x1][y1])
	{
		parent[x1][y1] = root2;//x2,y2
	}
	else
	{
		parent[x1][y1] = root2;//x2,y2
		rank[x2][y2]++;
	}
}

void Kruskal::randomiseEdgeWeight(int x,int y)
{
	int random = rand() % (numOfLines);

	Cell newCellNeighbour = {x,y};
	edges.push_back(KruskalEdge(newCell,newCellNeighbour,random));
}

Node Kruskal::build(Maze &maze,int width, int height,int seed)
{
	srand(seed);

	cout << "Generating Kruskal maze with seed: " << seed
			<< ", width: " << width
			<< ", height: " << height << endl;

	numOfLines = (width*height);

	parent = new Cell*[width];
	rank = new int*[width];

	newCell = {0,0};

	for(int x=0;x<width;x++)
	{
		parent[x] = new Cell[height];
		rank[x] = new int[height];

		for(int y=0;y<height;y++)
		{
			newCell = {x, y};
			makeSet(newCell);

			if(x<width-1)
			{
				randomiseEdgeWeight(x+1,y);
			}

			if(y<height-1)
			{
				randomiseEdgeWeight(x,y+1);
			}

			if(x>0)
			{
				randomiseEdgeWeight(x-1,y);
			}

			if(y>0)
			{
				randomiseEdgeWeight(x,y-1);
			}
		}
	}

	sort(edges.begin(), edges.end(),[](KruskalEdge x, KruskalEdge y){return x.weight < y.weight;});

	Maze* buildMaze = &maze;
	buildMaze->setWidth(width);
	buildMaze->setHeight(height);
	vector<SVGEdge> & mazeEdges = buildMaze->mazeEdgeArray();

	Node root(0,0);
	for(KruskalEdge e : edges)
	{
		int prevX = e.x1;
		int prevY = e.y1;
		int currX = e.x2;
		int currY = e.y2;

		Cell root1 = findSet({prevX,prevY});
		Cell root2 = findSet({currX,currY});
		if(!(root1 == root2))
		{
			mazeEdges.push_back(SVGEdge(prevX,prevY,currX,currY,"white"));

			unionSet(root1,root2);
		}
	}

	return root;
}
