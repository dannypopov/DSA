#include "Operators.h"
#include "myStack.h"
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
void Operators::copyData(const Operators& other)
{
	m_operators = new Operator[other.getCapacity()];
	for (int i = 0; i < other.getIndex(); ++i)
	{
		m_operators[i] = other.m_operators[i];
	}
	m_capacity = other.getCapacity();
	m_index = other.getIndex();
}

void Operators::unleashData()
{
	delete[] m_operators;
	m_operators = nullptr;
	m_capacity = 0;
	m_index = 0;
}
Operators::Operators(Operator* operands, size_t capacity, size_t index) :m_operators(nullptr), m_capacity(capacity), m_index(index)
{

}

Operators::Operators(const Operators&other)
{
	//unleashData();
	copyData(other);
}

Operators::~Operators()
{
	unleashData();
}
Operators& Operators::operator=(const Operators& other)
{
	if (this != &other)
	{
		unleashData();
		copyData(other);
	}
	return *this;
}
size_t Operators::getCapacity() const
{
	return m_capacity;
}

size_t Operators::getIndex() const
{
	return m_index;
}

void Operators::resize(int newSize)
{
	Operator* newOperands = new Operator[newSize];
	size_t elementsToCopy;
	if (newSize < m_capacity)
	{
		elementsToCopy = newSize;
	}
	else
	{
		elementsToCopy = m_capacity;
	}
	for (int i = 0; i < elementsToCopy; ++i)
	{
		newOperands[i] = m_operators[i];
	}
	delete[] m_operators;
	m_operators = newOperands;
	m_capacity = newSize;
}

Operator& Operators::operator[](int index)
{
	if (index >= m_capacity)
	{
		throw std::out_of_range("Invalid index");
	}
	return m_operators[index];
}

const Operator& Operators::operator[](int index) const
{
	if (index >= m_capacity)
	{
		throw std::out_of_range("Invalid index");
	}
	return m_operators[index];
}

void Operators::add(Operator Element)
{
	if (m_index >= m_capacity)
	{
		size_t newSize = (m_capacity == 0 ? 2 : m_capacity * 2);
		resize(newSize);
	}
	m_operators[m_index++] = Element;
}

void Operators::init(size_t size)
{
	m_operators = new Operator[size];
	m_capacity = size;
	m_index = 0;
}

void Operators::readFromFile(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	m_capacity = getNumberOfOperandsFile(fileName);
	Operators::init(m_capacity);
	char str[OPERATORS_FILE_MAX_LINE_SIZE]; // 0 - symbol , 2-operand , 4 - associative
	while (file)
	{
		file.getline(str, OPERATORS_FILE_MAX_LINE_SIZE);
		if (file) // if just to be sure not to read last line
		{
			Operator newOperand(str[0], str[2], str[4] - '0');
			this->add(newOperand);
		}
	}
	file.close();
}

size_t Operators::getNumberOfOperandsFile(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);
	size_t numberOfLines = 0;
	char ch;
	while (file.get(ch))
	{
		if (ch == '\n')
		{
			numberOfLines++;
		}
	}
	file.close();
	return numberOfLines;
}
std::ostream& operator<<(std::ostream& out, const Operators& arr)
{
	for (int i = 0; i < arr.getIndex(); ++i)
	{
		out << arr[i];
		out << "\n";
	}
	out << "\n";
	return out;
}
