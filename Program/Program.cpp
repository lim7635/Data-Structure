#include <iostream>
#define SIZE 4
using namespace std;

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = NULL)
		{
			this->data = data;
			next = link;
		}
	};

	int size; // 정점의 개수
	T* vertex[SIZE]; // 정점의 집합
	Node* list[SIZE]; // 인접 리스트

public:
	AdjacencyList()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = list[i] = nullptr;
		}
	}

	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency Matrix is Full" << endl;
			return;
		}

		vertex[size++] = data;
	}

	void Insert(int u, int v)
	{
		if (size == 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}

		if (u >= size || v >= size)
		{
			cout << "Out of Range" << endl;
			return;
		}

		list[u] = new Node(data, list[u]);
		list[v] = new Node(data, list[v]);
	}
};

int main()
{
#pragma region 인접 리스트(Adjacency List)
	// 그래프의 각 정점에 인접한 정점들을
	// 연결 리스트로 표현하는 방법입니다.

	// 장점
	// 그래프의 모든 간선의 수를 O(V + E)로 표현할 수 있습니다.
	// V : 정점, E : 간선

	// 단점
	// 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 위해서는
	// 정점의 인접 리스트를 모두 탐색해야 하므로 정점의 차수만큼의 시간이 필요합니다.

#pragma endregion

	return 0;
}