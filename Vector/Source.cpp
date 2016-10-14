#include <iostream>
#include "Vector.h"
int main()
{
	Vector v(1, 2, 3);
	Vector c(2, 3, 4);
	Vector a = v^c;
	a.Print();
	a = v + c;
	std::cout << std::endl;
	a.Print();
	std::cout << std::endl;
	std::cout << v*c;
	std::cout << std::endl;
	std::cout << std::endl;
	a.Print();
	system("PAUSE");
	return 0;
}