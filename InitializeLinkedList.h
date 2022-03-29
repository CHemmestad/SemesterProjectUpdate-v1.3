#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node;

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void makeList();
	//void add();
	//void remove();
	//void find();
	void print();

private:
	Node* pos;
	Node* head;
	Node* tail;

};

#endif // !LINKEDLIST_H

