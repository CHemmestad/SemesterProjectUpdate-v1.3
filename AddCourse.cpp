#include "AddCourse.h"
#include "Course.h"

AddCourse::AddCourse() {
}

void AddCourse::addCourse() {
	Course course;
	Date date;

	ofstream outfile;
	outfile.open("CoursesTemp.txt");
	//continues linked list with new information

	ifstream infile;
	infile.open("Courses.txt");
	//adds current information to a linked list
	while (infile) {
		string current;
		getline(infile, current);
		outfile << current << endl;
	}
	infile.close();

	bool con = true;
	string yes_no = "Y";

	while (con) {
		if (con == false) {
			break;
		}
		course.initializeName();
		course.initializeId();
		course.initializeCredits();
		cin.ignore();
		course.initializeType();
		course.initializeMaxCapacity();
		cin.ignore();
		course.initializeDaysOfWeek();
		course.initializeStart();
		course.initializeEnd();
		cin.ignore();
		course.initializeClassroom();

		outfile << course.getName() << endl;
		outfile << course.getId() << endl;
		outfile << course.getCredits() << endl;
		outfile << course.getType() << endl;
		outfile << course.getMaxCapacity() << endl;
		outfile << course.getDaysOfWeek() << endl;
		outfile << course.getStart() << endl;
		outfile << course.getEnd() << endl;
		outfile << course.getClassroom() << endl;

		system("cls");

		cout << "Start date : " << endl;
		date.initializeStartYear();
		date.initializeStartMonth();
		date.initializeStartDay();

		outfile << date.getStartYear() << endl;
		outfile << date.getStartMonth() << endl;
		outfile << date.getStartDay() << endl;

		cout << "End date : " << endl;
		date.initializeEndYear();
		date.initializeEndMonth();
		date.initializeEndDay();

		outfile << date.getEndYear() << endl;
		outfile << date.getEndMonth() << endl;
		outfile << date.getEndDay() << endl;

		outfile << "END";

		cout << "Add another course? Y/N : ";
		cin >> yes_no;
		if (yes_no != "Y" && yes_no != "y") {
			con = false;
		}
		system("cls");
	}

	outfile.close();

	remove("Courses.txt");
	rename("CoursesTemp.txt", "Courses.txt");

	course.printCourse();
	date.printDate();
}