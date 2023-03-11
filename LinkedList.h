// LinkedList.h
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "NodeLL.h"
#include <string>

class LinkedList
{
private:
	NodeLL* head;

public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	bool isFull();
	bool insertHead(int id);
	bool insertTail(int id);
	NodeLL* search(int id);
	bool remove(int id);
	void clear();
	void print();
	int contElemList();
	NodeLL* findTail();
	bool insertGrowing(int elem);
	int findOrderingPos(int elem);

	NodeLL* getHead(void) { return head; };
	void setHead(NodeLL* head) { this->head = head; }
};

#endif
