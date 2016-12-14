#ifndef STACK_H
#define STACK_H
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
template <typename TYPE>
class Stack
{
	class Element
	{
	public:
		TYPE m_data;
		Element* m_next;
		Element(TYPE data, Element* next = nullptr);
	};
private:
	Element* m_top;
	int m_size;
public:
	// BIG-4
	Stack();
	~Stack();
	Stack(Stack const&);
	Stack& operator=(Stack const&);
	//
	void push(const TYPE&);
	bool pop(TYPE&);
	int getSize() const;
	bool empty() const;
	//
private:
	void iniatilze();
	void unleashData();
	void copyData(Stack const&);
};

template <typename TYPE>
Stack<TYPE>::Element::Element(TYPE data, Element * next)
{
	this->m_data = data;
	this->m_next = next;
}
template <typename TYPE>
Stack<TYPE>::Stack()
{
	iniatilze();
}
template <typename TYPE>
Stack<TYPE>::~Stack()
{
	unleashData();
}
template <typename TYPE>
Stack<TYPE>::Stack(Stack const &other)
{
	iniatilze();
	copyData(other);
}
template <typename TYPE>
Stack<TYPE> & Stack<TYPE>::operator=(Stack const &rhs)
{
	if (this != &rhs)
	{
		unleashData();
		copyData(rhs)
	}
	return *this;
}
template <typename TYPE>
void Stack<TYPE>::push(const TYPE &element)
{
	m_top = new Element(element, m_top);
	m_size++;
}
template <typename TYPE>
bool Stack<TYPE>::pop(TYPE &element)
{
	if (m_size == 0)
	{
		return false;
	}
	element = m_top->m_data;
	Element* old = m_top;
	m_top = m_top->m_next;
	delete old;
	m_size--;
	return true;
}
template <typename TYPE>
int Stack<TYPE>::getSize() const
{
	return m_size;
}
template <typename TYPE>
bool Stack<TYPE>::empty() const
{
	return m_size == 0;
}
template <typename TYPE>
void Stack<TYPE>::iniatilze()
{
	m_top = nullptr;
	m_size = 0;
}
template <typename TYPE>
void Stack<TYPE>::unleashData()
{
	Element* p;
	while (m_top)
	{
		p = m_top;
		m_top = m_top->m_next;
		delete p;
	}
	iniatilze();
}
template <typename TYPE>
void Stack<TYPE>::copyData(Stack const &other)
{
	if (this == &other)
	{
		std::cerr << "self assignment FORBIDDEN!\n";
	}
	if (other.ifEmpty())
	{
		std::cerr << "nothin` to copy\n";
	}
	Element<TYPE> *mine, *their;
	m_top = new(std::nothrow) Element(other.m_top->m_data);
	mine = m_top;
	their = other.m_top->m_next;
	while (their)
	{
		mine->m_next = next Element(their->m_data);
		mine = mine->m_next;
		their = their->m_next;
	}
	size = other.m_size;
}


#endif // !STACK_H
