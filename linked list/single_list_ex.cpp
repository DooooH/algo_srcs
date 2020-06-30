#include <iostream>
using namespace std;

template <typename T>
struct Node
{
public:
	T value;
	struct Node<T> *next = nullptr; //nullptr?
};

template <typename T>
class single_list
{
private:
		Node<T> *head;
		Node<T> *tail;
		int size = 0;
public:
		single_list() : head(nullptr), tail(nullptr) {} // 생성자 리스트
		~single_list() {} // 소멸자

		void AddNode(T _value)
		{
			Node<T> *temp = new Node<T>(); //괄호 하는거 안하는거 같나?
			temp->next = nullptr;
			temp->value = _value;
			size++;

			if (head == nullptr)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp; // 
			}
			
		}

		void RemoveNode(T _value)
		{
			Node<T> *temp = head;
			Node<T> *pre_node = head;

			while(temp != nullptr)
			{
				if (temp->value == _value)
				{
					break ;
				}
				pre_node = temp;
				temp = temp->next;
			}
			if (temp == nullptr)
			{
				return ;
			}
			pre_node->next = temp->next;
			size--;
			delete temp;
		}

		void Show()
		{
			Node<T> *temp = head;

			while (head != nullptr)
			{
				cout << head->value << "->";
				head = head->next;
			}
			cout << "\n";
		}

		void DeleteList()
		{
			Node<T> *temp = head;
			while (head != nullptr)
			{
				temp = head->next;
				delete head;
				head = temp;
			}
			tail = nullptr;
		}

		void RemoveTail()
		{
			Node<T> *temp = head;

			if (temp == nullptr)
				return;
			while (temp->next != tail) //tail로 비교 가능??
			{
				temp = temp->next;
			}
			temp->next = nullptr;
			tail = temp;
			size--;
			delete tail;
		}

		void RemoveHead()
		{
			Node<T> *temp = head;
			if (temp == nullptr)
				return ;
			head = head->next;
			size--;
			delete head;
		}

		void AddHead(T _value)
		{
			Node<T> *new_node = new Node<T>();
			
			size++;
			new_node->value = _value;
			new_node->next = head;
			head = new_node;
		}

		void AddPosition(int _index, T _value)
		{
			int idx = 0;
			Node<T> *temp = head;

			if (size < 0 || _index > size - 1)
			{
				cout << "Wrong index\n";
				return ;
			}

			while (idx < size && temp->next != nullptr)
			{
				idx++;
				temp = temp->next;
			}
		}
};