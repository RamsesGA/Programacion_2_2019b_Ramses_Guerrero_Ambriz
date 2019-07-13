#pragma once
#include "Libraries_or_H.h"

using namespace std;

class SingleList;
class DoubleList;
class SingleNode;
class DoubleNode;

class Sort
{
	public:
		/**
		* TODO implement
		* Swaps two single nodes
		* @param [SingleNode *] The first node to swap
		* @param [SingleNode *] The second node to swap
		* @return [SingleNode *] The pointer to the second Node to finalize the swaping outside this function
		*/
		static SingleNode* swap(SingleNode *_node1, SingleNode *_node2);

		/**
		 * TODO implement
		 * Swaps two single nodes
		 * @param [DoubleNode *] The first node to swap
		 * @param [DoubleNode *] The second node to swap
		 * @return [DoubleNode *] The pointer to the second Node to finalize the swaping outside this function
		 */
		static DoubleNode* swap(DoubleNode *_node1, DoubleNode *_node2);

		/**
		 * TODO implement
		 * Sorts the given single linked list using the BubbleSort method
		 * @param [SingleList &] the list to be sorted
		 */
		static void bubble(SingleList &_start);
	
		/**
		 * TODO implement
		 * Sorts the given double linked list using the BubbleSort method
		 * @param [DoubleList &] the list to be sorted
		 */
		static void bubble(DoubleList &_list);
	
		/**
		 * TODO implement
		 * Sorts the given single linked list using the QuickSort method
		 * @param [SingleList &] the list to be sorted
		 */
		static void quick(SingleList &_list);
	
		/**
		 * TODO implement
		 * Sorts the given double linked list using the QuickSort method
		 * @param [DoubleList &] the list to be sorted
		 */
		static void quick(DoubleList &_list);
};

