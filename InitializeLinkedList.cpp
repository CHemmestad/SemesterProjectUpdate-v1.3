#include "InitializeLinkedList.h"

struct Node {
	string name;
	string id;
	string credits;
	string type;
	string maxCapacity;
	string daysOfWeek;
	string start;
	string end;
	string classroom;
	string date;
	Node* next;
	Node* previous;
};

LinkedList::LinkedList() {
	pos = NULL;
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList() {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedList::print() {
	while (head != NULL) {
		cout << head->classroom << endl;
		head = head->next;
	}
}

void LinkedList::makeList() {
	string current;

	ifstream infile;
	infile.open("Courses.txt");

	while (current != "END OF LIST") {
		if (current == "END OF LIST") {
			break;
		}
		system("pause");
		cout << "Does not equal 'END OF LIST'" << endl; //Check
		cout << current << endl; //Check
		Node* temp = new Node();
		temp->next = NULL;
		temp->previous = NULL;
		if (!infile) {
			continue;
		}
		while (current != "END") {
			cout << "Does not equal 'End'" << endl; //Check
			cout << current << endl; //Check
			if (current == "END") {
				break;
			}
			getline(infile, current);
			if (current == "") {
				continue;
			}
			else if (current == "Class") {
				getline(infile, current);
				temp->name = current;
			}
			else if (current == "ID") {
				getline(infile, current);
				temp->id = current;
			}
			else if (current == "Credits") {
				getline(infile, current);
				temp->credits = current;
			}
			else if (current == "Type") {
				getline(infile, current);
				temp->type = current;
			}
			else if (current == "Max") {
				getline(infile, current);
				temp->maxCapacity = current;
			}
			else if (current == "Days") {
				getline(infile, current);
				temp->daysOfWeek = current;
			}
			else if (current == "Start") {
				getline(infile, current);
				temp->start = current;
			}
			else if (current == "End") {
				getline(infile, current);
				temp->end = current;
			}
			else if (current == "Room") {
				getline(infile, current);
				temp->classroom = current;
			}
			else if (current == "Date") {
				for (int x = 0; x < 6; x++) {
					getline(infile, current);
					temp->date = temp->date + "/" + current;
				}
				cout << temp->date << endl; //Check
			}
			else {
				continue;
			}
		}
		cout << "'END' loop ended" << endl; //Check
		if (head == NULL) {
			pos = temp;
			head = temp;
			tail = temp;
		}
		else {
			pos->previous = pos;
			pos->next = temp;
			pos = pos->next;
			tail = pos;
		}
		getline(infile, current);
	}
	cout << "'END OF LIST' loop ended" << endl; //Check
	infile.close();
}