#ifndef __MINHEAP_H
#define __MINHEAP_H

#include "Pair.h"

class MinHeap
{
private:
	Pair Arr[MAX_SIZE];
	int heapSize;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	MinHeap();
	Pair Min();
	Pair DeleteMin();
	Pair* getArr();
	void Insert(Pair& item);
	void deletePairinI(int index);

	int getHeapSize();
	void setHeapSize(int size);

	void print();	
};
#endif

