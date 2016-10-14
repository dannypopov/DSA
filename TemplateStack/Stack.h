#ifndef STACK_H
#define STACK_H
template <typename TYPE>
class Stack
{
	class Node
	{
	public:
		TYPE m_data;
		Node* m_next;
		Node(TYPE data, Node* next = nullptr);
	};
private:
	Node* m_top;
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
	bool ifEmpty() const;
	//
private:
	void iniatilze();
	void unleashData();
	void copyData(Stack const&);
};

template <typename TYPE>
Stack<TYPE>::Node::Node(TYPE data, Node * next)
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
	m_top = new Node(element, m_top);
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
	Node* old = m_top;
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
bool Stack<TYPE>::ifEmpty() const
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
	Node* p;
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
	if (other.ifEmpty())
		return;
	Node<TYPE> *mine, *their;
	try
	{
		m_top = new(std::nothrow) Node(other.m_top->m_data);
		mine = m_top;
		their = other.m_top->m_next;
		while (their)
		{
			mine->m_next = next Node(their->m_data);
			mine = mine->m_next;
			their = their->m_next;
		}
		size = other.m_size;
	}
	catch (std::bad_alloc&)
	{
		unleashData();
		throw;
	}
}

#endif // !STACK_H