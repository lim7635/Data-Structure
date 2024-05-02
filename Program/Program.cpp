#include <iostream>
using namespace std;

template <typename T>
class BalancedBinaryTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		int height;
	};

	Node* root;

public:
	BalancedBinaryTree()
	{
		root = nullptr;
	}

	Node* CreateNode(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->height = 1;

		return newNode;
	}

	int Height(Node * root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			return root->height;
		}
	}

	int BalanceFactor(Node * root)
	{
		return Height(root->left) - Height(root->right);
	}

	void Insert(T data)
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
			return;
		}

		Node* currentNode = root;
		while (currentNode != nullptr)
		{
			if (data == currentNode->data)
			{
				return;
			}

			if (data < currentNode->data)
			{
				if (currentNode->left == nullptr)
				{
					currentNode->left = CreateNode(data);
					break;
				}
				else
				{
					currentNode = currentNode->left;
				}
			}
			else
			{
				if (currentNode->right == nullptr)
				{
					currentNode->right = CreateNode(data);
					break;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
	}

	void Balancing(Node * root, T data)
	{
		int balanceFactor = BalanceFactor(root);


	}

};

int main()
{
#pragma region 균형 이진 탐색 트리(AVL Tree)
	// 삽입과 삭제가 일어나는 경우 자동으로 그 높이를
	// 작게 유지하는 노드 기반 이진 탐색 트리입니다.

	// Balance Factor(BF)
	// 왼쪽 서브 트리의 높이에서 오른쪽 서브 트리의 높이를 뺀 값

	// BF = 1 (왼쪽 서브 트리의 높이가 오른쪽 서브 트리의 높이보다 한 단계 높다.)
	
	// BF = 0 (왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이가 같다.)

	// BF = -1 (왼쪽 서브 트리의 높이가 오른쪽 서브 트리의 높이보다 한 단계 낮다.)

	// 불균형 발생 유형
	// LL 유형 : 불균형 발생 노드의 왼쪽 자식 노드와
	//			 자식의 왼쪽 자식 노드에 의해 왼쪽으로 치우쳐져 있습니다.

	// RR 유형 : 불균형 발생 노드의 오른쪽 자식 노드와
	//			 자식의 오른쪽 자식 노드에 의해 왼쪽으로 치우쳐져 있습니다.

	// LR 유형 : 불균형 발생 노드의 왼쪽 자식 노드와
	//			 자식의 오른쪽 자식 노드에 의해 왼쪽으로 치우쳐져 있습니다.

	// RL 유형 : 불균형 발생 노드의 오른쪽 자식 노드와
	//			 자식의 왼쪽 자식 노드에 의해 왼쪽으로 치우쳐져 있습니다.

	BalancedBinaryTree<int> balanced;

	balanced.CreateNode(7);
	balanced.Insert(10);
	balanced.Insert(15);
	balanced.Insert(5);
	balanced.Insert(3);

#pragma endregion

	return 0;
}