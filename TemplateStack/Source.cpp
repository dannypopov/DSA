#include <iostream>
#include "dStack.h"
int main()
{	
	int top;
	dStack<int> _stack;
	for (int i = 0; i <= 10; ++i)
	{
		_stack.push(i);
	}
	_stack.print();
	_stack.pop(top);
	std::cout << "Popped top: " << top << std::endl;
	_stack.print();
	system("PAUSE");
	return 0;
}