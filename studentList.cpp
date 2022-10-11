#include <iostream>
#include <vector>
#include <cstring>
/* Name: Ishaan Varma
What this file does: Has everything for the student list project
Date: 10/11/2022
*/
// makes it so that I don't have to type std:: before every cout and cin
using namespace std;

//constant character arrays in order to recognize commands
const char add[4] = {'a','d','d','\0'};
const char print[6] = {'p','r','i','n','t','\0'};
const char quit[5] = {'q','u','i','t','\0'};
const char deleter[7] = {'d','e','l','e','t','e','\0'};

//struct to hold student information
struct Student {
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
};

//method to add a new student by getting input from the user, returns a student pointer
Student* userAddNewStudent() {
  Student* newLearner = new Student();
  cout << "Type in the student's first name." << endl;
  cin >> newLearner->firstName;
  cout << "Type in the student's last name." << endl;
  cin >> newLearner->lastName;
  cout << "Type in the student's id." << endl;
  cin >> newLearner->id;
  cout << "Type in the student's GPA." << endl;
  cin >> newLearner->GPA;
  return newLearner;
}
//initializes methods
void displayStudent(Student* student);
void lowercase(char sentence[]);

//main
int main() {
  //Student* student = userAddNewStudent();
  //displayStudent(student);
  //variable that determines if the program is running or not
  bool run = true;
  //where all of the students are stored
  vector<Student*> ogList;
  vector<Student*>* studentList = &ogList;
  //where the user's command is stored
  char command[7];
  //run the program
  while(run == true) {
    //get the command and make it lowercase
    cout << "Type in add, delete, print, or quit." << endl;
    cin >> command;
    lowercase(command);
    //cout << "command: " << command << endl;
    /*int whileValue = 0;
    bool nullCheck = false;
    while(nullCheck == false && whileValue < 7) {
      cout << "command[" << whileValue << "]: " << command[whileValue] << endl;
      if(command[whileValue] == '\0') {
	nullCheck = true;
      }
      whileValue++;
      }*/

    //int addCheck = strcmp(command,add);
    //cout << "addCheck: " << addCheck;
    //cout << "delete check: " << strcmp(command,deleter) << endl;
    //if the command is "add", make a new student and put it ins the studentList vector
    if(strcmp(command,add) == 0) {
      studentList->push_back(userAddNewStudent());
    }
    //if the command is print, display all students using an iterator
    else if(strcmp(command,print) == 0) {
      for(auto i = studentList->begin(); i != studentList->end(); ++i) {
	displayStudent((*i));
      }
    }
    //if the command is delete, get the student ID of the student to be removed, and remove that student from the vector
    else if(strcmp(command,deleter) == 0) {
      int studentID = 0;
      cout << "Type in the students ID." << endl;
      cin >> studentID;
      for(auto i = studentList->begin(); i != studentList->end(); ++i) {
	if((*i)->id == studentID) {
	  studentList->erase(i);
	  break;
	}
      }
    }
    //if the command is quit, set run to false
    else if(strcmp(command,quit) == 0) {
      run = false;
    }
    //if an invalid command is entered, notify the user
    else {
      cout << "Your command was invalid." << endl;
    }
    
  }
  
  //delete all students, as they are in the heap
  for(auto i = studentList->begin(); i != studentList->end(); ++i) {
    delete *i;
  }
  
  //end the program
  return 0;
}

//method to display a student
void displayStudent(Student* student) {
  //print out the first name, last name, student id, and GPA to 2 decimal points
  cout << "First name: " << student->firstName << endl;
  cout << "Last name: " << student->lastName << endl;
  cout << "Student ID: " << student->id << endl;
  int studentGPA100 = (int)((student->GPA+0.005)*100);
  double studentGPA = (double)(studentGPA100)/100;
  cout << "Student's GPA: " << studentGPA << endl;
}

//makes all letters lowercase
void lowercase(char sentence[]) {
  //iterating variable
   int i = 0;
   //go through the char array
   while(true) {
     int charVal = (int) sentence[i];
     //if the letter is capital, make it lowercase using ASCII
     if(65<=charVal && charVal <= 90) {
       sentence[i] = (char)(charVal+32);
     }
     //if the character is the null character, 
     else if(sentence[i] == '\0') {
       break;
     }
     //increment the variable
     i++;
   }

   
 }
