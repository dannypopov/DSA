#include "Trie.h"
#include <iostream>
void Node::copyData(const Node &other)
{
	this->setValue(other.getValue());
	this->setData(other.getData());
}

void Node::unleashData()
{
	delete[] m_data;
	m_data = nullptr;
	m_value = -1;
	f

}

Node::Node(char * data, int value) :m_value(value)
{
	if (data != nullptr)
	{
		setData(data);
	}
}

Node::Node(const Node &other)
{
	unleashData();
	copyData(other);
}

Node & Node::operator=(const Node &rhs)
{
	if (this != &rhs)
	{
		unleashData();
		copyData(rhs);
	}
	return *this;
}

Node::~Node()
{
	unleashData();
}

int Node::getValue() const
{
	return m_value;
}

const char * Node::getData() const
{
	if (m_data != nullptr)
	{
		return m_data;
	}
	return "";
}

void Node::setData(const char *newData)
{
	if (m_data != newData)
	{
		int newSize = strlen(newData);
		m_data = new char[newSize + 1];
		strcpy_s(m_data, strlen(newData) + 1, newData);
	}
}

void Node::setValue(int newValue)
{
	m_value = newValue;
}
