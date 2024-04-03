#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;

public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	Node* CreateNode(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	void Insert(T data)
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
			return;
		}

		Node * CurrentNode = root;
		while (CurrentNode != nullptr)
		{
			if (data == CurrentNode->data)
			{
				return;
			}
			else if (data < CurrentNode->data)
			{
				if (CurrentNode->left == nullptr)
				{
					CurrentNode->left = CreateNode(data);
					break;
				}
				else
				{
					CurrentNode = CurrentNode->left;
				}
			}
			else
			{
				if (CurrentNode->right == nullptr)
				{
					CurrentNode->right = CreateNode(data);
					break;
				}
				else
				{
					CurrentNode = CurrentNode->right;
				}
			}
		}
	}

	void Find(T data)
	{
		if (root == nullptr)
		{
			cout << "Tree is Empty" << endl;
			return;
		}

		Node* CurrentNode = root;
		while (CurrentNode != nullptr)
		{
			if (data == CurrentNode->data)
			{
				cout << CurrentNode->data << endl;
				return;
			}
			else if(data < CurrentNode->data)
			{
				CurrentNode = CurrentNode->left;
			}
			else if(data > CurrentNode->data)
			{
				CurrentNode = CurrentNode->right;
			}
		}
		cout << "Not Found" << endl;
	}

};

int main()
{
#pragma region 이진 탐색 트리(Binary Search Tree)
	// 한 노드에 대해 왼쪽/오른쪽의 (최대) 두 개의 자식을 가질 수 있는 트리이며
	// 왼쪽 자식은 부모 노드보다 작은 값, 오른쪽 자식은 부모 노드보다 큰 값을 가지는 탐색 트리입니다.

#pragma endregion

	return 0;
}
