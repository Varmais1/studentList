#include <iostream>
#include <vector>
#include <cstring>
/* Name: Ishaan Varma
What this file does: Has everything for the student list project
Date: 10/5/2022
*/
using namespace std;


const char add[4] = {'a','d','d','\0'};
const char print[6] = {'p','r','i','n','t','\0'};
const char quit[5] = {'q','u','i','t','\0'};
const char deleter[7] = {'d','e','l','e','t','e','\0'};


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
void lowercase(char sentence[]);


int main() {
  //Student* student = userAddNewStudent();
  //displayStudent(student);
  bool run = true;
  vector<Student*> ogList;
  vector<Student*>* studentList = &ogList;
  char command[7];
  while(run == true) {
    cin >> command;
    lowercase(command);
    if(strcmp(command,add) == 0) {
      studentList->push_back(userAddNewStudent());
    }
    else if(strcmp(command,print) == 0) {
      for(auto i = studentList->begin(); i != studentList->end(); ++i) {
	displayStudent((*i));
      }
    }
    else if(strcmp(command,deleter) == 0) {
      int studentID = 0;
      cin >> studentID;
      for(auto i = studentList->begin(); i != studentList->end(); ++i) {
	if((*studentList)[*i]->id == studentID) {
	  studentList->erase(i);
	}
      }
    }
    else if(strcmp(command,quit) == 0) {
      run = false;
    }
  }
  
  
  
  
  
  
  for(auto i = studentList->begin(); i != studentList->end(); ++i) {
    delete **i;
    delete *i;
  }
  
  
  return 0;
}

void displayStudent(Student* student) {
  cout << "First name: " << student->firstName << endl;
  cout << "Last name: " << student->lastName << endl;
  cout << "Student ID: " << student->id << endl;
  cout << "Student's GPA: " << student->GPA << endl;
}


void lowercase(char sentence[]) {
   int i = 0;
   while(i<4) {
     if(65<(int) sentence[i] < 90) {
       sentence[i] = (char)((int)(sentence[i])+32);
     }
   }

   
 }
