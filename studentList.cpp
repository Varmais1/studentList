#include <iostream>
#include <vector>
#include <cstring>
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

Student* userAddNewStudent() {
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
Student* newStudent(char firstName[], char lastName[], int id, float GPA);

int main() {
  //Student* student = userAddNewStudent();
  //displayStudent(student);
  char fname[15];
  char lname[15];
  strcpy(fname, "Ishaan");
  strcpy(lname, "Varma");
  Student* student2 = newStudent(fname,lname,418487,4.00);
  displayStudent(student2);



  delete student2;
  return 0;
}

void displayStudent(Student* student) {
  cout << "First name: " << student->firstName << endl;
  cout << "Last name: " << student->lastName << endl;
  cout << "Student ID: " << student->id << endl;
  cout << "Student's GPA: " << student->GPA << endl;
}

Student* newStudent(char firstName[15], char lastName[15], int id, float GPA) {
  Student* newLearner = new Student();
  newLearner->firstName = firstName;
  newLearner->lastName = lastName;
  newLearner->id = id;
  newLearner->GPA = GPA;
  return newLearner;
}
