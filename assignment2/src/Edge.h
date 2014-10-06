/*
 * Edges.h
 *
 *  Created on: 6 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#pragma once

#include "Cell.h"
#include <string>
/**
 * Edges represents
 * the walls of the
 * maze
 */
struct Edge
{
	int x1;
	int y1;
	int x2;
	int y2;

	Edge(int x1,int y1,int x2,int y2)
	: x1(x1), y1(y1), x2(x2), y2(y2) {}

	Edge(): x1(0), y1(0), x2(0), y2(0) {}
};

struct SVGEdge : public Edge
{
	std::string colour = "white";

	SVGEdge(int iX1,int iY1,int iX2,int iY2, std::string color)
	: colour(color)
	{
		x1 = iX1;
		y1 = iY1;
		x2 = iX2;
		y2 = iY2;
	}

	SVGEdge(): colour("white") {}
};

struct KruskalEdge : public Edge
{
	int weight;

	KruskalEdge(Cell childCell,Cell parentCell, int iWeight)
	/**
	 * : x1(iX1), y1(iY1), x2(iX2), y2(iY2), weight(iWeight)
	 * Weird how above does not work, so we initialise them
	 * inside the curly brackets
	 */
	{
		x1 = childCell.x2;
		y1 = childCell.y2;
		x2 = parentCell.x2;
		y2 = parentCell.y2;
		weight = iWeight;
	}

	KruskalEdge() : weight(0) {}
};
