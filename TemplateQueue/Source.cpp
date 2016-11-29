#include <iostream>
#include "dQueueh.h"
int main()
{
	int front;
	dQueue<int> _queue;
	for (int i = 0; i <= 10; ++i)
	{
		_queue.enqueue(i);
	}
	_queue.print();
	_queue.dequeue(front);
	std::cout << front << std::endl;
	_queue.print();
	system("PAUSE");
	return 0;
}