/** @file data_structure.cpp
  * @brief define the object list and data structure
  *
  * @author PokaiChang
  * @date 2013-11-15
  */
#include <stdlib.h>
#include "data_structure.h"


LinkedList::LinkedList() {
	_length = 0;
	_head = NULL;
}


int LinkedList::length() {
	return _length;
}


LinkedListNode* LinkedList::head() {
	return _head;
}


LinkedListNode* LinkedList::getNode(int n) {
	if (n < 0)
		return NULL;
	if (n > _length)
		return NULL;
	if (n == 1) {  // if first node
		return _head;
	}
	else {
		LinkedListNode *node=_head;
		int i=1;
		while (node->next) {  // jump to (nth) node
			if (i == n)
				break;
			node = node->next;
			i++;
		}
		return node;
	}
}


void LinkedList::insertNode(LinkedListData data) {
	LinkedListNode *insert_to;
	if (_length == 0) {  // if no nodes
		_head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
		insert_to = _head;
	}
	else {
		LinkedListNode *insert_after=_head;
		while (insert_after->next) {  // jump to last node
			insert_after = insert_after->next;
		}
		insert_after->next = (LinkedListNode *)malloc(sizeof(LinkedListNode));
		insert_to = insert_after->next;
	}
	insert_to->data = data;
	insert_to->next = NULL;
	_length++;
}


void LinkedList::insertNode(int n, LinkedListData data) {
	if (n < 1)
		n = 1;
	if (n > _length+1)
		n = _length+1;
	LinkedListNode *new_node=(LinkedListNode *)malloc(sizeof(LinkedListNode));
	new_node->data = data;

	if (n == 1) {  // if first node
		if (n < _length)
			new_node->next = _head;
		else
			new_node->next = NULL;
		_head = new_node;
	}
	else {
		LinkedListNode *insert_after=_head;
		int i=1;
		while (insert_after->next) {  // jump to nth node
			if (i == n-1)
				break;
			insert_after = insert_after->next;
			i++;
		}
		if (n < _length)
			new_node->next = insert_after->next;
		else
			new_node->next = NULL;
		insert_after->next = new_node;
	}
	_length++;
}


void LinkedList::deleteNode() {
	if (_length == 0)
		return;
	LinkedListNode *del_node=_head;
	if (_length > 1)
		_head = _head->next;
	else
		_head = NULL;
	free(del_node);
	_length--;
}


void LinkedList::deleteNode(int n) {
	if (_length == 0)
		return;
	if (n < 1)
		n = 1;
	if (n > _length)
		n = _length;
	LinkedListNode *del_node=_head;
	if (n == 1) {  // if first node
		if (n < _length)
			_head = _head->next;
		else
			_head = NULL;
		free(del_node);
	}
	else {
		LinkedListNode *del_node_p;
		int i=1;
		while (del_node->next) {  // jump to nth node
			if (i == n)
				break;
			del_node_p = del_node;
			del_node = del_node->next;
			i++;
		}
		if (n < _length)
			del_node_p->next = del_node->next;
		else
			del_node_p->next = NULL;
		free(del_node);
	}
	_length--;
}


void LinkedList::clear() {
	while (head())
		deleteNode();
}
