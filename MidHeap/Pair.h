#ifndef __PAIR_H
#define __PAIR_H

#define MAX_SIZE 100

#include <string>
#include <iostream>
using namespace std;



typedef struct pair
{
	int priority;
	int myIndex;
	string str;
	pair* brother;

}Pair;

#endif
