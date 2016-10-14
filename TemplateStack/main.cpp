#include <iostream>
#include "Stack.h"
 
int main()
{
	int a = 3;
	Stack<int> Test;
	Test.push(1);
	Test.push(2);
	Test.push(3);
	Test.push(4);
	Test.push(5);
	std::cout <<std::boolalpha<< Test.ifEmpty() << std::endl;
	std::cout << Test.getSize() << std::endl;
	Test.pop(a);
	std::cout << "After pop" << std::endl;
	std::cout <<std::boolalpha<< Test.ifEmpty() << std::endl;
	std::cout << Test.getSize() << std::endl;
	system("PAUSE");
	return 0;
}