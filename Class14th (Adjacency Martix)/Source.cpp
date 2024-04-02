#include <iostream>
#define SIZE 10
using namespace std;

template <typename T>
class AdjacencyMatrix
{
private:
	int size; // 정점의 개수

	T vertex[SIZE]; // 정점의 집합

	int matrix[SIZE][SIZE]; // 인접 행렬

public:
	AdjacencyMatrix()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = NULL;
			}
		}
	}

	// 정점 생성 함수
	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency Matrix is Full" << endl;
			return;
		}

		vertex[size++] = data;
	}

	// 간선 연결 함수
	void Insert(int i, int j, int value = 1)
	{
		if (size == 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}

		if (i >= size || j >= size)
		{
			cout << "Out of Range" << endl;
			return;
		}

		matrix[i][j] = matrix[j][i] = value;
	}

	void Show()
	{
		if (size == 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}

		cout << " ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << vertex[i];
		}

		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << vertex[i];
			for (int j = 0; j < size; j++)
			{
				cout << " " << matrix[i][j];
			}
			cout << endl;
		}
	}
};

int main()
{
#pragma region 그래프(Graph)
	// 요소들이 서로 복잡하게 연결되어 있는 관계를 표현하는 자료 구조이며
	// 정점과 간선들의 집합으로 구성되어 있습니다.

	// 정점(Vertex)
	// Node : 데이터가 저장되는 그래프의 기본 원소입니다.

	// 간선(Edge)
	// 노드들을 연결하는 선입니다.

	// 인접 정점(Adjacent Vertex)
	// 간선으로 직접 연결된 정점을 의미합니다.

	// 차수(Degree)
	// 정점에 연결된 간선의 수를 의미합니다.

	// 경로(Path)
	// 정점들을 연결하는 간선들의 순서입니다.

	// G = (V, E) : 정점과 간선으로 이루어진 집합

	// 그래프의 종류
	// 1. 무방향 그래프(Undirected Graph)
	// 간선에 방향이 없는 그래프이다.

	// 2. 방향 그래프(Directed Graph)
	// 간선에 방향이 있는 그래프이다.
	// 진입 차수 : 다른 정점에서 들어오는 간선의 개수
	// 진출 차수 : 다른 정점으로 나가는 간선의 개수

	// 3. 가중치 그래프(Weighted Graph)
	// 간선에 가중치가 있는 그래프입니다.

	// 길찾기 및 네트워크에 주로 사용

#pragma endregion

#pragma region 인접 행렬(Adjacency Matrix)
	// 정점들 간의 연결 관계를 이차원 배열로 표현하는 방식입니다.
	// 정점의 개수가 V일 때, V x V 크기의 이차원 배열을 사용합니다.

	// 장점
	// 1. 두 정점이 연결되어 있는 확인하기 쉽습니다.
	// 2. 두 정점 사이의 간선의 가중치를 쉽게 확인할 수 있습니다.

	// 단점
	// 1. 정점의 개수가 많을 때 메모리 낭비가 심합니다.
	// 2. 특정 정점과 연결된 정점을 찾을 때 시간이 오래 걸립니다.

	AdjacencyMatrix<char> graph;

	graph.Insert('A');
	graph.Insert('B');
	graph.Insert('C');
	graph.Insert('D');

	graph.Insert(0, 1);
	graph.Insert(2, 0);
	graph.Insert(3, 0);
	graph.Insert(2, 3);

	graph.Show();

#pragma endregion

	return 0;
}
