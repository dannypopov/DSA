#ifndef QUEUE_H
#define  QUEUE_H
template<typename type>
class Box
{
public:
	Box<type>* m_previous;
	Box<type>* m_next;
	type m_data;
	Box(type data, Box<type>* previous = nullptr, Box<type>* next = nullptr);
};
template<typename type>
class dQueue
{
private:
	Box<type>* m_back;
	Box<type>* m_front;
	int m_size;
public:
	dQueue();
	~dQueue();
	void enqueue(const type&);
	bool dequeue(type&);
	type& peek() const;
	Box<type>* frontBox() const;
	void print() const;
	bool empty() const;
};
template<typename type>
inline dQueue<type>::dQueue()
{
	m_back = nullptr;
	m_front = nullptr;
	m_size = 0;
}

template<typename type>
inline dQueue<type>::~dQueue()
{
	Box<type>* boxPointer;
	while (m_front)
	{
		boxPointer = m_back;
		m_back = m_back->m_next;
		delete[] boxPointer;
	}
	m_back = nullptr;
	m_front = nullptr;
	m_size = 0;
}

template<typename type>
inline void dQueue<type>::enqueue(const type &newElement)
{
	Box<type>* newBox = new Box<type>(newElement, nullptr, m_back);
	if (empty())
	{
		m_front = newBox;
	}
	else
	{
		m_back->m_previous = newBox;
	}
	m_back = newBox;
	m_size++;
}

template<typename type>
inline bool dQueue<type>::dequeue(type &returnElement)
{
	if (this->empty())
	{
		std::cerr << "Its empty!" << std::endl;
		return false;
	}
	else
	{
		returnElement = m_front->m_data;
		Box<type>* pointerToOld = m_front;
		m_front = m_front->m_previous;
		delete[] pointerToOld;
		--m_size;
		return true;
	}
}

template<typename type>
inline type & dQueue<type>::peek() const
{
	type frontData;
	frontData = m_front->m_data;
	return frontData;
}

template<typename type>
inline Box<type>* dQueue<type>::frontBox() const
{
	Box<type>* front;
	front = m_front;
	return front;
}

template<typename type>
inline void dQueue<type>::print() const
{
	if (m_front == nullptr)
	{
		std::cerr << "Nothing to print\n";
		return;
	}
	else
	{
		Box<type>* boxPointer = m_front;
		while (boxPointer != nullptr)
		{
			std::cout << boxPointer->m_data << std::endl;
			boxPointer = boxPointer->m_previous;
		}
	}
}
template<typename type>
inline bool dQueue<type>::empty() const
{
	return (m_size == 0) ? true : false;
}
template<typename type>
inline Box<type>::Box(type data, Box<type>* previous, Box<type>* next)
{
	this->m_data = data;
	this->m_previous = previous;
	this->m_next = next;
}
#endif // !QUEUE_H
