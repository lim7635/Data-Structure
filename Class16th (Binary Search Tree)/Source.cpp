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

		Node* CurrentNode = root;
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

	bool Find(T data)
	{
		if (root == nullptr)
		{
			return false;
		}

		Node* CurrentNode = root;
		while (CurrentNode != nullptr)
		{
			if (data == CurrentNode->data)
			{
				return true;
			}
			else if (data < CurrentNode->data)
			{
				CurrentNode = CurrentNode->left;
			}
			else if (data > CurrentNode->data)
			{
				CurrentNode = CurrentNode->right;
			}
		}
		return false;
	}

	void Remove(T data)
	{
		if (root == nullptr)
		{
			cout << "Binary Search Tree is empty." << endl;
			return;
		}

		Node* ParentNode = nullptr;
		Node* CurrentNode = root;
		while (CurrentNode->data != data)
		{
			ParentNode = CurrentNode;
			if (data < CurrentNode->data)
			{
				CurrentNode = CurrentNode->left;
			}
			else if (data > ParentNode->data)
			{
				CurrentNode = CurrentNode->right;
			}
		}

		if (CurrentNode == nullptr)
		{
			cout << "Node is not Found." << endl;
			return;
		}

		// 1. �ڽ� ��尡 ���� ��带 �����ϴ� ���
		if (CurrentNode->left == nullptr && CurrentNode->right == nullptr)
		{
			if (ParentNode != nullptr)
			{
				if (CurrentNode == ParentNode->left)
				{
					ParentNode->left = nullptr;
				}
				else if (CurrentNode == ParentNode->right)
				{
					ParentNode->right = nullptr;
				}
			}
			else
			{
				root = nullptr;
			}
		}

		// 2. �ڽ� ��尡 1���� ��带 �����ϴ� ���
		else if (CurrentNode->left == nullptr || CurrentNode->right == nullptr)
		{
			Node* ChildNode = nullptr;
			if (CurrentNode->left != nullptr)
			{
				ChildNode = CurrentNode->left;
			}
			else if (CurrentNode->right != nullptr)
			{
				ChildNode = CurrentNode->right;
			}

			if (ParentNode != nullptr)
			{
				if (ParentNode->left == CurrentNode)
				{
					ParentNode->left = ChildNode;
				}
				else
				{
					ParentNode->right = ChildNode;
				}
			}
		}

		// 3. �ڽ� ��尡 2���� ��带 �����ϴ� ���
		else
		{
			Node* ChildNode = CurrentNode->right;
			Node* TraceNode = CurrentNode;
			while (ChildNode->left != nullptr)
			{
				TraceNode = ChildNode;
				ChildNode = ChildNode->left;
			}

			if (TraceNode->left == TraceNode)
			{
				TraceNode->left = ChildNode->right;
			}
			else
			{
				TraceNode->right = ChildNode->right;
			}
			CurrentNode->data = ChildNode->data;

			delete ChildNode;
			return;
		}
		delete CurrentNode;
	}

	void Destroy(Node * root)
	{
		if (root != nullptr)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
		}
	}

	~BinarySearchTree()
	{
		Destroy(root);
	}
};

int main()
{
#pragma region ���� Ž�� Ʈ��(Binary Search Tree)
	// �� ��忡 ���� ����/�������� (�ִ�) �� ���� �ڽ��� ���� �� �ִ� Ʈ���̸�
	// ���� �ڽ��� �θ� ��庸�� ���� ��, ������ �ڽ��� �θ� ��庸�� ū ���� ������ Ž�� Ʈ���Դϴ�.

	BinarySearchTree<int> binarysearchtree;

	binarysearchtree.Insert(100);
	binarysearchtree.Insert(90);
	binarysearchtree.Insert(10);
	binarysearchtree.Insert(20);
	binarysearchtree.Insert(30);
	binarysearchtree.Insert(50);
	binarysearchtree.Insert(40);

#pragma endregion

	return 0;
}
