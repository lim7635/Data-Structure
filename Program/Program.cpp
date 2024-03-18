#include <iostream>
using namespace std;

template <typename T>
class CircleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

	int size;

public:
	CircleLinkedList()
	{
		head = nullptr;

		size = 0;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			head->next = newNode;
			newNode->next = head->next;
			head = newNode;
		}
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
		deleteNode = head->next;

		if (size == 1)
		{
			head = nullptr;
		}
		else
		{
			head->next = deleteNode->next;
		}
		delete deleteNode;
		size--;
	}

	void PopBack()
	{
		if (size == 0)
		{
			cout << "List is Empty" << endl;
			return;
		}

		Node* deleteNode = head;
		Node* currentNode = head;
		if (size == 1)
		{
			head = nullptr;
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = head->next;
			head = currentNode;
		}
		delete deleteNode;
		size--;
	}

	void Show()
	{
		Node* currentNode = head;

		for (int i = 0; i < size; i++)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	~CircleLinkedList()
	{
		while (size != 0)
		{
			PopFront();
		}
	}
};

int main()
{
	CircleLinkedList<int> circlelinkedlist;

	circlelinkedlist.PushBack(100);
	circlelinkedlist.PushFront(99);
	circlelinkedlist.PushFront(97);
	circlelinkedlist.PushBack(95);

	circlelinkedlist.Show();
	circlelinkedlist.PopBack();

	return 0;
}