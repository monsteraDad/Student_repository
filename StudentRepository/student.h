//
//  student.h
//
//  Created by monsteraDad on 2/23/21.
//

#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Student {

    public:
    
    // constraint for numDaysComp array
    const static int SIZE = 3; //needs to be static 
    
    //default student constructo
    Student();
    
    //parameterized contructor 
    Student(string ID, string firstN, string lastN, string EmailAddress, int age, int numDays[], DegreeProgram degreeP);
    
    //destructor
    ~Student();
    
    //accessors
    string GetStudentID();
    string GetFirtName();
    string GetLastName();
    string GetEmailAddress();
    int GetStudentAge();
    int* GetNumDayComp();
    DegreeProgram GetDegreeProgram();
    
    //setters
    void SetStudentID(string ID);
    void SetFirstName(string firstN);
    void SetLastName(string lastN);
    void SetEmailAddress(string EmailAddress);
    void SetStudentAge(int age);
    void SetDegreeProgram(DegreeProgram degreeP);
    void SetNumDayComp(int numDays[]); //pointer array
    
    // function to print specific student data
    void Print();
    
    private:
    
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int* numDayComp;    //array of 3 elements where each element is a number of days it                       takes to complete a class
    DegreeProgram degreeProgram;

};




#endif /* student_h */
