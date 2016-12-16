#ifndef TRIE_H
#define TRIE_H
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
