#include <iostream>
/* Name: Ishaan Varma
What this file does: Has everything for the student list project
Date: 10/5/2022
*/
using namespace std;

struct Student {
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
};

Student* newStudent() {
  Student* newLearner = new Student();
  cout << "Type in the student's first name." << endl;
  cin.get(newLearner->firstName, 15);
  cin.get();
  cout << "Type in the student's last name." << endl;
  cin.get(newLearner->lastName, 15);
  cin.get();
  cout << "Type in the student's id." << endl;
  cin >> newLearner->id;
  cout << "Type in the student's GPA." << endl;
  cin >> newLearner->GPA;
  return newLearner;
}
void displayStudent(Student* student);


int main() {
  Student* student = newStudent();
  displayStudent(student);
}

void displayStudent(Student* student) {
  cout << "First name: " << student->firstName << endl;
  cout << "Last name: " << student->lastName << endl;
  cout << "Student ID: " << student->id << endl;
  cout << "Student's GPA: " << student->GPA << endl;
}
