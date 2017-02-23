/*
 * File:	Student.cpp
 * Author:	Norris, Joel R.
 * Course:	CSCI 3110
 * Instructor:	Zhijiang Dong
 * Date:	2017_02_11
 *
 * Purpose: This file is a part of the 1st open lab assignment, which 
 * includes Student.h, Student.cpp, Roster.h, Roster.cpp, 
 * and main.cpp. This file gives the full implementation 
 * of the class Student.
 */

#include "Student.h"
#include <iostream>


// default constructor w/ initializer list
Student::Student(void)
:m_id("c000000"), m_score(), m_total(0), m_letterGrade('F') { }

// alternate constructor, to accept arguments to initialize score values on construction
Student::Student(std::string id, int cla, int ola, int quiz, int homework, int exam, int bonus)
:m_id("c000000"), m_score(), m_total(0), m_letterGrade('F')
{
		this->setID(id);
		this->changeScore(CLA, cla);
		this->changeScore(OLA, ola);
		this->changeScore(QUIZ, quiz);
		this->changeScore(HOMEWORK, homework);
		this->changeScore(EXAM, exam);
		this->changeScore(BONUS, bonus);
}

// accessor and mutator for m_id

std::string Student::getID(void) const
{
	return this->m_id;
}

void Student::setID(std::string id)
{
	this->m_id = id;
}

// accessors and mutators for m_score

void Student::changeScore(const ScoreType scoreType, const int score)
{
	this->m_score[scoreType] = score;
	//std::cout << score << std::endl;
	//std::cout <<  this->m_score[scoreType] << std::endl;
}

int Student::getScore(const ScoreType scoreType) const
{
	return this->m_score[scoreType];
}

// accessors and mutators for m_total

int Student::getTotal(void) const
{
	return this->m_total;
}

void Student::changeTotal(const int total)
{
	this->m_total = total;
}

// accessors and mutators for m_letterGrade

char Student::getLetterGrade() const
{
	return this->m_letterGrade;
}

void Student::changeLetterGrade(const char letterGrade)
{
	this->m_letterGrade = letterGrade;
}
