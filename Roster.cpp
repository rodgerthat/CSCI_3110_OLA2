/*
 * File:	Roster.cpp
 * Author:	Norris, Joel R.
 * Course:	CSCI 3110
 * Instructor:	Zhijiang Dong
 * Date:	2017_02_11
 *
 * Purpose: This file is a part of the 1st open lab assignment, which 
 * includes Student.h, Student.cpp, Roster.h, Roster.cpp, 
 * and main.cpp. This file gives the full implementation 
 * of the class Roster.
 */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "Roster.h"


Roster::Roster(std::string courseName)
:m_courseName("CSCI_3110")
{
	this->m_courseName = courseName;
}

void Roster::readStudentRecord(std::string fileName)
{

		std::string c_number;
		int		cla, ola, quiz, homework, exam, bonus;

		std::ifstream inFile;

		inFile.open(fileName);

		int i=0;
		std::string line;
		// skip the table header in the file
		getline( inFile, line);
		
		// loop through the lines in the file, create a new Student object for each
		// assign relevant score data to the new Student object

		while( getline(inFile, line) ) {

			//std::cout << line << std::endl;

			std::stringstream ss(line);
			ss >> c_number
				>> int(cla)
				>> int(ola)
				>> int(quiz)
				>> int(homework)
				>> int(exam)
				>> int(bonus);

			// instantiate a new student object, based on the incoming data
			Student student = Student(c_number, cla, ola, quiz, homework, exam, bonus);
			// place it in the roster's m_students array
			this->m_students[i] = student;

			i++;

			this->m_studentNum = i;		// start counting the number of students 

		}



}

// Calculate  total  score  and  final  letter  grade.  The 
// total score  is  the  sum  of  CLA,  OLA, Quiz, Homework, Exam and Bonus. 
// There will be five letter grades, A(>=90), B(>=80), 
// C(>=70),   D(>=60),   and   F(<60).   The   letter   grade   is   
// determined  based  on  the  total  score.    For  example,  if  the  
// term  grade  is  79,  then  the  letter  grade  is  C,  and  if  the  
// term grade is 89, then the letter grade is B. 
void Roster::calculateTotalScore() {
	
	int cla, ola, quiz, homework, exam, bonus;
	int totalScore;

	// loop through the array of student objects
	for (int i=0; i < m_studentNum; i++) {

		// for each student, pull out their score data and add to get totalScore
		cla =		this->m_students[i].getScore(Student::CLA);
		ola =		this->m_students[i].getScore(Student::OLA);
		quiz =		this->m_students[i].getScore(Student::QUIZ);
		homework =	this->m_students[i].getScore(Student::HOMEWORK);
		exam =		this->m_students[i].getScore(Student::EXAM);
		bonus =		this->m_students[i].getScore(Student::BONUS);

		totalScore = cla + ola + quiz + homework + exam + bonus;
		this->m_students[i].changeTotal(totalScore);

		// then compute the letter grade for each, and assign back to that student
		this->m_students[i].changeLetterGrade( this->calculateLetterGrade(totalScore) );
		
	}

}

// There will be five letter grades, A(>=90), B(>=80), 
// C(>=70),   D(>=60),   and   F(<60).   The   letter   grade   is   
// determined  based  on  the  total  score.    For  example,  if  the  
// term  grade  is  79,  then  the  letter  grade  is  C,  and  if  the  
// term grade is 89, then the letter grade is B. 
char Roster::calculateLetterGrade( int totalScore ) {
	
	if (totalScore >= 90)		return 'A';
	else if (totalScore >= 80)	return 'B';
	else if (totalScore >= 70)	return 'C';
	else if (totalScore >= 60)	return 'D';
	else						return 'F';
}

void Roster::displayStudent( std::string cNumber ) {
	
	// loop through student objects in array, check for matching cNumber
	for (int i=0; i < m_studentNum; i++) {
		
		if ( cNumber == this->m_students[i].getID() ) { 

			std::cout << std::setw(TABLE_COLUMN_WIDTH) <<
			m_students[i].getID() << "\t" <<
			m_students[i].getScore(Student::CLA) << "\t" <<
			m_students[i].getScore(Student::OLA) << "\t" <<
			m_students[i].getScore(Student::QUIZ) << "\t" <<
			m_students[i].getScore(Student::HOMEWORK) << "\t\t" <<
			m_students[i].getScore(Student::EXAM) << "\t" <<
			m_students[i].getScore(Student::BONUS) << "\t" <<
			m_students[i].getTotal() << "\t" <<
			m_students[i].getLetterGrade() << "\t" <<
			std::endl;
		
		}
	}

}

void Roster::displayStudentsInfo() {

	// loop through student objects in array, output all student data
	for (int i=0; i < m_studentNum; i++) {

		std::cout << std::setw(TABLE_COLUMN_WIDTH) <<
		m_students[i].getID() << "\t" <<
		m_students[i].getScore(Student::CLA) << "\t" <<
		m_students[i].getScore(Student::OLA) << "\t" <<
		m_students[i].getScore(Student::QUIZ) << "\t" <<
		m_students[i].getScore(Student::HOMEWORK) << "\t\t" <<
		m_students[i].getScore(Student::EXAM) << "\t" <<
		m_students[i].getScore(Student::BONUS) << "\t" <<
		m_students[i].getTotal() << "\t" <<
		m_students[i].getLetterGrade() <<
		std::endl;
	}

}

// print table header
void Roster::printTableHeader() {

	std::cout << std::setw(TABLE_COLUMN_WIDTH) << "\nID\tCLA\tOLA\tQuiz\tHomework\tExam\tBonus\tTotal\tFinalGrade\t" << std::endl;

}
