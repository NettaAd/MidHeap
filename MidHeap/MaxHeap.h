#ifndef __MAXHEAP_H
#define __MAXHEAP_H

#include "Pair.h"

class MaxHeap
{
private:
	Pair Arr[MAX_SIZE];
	int heapSize;
	
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);


public:
	MaxHeap();
	Pair Max();
	Pair DeleteMax();
	void Insert(Pair& item);
	void deletePairinI(int indext);
	Pair* getArr();

	int getHeapSize();
	void setHeapSize(int size);

	void print();
};
#endif

