//
//  roster.cpp
//
//  Created by monsteraDad on 2/23/21.
//

#include <stdio.h>
#include "roster.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor.
Roster::Roster() {
    this -> maxSize = 0;
    this -> tail = -1;
    this -> classRosterArray = nullptr;
}

//parameterized constructor.
Roster::Roster(int maxSize) {
    this -> maxSize = maxSize;
    this -> tail = -1;
    this ->classRosterArray = new Student *[maxSize];
}


// parse student data
void Roster::parseAndAdd(string studentData) {
    
    
    /*parse through data to set each variable.
     *Since data is a string containing commas we will search for instances of the commas and assign the varriables as we parse.
    */
    int parseArr[Student::SIZE]; // this will allow us to parse the student table
   
    
    // increment the tail as the program parses
    if (tail < maxSize) {
        ++tail;
    }
    
    // set a new instance of Student using the default contructor.
    this -> classRosterArray[tail] = new Student();
    
    
    //read student ID.
    int long roC = studentData.find(","); // returns index where "," is found
    classRosterArray[tail] -> SetStudentID(studentData.substr(0,roC));
    
    // read first name
    int long loC = roC + 1; // this starts the search after the last comma
    roC = studentData.find(",", loC);
    classRosterArray[tail] -> SetFirstName(studentData.substr(loC, roC - loC));
    
    // read last name
    loC = roC + 1;
    roC = studentData.find(",", loC);
    classRosterArray[tail] -> SetLastName(studentData.substr(loC, roC - loC));
    
    // read EmailAddress
    loC = roC + 1;
    roC = studentData.find(",", loC);
    classRosterArray[tail] -> SetEmailAddress(studentData.substr(loC, roC - loC));
    
    // read age
    loC = roC + 1;
    roC = studentData.find(",", loC);
    int x = stoi(studentData.substr(loC, roC - loC));
    classRosterArray[tail] -> SetStudentAge(x);

    // read days in course
    
    //course 1
    loC = roC + 1;
    roC = studentData.find(",", loC);
    parseArr[0] = stoi(studentData.substr(loC, roC - loC));
    
    //course 2
    loC = roC + 1;
    roC = studentData.find(",", loC);
    parseArr[1] = stoi(studentData.substr(loC, roC - loC));
    
    //course 3
    loC = roC + 1;
    roC = studentData.find(",", loC);
    parseArr[2] = stoi(studentData.substr(loC, roC - loC));
    
    
    // set days in cours
    classRosterArray[tail] -> SetNumDayComp(parseArr);
    
    
    // read degreeProgram
    loC = roC + 1;
    
    /*  since reading string incrementally to differensiate between SECURITY, SOFTWARE we can just look for a difference in their second letters, E or O. For the difference between SECURITY, SOFTWARE, and NETWORK we can just look at the first letter. (comparing characters at the first two indexes after the final comma) */
    
    if (studentData[loC] == 'S') {
        if(studentData[loC + 1] == 'O') {
            classRosterArray[tail] -> SetDegreeProgram(SOFTWARE);
            
        }
        else if (studentData[loC + 1] == 'E') {
            classRosterArray[tail] -> SetDegreeProgram(SECURITY);
            
        }
    }
    else if (studentData[loC] == 'N') {
        classRosterArray[tail] -> SetDegreeProgram(NETWORK);
        
    }
    
}
    
void Roster::add(string studentID, string firstN, string lastN, string EmailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    
    // put numDayComp elements in there respective indexes.
    int numDayComp[Student::SIZE];
    
    numDayComp[0] = daysInCourse1;
    numDayComp[1] = daysInCourse2;
    numDayComp[2] = daysInCourse3;
    
    //set class roster as a new student instance
    classRosterArray[tail] = new Student(studentID, firstN, lastN, EmailAddress, age, numDayComp, degreeprogram);
    
}

bool Roster::remove(string studentID) {
    //set a boolean for found
    bool found = false;
    
    //loop through array to find student id
    for ( int i = 0; i <= tail; ++i) {
        if((this -> classRosterArray[i] -> GetStudentID()) == studentID) {
            found = true;
            // delete instance of classRosterArray
            delete this -> classRosterArray[i];
            //adjust array pointers
            this -> classRosterArray[i] = this ->classRosterArray[tail];
            tail -= 1;
            cout << studentID << " Deleted!" << endl << endl;
        }
    }
        // if item is not found.
        if (!found) {
            cout << "Student Not Found with ID of " << studentID << endl << endl;
        }
       
    
    return found;
}

// function to print student data in tabular format. calls Print() from student.cpp
void Roster::printAll() {
    cout << "Roster:" << endl;
    for(int i = 0; i <= this->tail; ++i) {
        this->classRosterArray[i]->Print();
    }
    cout << endl << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    // check if student id found
    bool found = false;
    //
    for(int i = 0; i <= tail; ++i) {
        if (this -> classRosterArray[i] -> GetStudentID() == studentID) {
            found = true;
            //create a way to access the ptr of numDayComp array.
            int* ptr = classRosterArray[i] -> GetNumDayComp();
            // print average by adding each instance of pointer together.
            cout << studentID << "'s average number of days in a class is, " << ((ptr[0] + ptr[1] + ptr[2]) / 3) << endl << endl;
        }
    }
    if (!found) {
        cout << "Student Not Found with ID of " << studentID << endl; 
    
    // if not found print error statement
    // if found, average the days in the 3 classes
    }
}

void Roster::printInvalidEmails() {
    
    cout << "Printing Invalid Emails:" << endl;
    // if the email does not meet criteria of valid email print.
    // loop through to catch emails
    for (int i = 0; i < maxSize; ++i) {
        //assign email to a string var
        string email = this -> classRosterArray[i] -> GetEmailAddress();
        //valid emails contain '@', '.', and do not contain ' '.
        if(email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
                cout << email << endl;
        }
    }
    cout << endl;
    
}

void Roster::printDegreeProgram(DegreeProgram degreeProgram) {
    //prints out student info for a dree program specified.
    cout << "Printing students in " << DegreeProgStr[degreeProgram] << " Program:" << endl;
    // if student has instance of degree program print the students info.
    for (int i = 0; i < maxSize; ++i) {
        
        if(this -> classRosterArray[i] -> GetDegreeProgram() == degreeProgram){
            // print students in specific degree program?
            this -> classRosterArray[i] -> Print();
        }
    }
   cout << endl << endl;
}

//roster deconstructor
Roster::~Roster() {
    for(int i = 0; i <= maxSize; ++i) {
        delete this -> classRosterArray[i];
        
    }
  
}


