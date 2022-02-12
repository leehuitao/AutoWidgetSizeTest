#pragma once
#include "define.h"

class CircularLink
{
public:
	CircularLink();

	void printIndex(int index);

	void addNodeIndex(int index,int data);

	void deleteNodeIndex(int index);
private:
	void init() { 

	}
};

CircularLink::CircularLink()
{
	init();
}

inline void CircularLink::printIndex(int index)
{
}

inline void CircularLink::addNodeIndex(int index, int data)
{
}

inline void CircularLink::deleteNodeIndex(int index)
{
}
