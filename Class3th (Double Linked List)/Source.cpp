#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
	};

	int size;

	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void Insert(int position, T data)
	{
		if (position > size + 1 || position == 0)
		{
			cout << "The Size is out of bounds" << endl;
			return;
		}
		else if (position == 1)
		{
			PushFront(data);
			return;
		}
		else if (position == size + 1)
		{
			PushBack(data);
			return;
		}

		Node* currentNode = head;
		Node* newNode = new Node;
		newNode->data = data;

		int i = 1;
		while (i != position)
		{
			currentNode = currentNode->next;
			i++;
		}

		newNode->prev = currentNode->prev;
		newNode->next = currentNode;
		currentNode->prev->next = newNode;
		currentNode->prev = newNode;
		size++;
	}

	void PopFront()
	{
		if (size == 0)
		{
			cout << "List is Empty" << endl;
			return;
		}

		Node* deleteNode = nullptr;
		deleteNode = head;

		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		}
		else
		{
			head = deleteNode->next; // head = head->next 동일
			head->prev = nullptr;
			delete deleteNode;
		}
		size--;
	}

	void PopBack()
	{
		if (size == 0)
		{
			cout << "List is Empty" << endl;
			return;
		}

		Node* deleteNode = nullptr;
		deleteNode = tail;

		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		}
		else
		{
			tail = deleteNode->prev; // tail = tail->prev 동일
			tail->next = nullptr;
			delete deleteNode;
		}
		size--;
	}

	int Size()
	{
		return size;
	}

	void Show()
	{
		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	~DoubleLinkedList()
	{
		while (size != 0)
		{
			PopFront();
		}
	}
};

int main()
{
	/*DoubleLinkedList<int> doublelinkedlist;

	doublelinkedlist.PushFront(100);
	doublelinkedlist.PushFront(95);
	doublelinkedlist.PushBack(98);
	doublelinkedlist.PushBack(99);

	doublelinkedlist.Insert(2, 97);

	doublelinkedlist.Show();

	cout << "Size 크기 : " << doublelinkedlist.Size() << endl;*/

	return 0;
}