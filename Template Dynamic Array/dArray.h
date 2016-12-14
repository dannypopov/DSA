#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
template<typename type>
class dArray
{
private:
	type* m_array;
	int m_index;
	int m_capacity;
	void unleashData();
	void copyData(const dArray&);
	void resize(int);
	void init();
public:
	//
	dArray<type>();
	~dArray<type>();
	dArray<type>(const dArray<type>&);
	dArray<type>& operator=(const dArray<type>&);
	//
	int getCapacity()const;
	int getIndex()const;
	type& operator[](int);
	const type& operator[](int)const;
	void add(type);
	void AlphaSort();
};
void swap(char *&first, char *&second)
{
	if (first != nullptr && second != nullptr)
	{
		char* tmp;
		tmp = first;
		first = second;
		second = tmp;
	}
}
template<typename type>
std::ostream& operator<<(std::ostream&, const dArray<type>&);
template<typename type>
inline int dArray<type>::getCapacity() const
{
	return m_capacity;
}

template<typename type>
inline int dArray<type>::getIndex() const
{
	return m_index;
}

template<typename type>
inline type & dArray<type>::operator[](int index)
{
	if (index >= m_capacity)
	{
		throw std::out_of_range("Invalid index");
	}
	return m_array[index];
}

template<typename type>
inline const type & dArray<type>::operator[](int index) const
{
	if (index >= m_capacity)
	{
		throw std::out_of_range("Invalid index");
	}
	return m_array[index];
}

template<typename type>
inline void dArray<type>::add(type newEl)
{
	if (m_index >= m_capacity)
	{
		int newSize = ((m_capacity == 0) ? 2 : m_capacity * 2);
		resize(newSize);
	}
	m_array[m_index] = newEl;
	m_index++;
}

template <>
inline void dArray<char*>::AlphaSort()
{
	char tmp[50];
	for (int i = 0; i < m_index - 1; i++)
	{
		for (int ii = i + 1; ii < m_index; ++ii)
		{
			if (strcmp(m_array[i], m_array[ii]) > 0)
			{
				swap(m_array[i], m_array[ii]);
			}
		}
	}
}

template<typename type>
inline void dArray<type>::unleashData()
{
	delete[] m_array;
	m_array = nullptr;
	m_capacity = 0;
	m_index = 0;
}

template<typename type>
inline void dArray<type>::copyData(const dArray &other)
{
	m_array = new type[other.getCapacity()];
	for (int i = 0; i < other.getIndex(); ++i)
	{
		m_array = other->m_array[i];
	}
	m_capacity = other.getCapacity();
	m_index = other.getIndex();
}

template<typename type>
inline void dArray<type>::resize(int newSize)
{
	type* newArray = new type[newSize];
	int elementsToCopy;
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
		newArray[i] = m_array[i];
	}
	delete[] m_array;
	m_array = newArray;
	m_capacity = newSize;
}
template<typename type>
inline void dArray<type>::init()
{
	m_capacity = 1;
	m_index = 0;
	m_array = new type[m_capacity];
}
template<typename type>
inline dArray<type>::dArray()
{
	init();
}

template<typename type>
inline dArray<type>::~dArray()
{
	unleashData();
}

template<typename type>
inline dArray<type>::dArray(const dArray &other)
{
	copyData(other);
}

template<typename type>
inline dArray<type> & dArray<type>::operator=(const dArray<type> &rhs)
{
	if (this != &rhs)
	{
		unleashData();
		copyData(rhs);
	}
	return *this;
}
template<typename type>
inline std::ostream & operator<<(std::ostream &out, const dArray<type>&arr)
{
	for (int i = 0; i < arr.getIndex(); ++i)
	{
		out << arr[i];
		out << "\n";
	}
	return out;
}
#endif // if DYNAMICARRAY_H
