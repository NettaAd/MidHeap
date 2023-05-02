#include "MidHeap.h"

MidHeap:: MidHeap(){}
void MidHeap::CreateEmpty()
{
	big.setHeapSize(0);
	BIG.setHeapSize(0);
	small.setHeapSize(0);
	SMALL.setHeapSize(0);
}

Pair MidHeap::Median() { return SMALL.Max(); }
Pair MidHeap::Max()    { return BIG.Max(); }
Pair MidHeap::Min()    { return small.Min(); }

Pair MidHeap::DeleteMax()
{
	Pair max = BIG.DeleteMax();                   // delete the max in the maximum heap
	big.deletePairinI(max.brother->myIndex);      // delete the max in the minimum heap

	int small_size = small.getHeapSize();
	int big_size = big.getHeapSize();

	if (small_size == big_size + 2)
	{
		Pair mid = SMALL.DeleteMax();
		small.deletePairinI(mid.brother->myIndex);

		insertToBigHalf(mid.priority, mid.str);
	}
	return max;
}
Pair MidHeap::DeleteMin()
{
	Pair min = small.DeleteMin();
	SMALL.deletePairinI(min.brother->myIndex);

	int small_size = small.getHeapSize();
	int big_size = big.getHeapSize();

	if (small_size + 1 == big_size)
	{
		Pair mid = big.DeleteMin();
		BIG.deletePairinI(mid.brother->myIndex);

		insertToSmallHalf(mid.priority, mid.str);
	}
	return min;
}

void MidHeap::insertToSmallHalf(int priority, string value)
{
	Pair* min_arr, * max_arr;
	Pair x, copy_x;

	     x.str = value;       x.priority = priority;
	copy_x.str = value;  copy_x.priority = priority;

	small.Insert(x);
	SMALL.Insert(copy_x);

	min_arr = small.getArr();
	max_arr = SMALL.getArr();

	min_arr[x.myIndex].brother = max_arr + copy_x.myIndex;
	max_arr[copy_x.myIndex].brother = min_arr + x.myIndex;
}
void MidHeap::insertToBigHalf(int priority, string value)
{
	Pair* min_arr, * max_arr;
	Pair x, copy_x;

	x.str = value;       x.priority = priority;
	copy_x.str = value;  copy_x.priority = priority;

	BIG.Insert(x);
	big.Insert(copy_x);

	max_arr = BIG.getArr();
	min_arr = big.getArr();

	max_arr[x.myIndex].brother = min_arr + copy_x.myIndex;
	min_arr[copy_x.myIndex].brother = max_arr + x.myIndex;
}

// the small heap is the bigger heap
void MidHeap::Insert(int priority, string value)
{
	int big_size;
	int small_size = small.getHeapSize();

	if (small_size == 0)
		insertToSmallHalf(priority, value);
	else
	{
		// -------- insert to big -------------
		if (priority > Median().priority)  
		{
			insertToBigHalf(priority, value);
			
			big_size = big.getHeapSize();
			small_size = small.getHeapSize();

			if (big_size > small_size)
			{
				Pair y = big.DeleteMin();
				BIG.deletePairinI(y.brother->myIndex);

				insertToSmallHalf(y.priority, y.str);
			}
		}

		// -------- insert to small -----------
		else  
		{
			insertToSmallHalf(priority, value);

			big_size = big.getHeapSize();
			small_size = small.getHeapSize();

			if (small_size - 2 == big_size) // the small heap was already bigger in 1
			{
				Pair y = SMALL.DeleteMax();
				small.deletePairinI(y.brother->myIndex);

				insertToBigHalf(y.priority, y.str);
			}
		}
	}
}