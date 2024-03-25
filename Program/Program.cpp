#include <iostream>
using namespace std;

#pragma region 트리(Tree)
// Tree 구조는 검색할 때 주로 사용

// Node : data, Node * left, Node * right로 구성
// root : 최상위 Node
// edge : Node와 Node를 연결하는 간선
// parent : 자신보다 하위 Node를 가지고 있는 Node를 의미(부모 Node)
// child : 자신보다 상위 Node를 가지고 있는 Node를 의미(자식 Node)
// leaf : 자식 Node를 가지지 않는 Node를 의미
// level : root로 부터 그 하위 단계를 측정하는 것 (위 -> 아래)
// height : level 반대(아래 -> 위)
// path : Node와 Node 사이간에 나타나는 Node와 간선의 순서
// degree : 해당 Node가 포함하는 자식 Node의 수

struct Node
{
	int data;

	Node* left;
	Node* right;
};

Node * CreateNode(int data, Node * left, Node * right)
{
	// 1. 새로운 Node 생성
	Node* newNode = new Node;

	// 2. 새로운 Node에 data값 저장
	newNode->data = data;

	// 3. 새로운 Node에 left값 저장
	newNode->left = left;

	// 4. 새로운 Node에 right값 저장
	newNode->right = right;

	// 5. 새로운 Node의 주소값 반환
	return newNode;
}

// 전위 순회
// 1. Root Node 방문
// 2. 왼쪽 서브 트리를 전위 순회합니다.
// 3. 오른쪽 서브 트리를 전위 순회합니다.
void Preorder(Node * root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

// 중위 순회
// 1. 왼쪽 서브 트리를 중위 순회합니다.
// 2. Root Node 방문
// 3. 오른쪽 서브 트리를 중위 순회합니다.
void Inorder(Node * root)
{
	if (root != nullptr)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}

// 후위 순회
// 1. 왼쪽 서브 트리를 후위 순회합니다.
// 2. 오른쪽 서브 트리를 후위 순회합니다.
// 3. Root Node 방문
void Postorder(Node * root)
{
	if (root != nullptr)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}
#pragma endregion

int main()
{
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	Preorder(node1);
	cout << endl;

	Inorder(node1);
	cout << endl;

	Postorder(node1);
	cout << endl;

	return 0;
}