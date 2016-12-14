#include "Operator.h"
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
void Operator::copyData(const Operator&other)
{
	setSymbol(other.getSymbol());
	setOperator(other.getOperator());
	setAssociative(other.getAssociative());
}

void Operator::unleashData()
{
	m_operator = '0';
	m_symbol = '0';
	m_associative = 0;
}

Operator::Operator(const Operator&other)
{
	copyData(other);
}

Operator::Operator(char symbol, char operatorr, int associative) :m_symbol(symbol), m_operator(operatorr)
{
	setAssociative(associative);
}

Operator::~Operator()
{
	unleashData();
}

Operator& Operator::operator=(const Operator&other)
{
	if (this != &other)
	{
		unleashData();
		copyData(other);
	}
	return *this;
}
const char Operator::getSymbol() const
{
	return m_symbol;
}

int Operator::getAssociative() const
{
	return m_associative;
}

char Operator::getOperator() const
{
	return m_operator;
}

void Operator::setSymbol(char newSymbol)
{
	m_symbol = newSymbol;
}

void Operator::setOperator(char newOperator)
{
	m_operator = newOperator;
}

void Operator::setAssociative(int newAssociative)
{
	if (newAssociative == 0)
	{
		m_associative = 0;
	}
	else if (newAssociative == 1)
	{
		m_associative = 1;
	}
	else
	{
		std::cerr << "Bad associative 0 or 1\n";
		m_associative = -1;
	}
}

void Operator::print() const
{
	std::cout << "Operator:" << m_operator << std::endl;
	std::cout << "Associative:" << m_associative << std::endl;
	std::cout << "Symbol:" << m_symbol << std::endl;
}

int Operator::getPriority() const
{
	switch (m_operator) {
	case '+': return 1; break;
	case '-': return 1; break;
	case '*': return 2; break;
	case '/': return 2; break;
	case '^': return 3; break;
	default: return -1; break;
	}
}

std::ostream& operator<<(std::ostream& out, const Operator& operand)
{
	out << "Operator:"  << operand.getOperator() << std::endl;
	out << "Associative:" << operand.getAssociative() << std::endl;
	out << "Symbol:" << operand.getSymbol() << std::endl;
	return out;
}
