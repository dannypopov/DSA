#ifndef STACK_H
#define STACK_H
template<typename type>
class Box
{
public:
	Box<type>* m_next;  // pointer to the next Box
	type m_data;  // the actual data 
	Box(type data, Box<type>*next = nullptr);
};
template<typename type>
class dStack
{
private:
	Box<type>* m_top;
	int m_size;
	Box<type>* tmpBox;
public:
	dStack();
	~dStack();
	bool empty() const;
	int size();
	void push(const type&);
	bool pop(type&);
	type& peek()const;
	Box<type>* top();
	void print() const;
	void init();
};

template<typename type>
inline dStack<type>::dStack()
{
	init();
}

template<typename type>
inline dStack<type>::~dStack()
{
	Box<type>* boxPointer;
	while (m_top)
	{
		boxPointer = m_top;
		delete[] boxPointer;
		m_top = m_top->m_next;
	}
	init();
}

template<typename type>
inline bool dStack<type>::empty() const
{
	return (m_size == 0) ? true : false;
}
template<typename type>
inline int dStack<type>::size()
{
	return m_size;
}
template<typename type>
inline void dStack<type>::push(const type &newElement)
{
	m_top = new Box<type>(newElement, m_top);
	++m_size;
}
template<typename type>
inline bool dStack<type>::pop(type &returnElement)
{
	if (this->empty())
	{
		return false;
	}
	else
	{
		returnElement = m_top->m_data;
		Box<type>* boxPointer = m_top;
		m_top = m_top->m_next;
		delete[] boxPointer;
		--m_size;
		return true;
	}
}
template<typename type>
inline type & dStack<type>::peek() const
{
	type topData = m_top->m_data;
	return topData;
}
template<typename type>
inline Box<type>* dStack<type>::top()
{
	Box<type>* _top;
	_top = m_top;
	return _top;
}
template<typename type>
inline void dStack<type>::print() const
{
	if (this->empty())
	{
		std::cerr << "Nothing to display\n";
		return;
	}
	Box<type>* boxPointer;
	boxPointer = m_top;
	while (boxPointer != nullptr)
	{
		std::cout << boxPointer->m_data << std::endl;
		boxPointer = boxPointer->m_next;
	}
}

template<typename type>
inline void dStack<type>::init()
{
	this->m_size = 0;
	this->m_top = nullptr;
}

template<typename type>
inline Box<type>::Box(type data, Box<type>* next) :m_data(data), m_next(next)
{
}
#endif // !STACK_H
