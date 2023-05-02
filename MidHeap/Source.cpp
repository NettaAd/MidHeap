#include "Pair.h"
#include "MinHeap.h"
#include "MaxHeap.h"
#include "MidHeap.h"

bool isDigit(char dig);
void ByeBye();




int main()
{
	MidHeap heap;
	Pair tmp;
	string numOfActions, first, priority, value, order;
	int lenNumActions, numActionsInt, lenPriority;

	getline(cin, numOfActions);
	lenNumActions = numOfActions.length();

	if (lenNumActions == 0)
		ByeBye();

	for (int i = 0; i < lenNumActions; i++)
	{
		if (i == 0)
		{
			if (!isDigit(numOfActions[i]) || numOfActions[i] == '0')
				ByeBye();
		}
		else
		{
			if (!isDigit(numOfActions[i]))
				ByeBye();
		}
	}

	numActionsInt = stoi(numOfActions);
	
	getline(cin, first);
	if (first.length() == 0)
		ByeBye();

	if (first != "e") // THE FIRST ORDER HAVE TO BE CREATE EMPTY
		ByeBye();

	heap.CreateEmpty();

	for (int i = 0; i < numActionsInt - 1; i++)
	{
		cin >> order;
		if (order.length() != 1)
			ByeBye();

		switch (order[0])
		{
		case 'a':
			tmp = heap.Max();
			cout << tmp.priority << tmp.str;
			break;

		case 'b':
			tmp = heap.DeleteMax();
			cout << tmp.priority << tmp.str;
			break;

		case 'c':
			tmp = heap.Min();
			cout << tmp.priority << tmp.str;
			break;

		case 'd':
			tmp = heap.DeleteMin();
			cout << tmp.priority << tmp.str;
			break;

		case 'f':
			cin >> priority;
			lenPriority = priority.length();

			if (lenPriority == 0)
				ByeBye();

			for (int i = 0; i < lenPriority; i++)
			{
				if (i == 0)
				{
					if (!isDigit(priority[i]) && priority[i] != '-')
						ByeBye();
				}
				else
				{
					if (!isDigit(priority[i]))
						ByeBye();
				}
			}
			getline(cin, value);

			if (value.length() == 0)
				ByeBye();

			heap.Insert(stoi(priority), value);
			break;

		case 'g':
			tmp = heap.Median();
			cout << tmp.priority << tmp.str;
			break;

		default:
			ByeBye();
			break;
		}
	}

	getline(cin, value);

	if (value.length() != 0)
		ByeBye();
}

bool isDigit(char dig)
{
	if (dig < '0' || dig > '9')
		return false;
	return true;
}

void ByeBye()
{
	cout << "wrong input" << endl;
	exit(1);
}
