#include "CursorList.hpp"
// #include <bits/stdc++.h>
// using namespace std;

// template <typename T>
// class CursorList{
// private:
// 	int cursor;
// 	T *values;
// 	int *addresses;
// 	int size = 0;

// public:
// 	CursorList(int size);
// 	void initializeList(int size);
// 	int getEmptyLocation();
// 	void addNode(T newValue);
// 	void deleteNode(T deleteValue);
// 	void printList();
// };

CursorList<char>::CursorList(int size){
	head = -1;
	values = new char[size];
	addresses = new int[size];

	for (int i = 0; i < size; i++)
	{
		values[i] = '\0';
		addresses[i] = -1;
	}
}

int CursorList<char>::getEmptyLocation(){
	int length = sizeof(values)/sizeof(values[0]);

	for (int i = 0; i< length; i++)
	{
		if (values[i] == '\0')
		{
			return i;
		}
	}
	
	return -1;
}

void CursorList<char>::addNode(char newValue){
	int now = head;
	int location = -1;

	if (size == 0){
		values[0] = newValue;
		head = 0;
		size++;
		return ;
	}

	if ((location = getEmptyLocation()) == -1)
	{
		cout << "List if Full\n";
		return;
	}

	while (a)
}