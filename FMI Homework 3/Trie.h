#ifndef TRIE_H
#define TRIE_H
/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Jordan Liliyanov Popov
* @idnumber 45166
* @task 3
* @compiler VC
*
*/
#include <fstream>
struct Node
{
	Node* m_children[27];
	bool isEnd;
	int m_value;
	int prefixCount;
};
class Trie
{
private:
	Node* m_root;
	int longestPhrase;
public:
	Trie();
	void init();
	void insert(const char*, int);
	bool search(const char*);
	int returnValue(const char*);
	void readFromFile(const char*);
	int getLongestPhrase()const;
};

#endif // !TRIE_H
