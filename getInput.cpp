//#include "Pair.h"
//#include "MinHeap.h"
//#include "MaxHeap.h"
//#include "MidHeap.h"
//
//bool isDigit(char dig);
//int main()
//{
//	MidHeap heap;
//
//	Pair tmp;
//	string numOfActions, first, priority, value;
//	int lenNumActions, numActionsInt, lenPriority;
//	bool valid = true;
//	char order;
//
//	getline(cin,numOfActions);
//	lenNumActions = numOfActions.length();
//
//	for (int i = 0; i < lenNumActions; i++)
//	{
//		if (i == 0)
//		{
//			if (!isDigit(numOfActions[i]) || numOfActions[i] == '0')
//			{
//				cout << "wrong input" << endl;
//				valid = false;
//				break;
//			}
//		}
//		else
//		{
//			if (!isDigit(numOfActions[i]))
//			{
//				cout << "wrong input" << endl;
//				valid = false;
//				break;
//			}
//		}			
//	}
//
//	if (valid)
//	{
//		getline(cin, first);
//		if (first != "e") // THE FIRST ORDER HAVE TO BE CREATE EMPTY
//		{
//			cout << "wrong input" << endl;
//			valid = false;
//		}
//	}
//
//	numActionsInt = stoi(numOfActions);
//	for (int i = 0; i < numActionsInt - 1 && valid; i++)
//	{
//		cin >> order;
//		switch (order)
//		{
//		case 'a':
//			tmp = heap.Max();
//			cout << tmp.priority << tmp.str;
//			break;
//
//		case 'b':
//			tmp = heap.DeleteMax();
//			cout << tmp.priority << tmp.str;
//			break;
//
//		case 'c':
//			tmp = heap.Min();
//			cout << tmp.priority << tmp.str;
//			break;
//
//		case 'd':
//			tmp = heap.DeleteMin();
//			cout << tmp.priority << tmp.str;
//			break;
//
//		case 'f':
//			cin >> priority;
//			lenPriority = priority.length();
//			for (int i = 0; i < lenPriority; i++)
//			{
//				if (i == 0)
//				{
//					if (!isDigit(numOfActions[i]) && numOfActions[i] != '-')
//					{
//						cout << "wrong input" << endl;
//						valid = false;
//						break;
//					}
//				}
//				else
//				{
//					if (!isDigit(numOfActions[i]))
//					{
//						cout << "wrong input" << endl;
//						valid = false;
//						break;
//					}
//				}
//			}
//
//			cin >> value;
//			heap.Insert(stoi(priority), value);
//			break;
//
//		case 'g':
//			tmp = heap.Median();
//			cout << tmp.priority << tmp.str;
//			break;
//		default:
//			cout << "wrong input" << endl;
//			valid = false;
//			break;
//		}
//	}
//	//check if more input is typed!
//
//}
// 
//bool isDigit(char dig)
//{	
//	if (dig < '0' || dig > '9')
//			return false;
//	return true;
//}