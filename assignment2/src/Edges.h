/*
 * Edges.h
 *
 *  Created on: 6 Aug 2014
 *      Author: Michaelsun Baluyos
 */

#pragma once

#include <string>
/**
 * Edges represents
 * the walls of the
 * maze
 */
struct Edges
{
	int x1;
	int y1;
	int x2;
	int y2;

	std::string colour = "white";

	Edges(int x1,int y1,int x2,int y2, std::string color)
	: x1(x1), y1(y1), x2(x2), y2(y2), colour(color) {}

	Edges(): x1(0), y1(0), x2(0), y2(0), colour("white") {}
};
