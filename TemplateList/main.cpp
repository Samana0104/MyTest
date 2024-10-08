#include <iostream>
#include <memory>
using namespace std;

template < class T >
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template < class T >
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* cur;

	void InitList()
	{
		head = new Node<T>;
		tail = new Node<T>;

		head = CreateNode(0);
		tail = CreateNode(0);

		head->next = tail;
		tail->prev = head;
		cur = head;
	}

	Node<T>* CreateNode(T data)
	{
		Node<T>* newNode = new Node<T>;
		_ASSERT(newNode);

		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;

		return newNode;
	}

public:
	LinkedList() : head(nullptr), tail(nullptr), cur(nullptr)
	{
		this->InitList();
	}
	
	void PushBack(T data)
	{
		Node<T>* newNode = this->CreateNode(data);
		Node<T>* tailPrev = this->tail->prev;

		tailPrev->next = newNode;
		newNode->prev = tailPrev;

		newNode->next = tail;
		tail->prev = newNode;
	}

	void InitCurToHead() const
	{
		this->cur = this->head;
	}

	void InitCurToTail() const
	{
		this->cur = this->tail;
	}
};

int main()
{
	LinkedList<int> listTest;

	listTest.PushBack(1);
	listTest.PushBack(2);
	listTest.PushBack(3);
	return 0;
}