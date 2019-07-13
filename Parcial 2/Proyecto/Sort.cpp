#include "Libraries_or_H.h"

using namespace std;

//Function to change position of nodes 
SingleNode * Sort::swap(SingleNode * _node1, SingleNode * _node2)
{
	_node1->next = _node2->next;
	_node2->next = _node1;
	//return the node changed _node2
	return _node2;
}

DoubleNode * Sort::swap(DoubleNode * _node1, DoubleNode * _node2)
{
	return nullptr;
}



//Funciones de ordenamiento

//Function to bubblesort the single list
void Sort::bubble(SingleList & _start)
{
	SingleNode **iter;
	SingleNode *node1, *node2;
	unsigned int size = _start.s;
	bool flag = false;

	//Start
	for (int i = 0; i < size; i++)
	{
		//Iter need value the start
		iter = _start.start;
		for (int j = 0; j < size - i - 1; i++)
		{
			//I do this, for do more confortable the condition
			node1 = *iter;
			node2 = node1->next;
			if (*node1 > *node2)
			{
				flag = true;
				*iter = swap(node1, node2);
			}
			iter = &(*iter)->next;
		}
		if (!flag)
		{
			break;
		}
	}
}

void Sort::bubble(DoubleList & _list)
{
}


//Quicksort
void Sort::quick(SingleList & _list)
{
}

void Sort::quick(DoubleList & _list)
{
}
