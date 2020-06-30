#include <bits/stdc++.h>
using namespace std;

class Node{
	friend class double_linked;
private:
	int value;
	Node* next_node;
	Node* pre_node;

public:
	Node(int v, Node* n, Node* p){
		value = v;
		next_node = n;
		pre_node = p;
	}
};

class double_linked {

private:
	Node* head;
	int size;

public:
	double_linked(){
		size = 0;
		head = NULL;
	}

	void push_back(int value){
		Node *new_node = new Node(value, NULL, NULL);
		if (head == NULL)
		{
			head = new_node;
			new_node->pre_node = new_node;
			new_node->next_node = new_node;
		}
		else{
			new_node->next_node = head;
			new_node->pre_node = head->pre_node;
			head->pre_node->next_node = new_node;
			head->pre_node = new_node;
		}
		size++;
	}

	void search(int value)
	{
		Node* node = head;
		for (int i = 0; i < size; i++)
		{
			if (node->value == value)
				cout << "value found\n";
			node = node->next_node;
		}
	}
};