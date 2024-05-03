#include <iostream>
using namespace std;

template <typename T>
class AVLTree
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
	AVLTree()
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

	// 노드 높이 구하는 함수
	int Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			int left = Height(root->left);
			int right = Height(root->right);

			return max(left, right) + 1;
		}
	}

	// BF 값을 구하는 함수
	int BalanceFactor(Node* root)
	{
		return Height(root->left) - Height(root->right);
	}

	// 노드 삽입 함수
	Node* Insert(Node* root, T data)
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
		}
		else if (data < root->data)
		{
			root->left = Insert(root->left, data);
			root = Rebalance(root);
		}
		else if (data > root->data)
		{
			root->right = Insert(root->right, data);
			root = Rebalance(root);
		}

		return root;
	}

	// LL 회전
	Node* RotateLL(Node* root)
	{
		Node* currentNode = root->left;
		root->left = currentNode->right;
		currentNode->right = root;

		return currentNode;
	}

	// RR 회전
	Node* RotateRR(Node* root)
	{
		Node* currentNode = root->right;
		root->right = currentNode->left;
		currentNode->left = root;

		return currentNode;
	}

	// RL 회전
	Node* RotateRL(Node* root)
	{
		Node* currentNode = root->right;
		root->right = RotateLL(currentNode);

		return RotateRR(root);
	}

	// LR 회전
	Node* RotateLR(Node* root)
	{
		Node* currentNode = root->left;
		root->left = RotateLL(currentNode);

		return RotateLL(root);
	}

	// BF 값에 따라 노드를 회전시키는 함수
	Node* Rebalance(Node* root)
	{
		int factor = BalanceFactor(root);

		Node* temp;
		// (LL or LR)
		if (factor > 1)
		{
			// LL
			if (BalanceFactor(root->left) > 0)
			{
				temp = RotateLL(root);
			}
			// LR
			else if (BalanceFactor(root->right) > 0)
			{
				temp = RotateLR(root);
			}
		}
		// (RR or RL)
		else if (factor < -1)
		{
			// RR
			if (BalanceFactor(root->right) > 0)
			{
				temp = RotateRR(root);
			}
			// RL
			else if (BalanceFactor(root->left) > 0)
			{
				temp = RotateRL(root);
			}
		}

		return temp;
	}

};

int main()
{
#pragma region AVL 트리(AVL Tree)
	// 삽입과 삭제가 일어나는 경우 자동으로 그 높이를
	// 작게 유지하는 노드 기반 균형 이진 탐색 트리입니다.

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

#pragma endregion

	return 0;
}