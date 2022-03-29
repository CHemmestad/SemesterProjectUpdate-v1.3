#include "Course.h"
#include "AddCourse.h"
#include "InitializeLinkedList.h"
#include <iostream>

using namespace std;

struct Node;

int main() {

	LinkedList list;
	list.makeList();
	list.print();

	AddCourse add;
	add.addCourse();

	return 0;
}