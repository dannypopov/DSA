#ifndef OPERANDS_H
#define  OPERANDS_H
/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Jordan Liliyanov Popov
* @idnumber 45166
* @task 1
* @compiler VC
*
*/
#include "Operator.h"
#include <iostream>
#include <fstream>

const int OPERATORS_FILE_MAX_LINE_SIZE = 6;

class Operators
{
private:
	Operator* m_operators;
	size_t m_capacity;
	size_t m_index;
private:
	void copyData(const Operators&);
	void unleashData();
	void resize(int);
public:
	//BiG 4
	Operators(Operator* operands = nullptr, size_t capacity = 0, size_t index = 0);
	~Operators();
	Operators(const Operators&);
	Operators& operator=(const Operators&);
	//Get
	size_t getCapacity() const;
	size_t getIndex() const;
	//Set
	//
	Operator& operator[](int);
	const Operator& operator[](int)const;
	//
	void add(Operator);
	void init(size_t);
	//
	void readFromFile(const char*);
	size_t getNumberOfOperandsFile(const char*);
};
std::ostream& operator<<(std::ostream&, const Operators&);
#endif
