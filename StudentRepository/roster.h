//
//  roster.h
//  jaredBreyerScriptProgPA
//
//  Created by Jared Breyer on 2/23/21.
//

#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Roster{

public:
    
    //set a size to the number of students, in this case there is 6. (including the data that was added) 
    int maxSize = 6;
    
    //set the tail of the pointer for the rosterClassArray
    int tail;
    
    //default constructor for roster class
    Roster();
    //construct Roster class with parameter of num of students
    Roster(int maxSize);
    
    //creation of pointer array to house instances of students.
    Student** classRosterArray;
    
    // roster deconstructor.
   ~Roster();
    
    //2ab parsethen add function
    void parseAndAdd(string studentData);
    
    //add student function
    void add(string studentID, string firstN, string lastN, string EmailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    // function to remove student from classRosterArray
    bool remove(string studentID);
    
    // function to print a complete tab separated list of student data
    void printAll();
    
    // function to print students average day in courses
    void printAverageDaysInCourse(string studentID);
    
    
    // function to print invalid emails.
    void printInvalidEmails();
    
    // function to print students degree program
    void printDegreeProgram(DegreeProgram degreeProgram);
};

#endif /* roster_h */
