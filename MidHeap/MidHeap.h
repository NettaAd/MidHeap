#ifndef __MIDHEAP_H
#define __MIDHEAP_H

#include "MinHeap.h"
#include "MaxHeap.h"

class MidHeap
{
private:
	MinHeap big, small;
	MaxHeap BIG, SMALL;

public:
	MidHeap();
	Pair Max();
	Pair DeleteMax();
	Pair Min();
	Pair DeleteMin();
	void CreateEmpty();
	void Insert(int priority, string value);
	Pair Median();

	void insertToSmallHalf(int priority, string value);
	void insertToBigHalf(int priority, string value);
};
#endif
