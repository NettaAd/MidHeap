#include "MinHeap.h"

MinHeap::MinHeap() {}
int MinHeap::Parent(int node) { return (node - 1) / 2; }
int MinHeap::Left(int node) { return (2 * node) + 1; }
int MinHeap::Right(int node) { return (2 * node) + 2; }
Pair MinHeap::Min() { return Arr[0]; }
Pair* MinHeap::getArr() { return Arr; }

void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (Arr[left].priority < Arr[node].priority))
		min = left;
	else
		min = node;

	if ((right < heapSize) && (Arr[right].priority < Arr[min].priority))
		min = right;

	if (min != node)
	{
		std::swap(Arr[node], Arr[min]);

		Arr[node].brother->brother = Arr + node;
		Arr[node].myIndex = node;
		Arr[min].brother->brother = Arr + min;
		Arr[min].myIndex = min;

		FixHeap(min);
	}
}
Pair MinHeap::DeleteMin()
{
	if (heapSize < 1){}
	Pair min = Arr[0];
	heapSize--;
	Arr[0] = Arr[heapSize];
	FixHeap(0);
	return min;
}
void MinHeap::Insert(Pair& item)
{
	heapSize++;
	int i = heapSize - 1; // the last palce in the array

	while ((i > 0) && (Arr[Parent(i)].priority > item.priority))
	{
		Arr[i] = Arr[Parent(i)];

		// update my bro that my loc has changed
		Arr[i].brother->brother = Arr + i;
		Arr[i].myIndex = i;

		i = Parent(i);
	}

	item.myIndex = i;

	Arr[i] = item;
}

void MinHeap::deletePairinI(int index)
{
	Arr[index] = Arr[heapSize - 1]; 	// put the most right leaf in A[i]
	Arr[heapSize - 1].brother->brother = Arr + index;
	Arr[heapSize - 1].myIndex = index;
	heapSize--;                         // remove the most right leaf
	FixHeap(index);
}

int MinHeap::getHeapSize() { return heapSize; }
void MinHeap::setHeapSize(int size) { heapSize = size; }


//void MinHeap::print()
//{
//	for (int i = 0; i < heapSize; i++)
//		cout << Arr[i].priority << " " << Arr[i].str << endl;
//}