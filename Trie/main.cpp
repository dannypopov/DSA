#include <iostream>
#include "Trie.h"
int main()
{
	Trie Test;
	Test.init();
	Test.insert("algorithm", 10);
	Test.insert("selection sort", 20);
	Test.insert("viagra", -100);
	Test.insert("linked list", 20);
	Test.insert("program", 5);
	std::cout<<Test.returnValue("viagra") << std::endl;
	system("PAUSE");
	return 0;
}