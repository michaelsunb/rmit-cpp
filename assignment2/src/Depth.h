/*
 * Depth.h
 *
 *  Created on: 6 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

#include "Maze.h"
#include <random>

class Depth
{
private:
	virtual void chooseNeighbour(std::mt19937 &rng) = 0;
	virtual void checkNeighbours() = 0;
};
