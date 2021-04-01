//
//  student.cpp
//
//  Created by monsteraDad on 2/23/21.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "student.h"

// default student constructor
Student::Student() {
    this -> studentID = "none";
    this -> firstName = "none";
    this -> lastName = "none";
    this -> emailAddress = "none";
    this -> studentAge = 0;
    this -> numDayComp = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        this -> numDayComp[i] = 0; //initialize the number of days to complete to [0,0,0]
    }
    this -> degreeProgram = SECURITY; // initialized to a random member of DegreeProgram enumerator. 
}

//parameterized constructor need to add numdays to complete
Student::Student(string ID, string firstN, string lastN, string EmailAddress, int age, int numDays[], DegreeProgram degreeP) {
    
    this -> studentID = ID;
    this -> firstName = firstN;
    this -> lastName = lastN;
    this -> emailAddress = EmailAddress;
    this -> studentAge = age;
    //setting up the number of days it takes to complete array with 3 elements.
    this -> numDayComp = new int[SIZE];
    for(int i = 0; i < SIZE; ++i){
        this->numDayComp[i] = numDays[i];
    }
    
    this -> degreeProgram = degreeP;
    
}

//getters
string Student::GetStudentID() {
    return studentID;
}

string Student::GetFirtName() {
    return firstName;
}

string Student::GetLastName() {
    return  lastName;
}

string Student::GetEmailAddress() {
    return emailAddress;
}

int Student::GetStudentAge() {
    return studentAge;
}

int* Student::GetNumDayComp() {
    return numDayComp;
}

DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}

//setters
void Student::SetStudentID(string ID) {
    this -> studentID = ID;
}

void Student::SetFirstName(string firstN) {
    this -> firstName = firstN;
}

void Student::SetLastName(string lastN) {
    this -> lastName = lastN;
}

void Student::SetEmailAddress(string EmailAddress) {
    this -> emailAddress = EmailAddress;
}

void Student::SetStudentAge(int age) {
    this -> studentAge = age;
}

void Student::SetDegreeProgram(DegreeProgram degreeP) {
    this -> degreeProgram = degreeP;
}

void Student::SetNumDayComp(int numDays[]) {
    for (int i = 0; i < SIZE; ++i) {
        this->numDayComp[i] = numDays[i];
    }
}

// funtion to print student data.
void Student::Print() {
    
    cout << GetStudentID() << "\t" << "First Name: " << GetFirtName() << "\t" << "Last Name: " << GetLastName() <<  "\t" << "Age: " << GetStudentAge();
    int *numDayComp = GetNumDayComp();
    cout << "\t" << "daysInCourse:" << "{" << numDayComp[0] << "," << numDayComp[1] << "," << numDayComp[2] << "}" << "\t" << "Degree Program: " << DegreeProgStr[GetDegreeProgram()] << endl;
    
}

//destructor
Student::~Student() {
    if (numDayComp != nullptr) {
        delete [] numDayComp;
        numDayComp = nullptr; 
    }
}


 




