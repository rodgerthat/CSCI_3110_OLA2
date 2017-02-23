/*
 * File:	main.cpp
 * Author:	Norris, Joel R.
 * Course:	CSCI 3110
 * Instructor:	Zhijiang Dong
 * Date:	Feb. 10 2017
 *
 * Purpose: This file is a part of the 2nd open lab assignment, which 
 * includes Student.h, Student.cpp, Roster.h, Roster.cpp, 
 * and main.cpp. This file is the main program logic
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Student.h"
#include "Roster.h"


const int NUM_STUDENTS = 17;
const std::string FILENAME = "point.dat";


int main() {

	std::string cnumber;

	Roster roster("CSCI_3110");

	// First, read all student information from the text file
	// and store them in an array of Student objects, within the Roster Class 

	roster.readStudentRecord(FILENAME);

	// Calculate  total  score  and  final  letter  grade.  The 
	// total score  is  the  sum  of  CLA,  OLA, Quiz, Homework, Exam and Bonus. 
	// There will be five letter grades, A(>=90), B(>=80), 
	// C(>=70),   D(>=60),   and   F(<60).   The   letter   grade   is   
	// determined  based  on  the  total  score.    For  example,  if  the  
	// term  grade  is  79,  then  the  letter  grade  is  C,  and  if  the  
	// term grade is 89, then the letter grade is B. 
	roster.calculateTotalScore();


	// Prompt  user  to  input  a  valid  c#,  and  the  program  display  
	// all information of the student with the given c#, including 
	// the total score and final letter grade. 
	std::cout << "Please enter the student's c-number: ";
	std::cin >> cnumber;
	
	roster.displayStudent(cnumber);

	// Then  display  information  of  all  students,  including  total  
	// score and final letter grade. 
	roster.printTableHeader();
	roster.displayStudentsInfo();

	return 0;

}

