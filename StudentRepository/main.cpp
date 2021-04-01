//
//  main.cpp
//  jaredBreyerScriptProgPA
//
//  Created by Jared Breyer on 2/23/21.
//

#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
using namespace std;

int main() {
    
    // print out my information.
    cout << "Jared Breyer" << endl;
    cout << "Scripting and Programing" << endl;
    cout << "Student ID: 001032849" << endl;
    cout << "C++" << endl << endl;
    
    //student table data with my student information added to the end. 
    const string studentData[5] ={"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jared,Breyer,jbreyer@wgu.edu,24,40,25,30,SOFTWARE"
    };
    
    //var set to the number of students, including my information.
    int classSize = 5;
    
    //creatting the instance of Roster
    
    Roster* roster = new Roster(classSize);
    //looping to parse each string in student data array.
    for(int i = 0; i < classSize; ++i) {
        roster -> parseAndAdd(studentData[i]);
    }
    
    //print roster
    roster->printAll();
    
    //print invalid emails
    roster->printInvalidEmails();
    
    //print average days in class
    roster -> printAverageDaysInCourse("A3");
   
    //print by degree
    roster -> printDegreeProgram(SOFTWARE);
    
    // remove A3
    roster ->remove("A3");
    roster->printAll();
    roster -> remove("A3");
    
    
    // implement deconstructor to release memory. 
   roster -> ~Roster();
    return 0;
       
}
