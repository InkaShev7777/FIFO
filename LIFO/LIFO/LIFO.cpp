// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
template<typename T>
struct Node {
	T value;
	Node* next;

	Node()
	{

	}

	Node(Node* node) {
		next = NULL;
		value = node->value;
	}
};


template <typename T>
class LIFO {
private:
	Node<T>* first;
	unsigned long size;
public:
	explicit LIFO()
	{
		this->first = NULL;
		this->size = 0;
	}

	void add(T value) {
		if (this->first == NULL) {
			this->first = new Node<T>();
			this->first->value = value;
			this->first->next = NULL;
		}
		else
		{
			Node<T>* iter = this->first;
			while (iter->next != NULL)
			{
				iter = iter->next;
			}

			iter->next = new Node<T>();
			iter->next->value = value;
			iter->next->next = NULL;
		}

	}
	void show() {
		Node<T>* iter = this->first;
		while (iter != NULL)
		{
			std::cout << iter << " " << iter->next << " " << iter->value << "\n";
			iter = iter->next;
		}

	}

	Node<T>* remove() {
		Node<T>* iter = this->first;
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
		Node<T>* forReturn = new Node<T>(iter);
		delete iter;
		return forReturn;
	}
};
int main()
{
	LIFO<int> simple;

	simple.add(0);
	simple.add(1);
	simple.add(2);

	simple.show();

	Node<int>* last = simple.remove();
	std::cout << last << " " << last->value << "\n";
	//simple.show();
	//Node<int>* last1 = simple.remove();
	//std::cout << last1 << " " << last1->value << "\n";
}
