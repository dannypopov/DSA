#ifndef OPERAND_H
#define OPERAND_H
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
#include <iostream>
class Operator
{
private:
	char  m_symbol;
	char m_operator;
	int m_associative;
	void copyData(const Operator&);
	void unleashData();
public:
	// BiG 4
	Operator(char symbol = '0',char operatorr ='0',int associative = 0);
	Operator(const Operator&);
	~Operator();
	Operator& operator=(const Operator&);
	//GET
	const char getSymbol() const;
	int getAssociative() const;
	char getOperator() const;
	//SET
	void setSymbol(char);
	void setOperator(char);
	void setAssociative(int);
	//Print
	void print() const;
	//
	int getPriority()const;
};
std::ostream& operator<<(std::ostream&, const Operator&);
#endif // OPERAND_H
