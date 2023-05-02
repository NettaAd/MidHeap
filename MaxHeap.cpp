#include "MaxHeap.h"

MaxHeap::MaxHeap() {}
int MaxHeap::Parent(int node) { return (node - 1) / 2; }
int MaxHeap::Left(int node)   { return (2 * node) + 1; }
int MaxHeap::Right(int node)  { return (2 * node) + 2; }

void MaxHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (Arr[left].priority > Arr[node].priority))
		max = left;
	else
		max = node;

	if ((right < heapSize) && (Arr[right].priority > Arr[max].priority))
		max = right;

	if (max != node)
	{
		std::swap(Arr[node], Arr[max]);

		Arr[node].brother->brother = Arr + node;
		Arr[node].myIndex = node;
		Arr[max].brother->brother = Arr + max;
		Arr[max].myIndex = max;

		FixHeap(max);
	}
}
void MaxHeap::Insert(Pair& item)
{
	heapSize++;
	int i = heapSize - 1; // the last palce in the array

	while ((i > 0) && (Arr[Parent(i)].priority < item.priority))
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
Pair MaxHeap::Max() { return Arr[0]; }
Pair* MaxHeap::getArr() { return Arr; }

Pair MaxHeap::DeleteMax()
{
	if (heapSize < 1) {}

	Pair max = Arr[0];
	heapSize--;
	Arr[0] = Arr[heapSize];
	FixHeap(0);
	return max;
}
void MaxHeap::deletePairinI(int index)
{
	Arr[index] = Arr[heapSize - 1]; 	// put the most right leaf in A[i]
	Arr[heapSize - 1].brother->brother = Arr + index;
	Arr[heapSize - 1].myIndex = index;
	heapSize--;                         // remove the most right leaf
	FixHeap(index);
}

int MaxHeap::getHeapSize() { return heapSize; }
void MaxHeap::setHeapSize(int size) { heapSize = size; }


//void MaxHeap::print()
//{
//	for (int i = 0; i < heapSize; i++)
//		cout << Arr[i].priority << " " << Arr[i].str << endl;
//}