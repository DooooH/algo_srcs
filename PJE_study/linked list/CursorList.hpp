#include <bits/stdc++.h>
using namespace std;

template <typename T>
class CursorList{
private:
	int head;
	T *values;
	int *addresses;
	int size = 0;

public:
	CursorList(int size);
	void initializeList(int size);
	int getEmptyLocation();
	void addNode(T newValue);
	void deleteNode(T deleteValue);
	void printList();
};