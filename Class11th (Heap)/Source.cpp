#include <iostream>
#define SIZE 8
using namespace std;

#pragma region 완전 이진 트리(Complete Binary Tree)
// 최댓값 또는 최솟값을 구할 때 사용하기 용이함

// 조건
// 최대(최소) 힙 : 꼭대기
// 왼쪽 Node가 항상 있어야한다.
// 부모 Node가 자식 Node보다 항상 커야한다.

// 배열 (노드 개수 + 1 만큼 생성)
// 왼쪽 자식의 인덱스 : 부모 노드의 인덱스 X 2
// 오른쪽 자식의 인덱스 : 부모 노드의 인덱스 X 2 + 1
// 부모의 인덱스 : 자식 노드의 인덱스 / 2
// 0번째 인덱스 제외하고 사용

template <typename T>
class Heap
{
private:
	T buffer[SIZE];

	int index;

public:
	Heap()
	{
		index = 0;
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (index >= SIZE - 1)
		{
			cout << "Heap is Full" << endl;
			return;
		}

		buffer[++index] = data;
		int child = index;
		int parent = index / 2;
		while (parent != 0)
		{
			if (buffer[child] > buffer[parent])
			{
				std::swap(buffer[child], buffer[parent]); // using namespace std;가 있을 경우 std:: 생략 가능
			}
			child = parent;
			parent = child / 2;
		}

		// 위와 같은 방식
		/*while (child > 1)
		{
			// 자식 노드와 부모 노드의 데이터를 비교합니다.
			if(buffer[parent] < buffer[child])
			{
				swap(buffer[parent], buffer[child]);
			}
			child = parent;
			parent = child / 2;
		}*/
	}

	T& Delete()
	{
		// 1. 힙이 비어있다면 프로그램을 종료합니다.
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;
			exit(1);
		}

		// 2. 임시 변수에 buffer[1]의 값을 보관합니다.
		T result = buffer[1];

		// 3. index로 가리키는 배열의 값을 첫 번째 원소에 넣어줍니다.
		buffer[1] = buffer[index];

		// 4. index로 가리키는 배열의 값을 초기화합니다.
		buffer[index] = NULL;

		// 5. index의 값을 감소시킵니다.
		index--;

		int parent = 1;
		while (parent * 2 <= index)
		{
			int child = parent * 2;
			if (buffer[child] > buffer[child + 1])
			{
				if (buffer[parent] < buffer[child])
				{
					swap(buffer[parent], buffer[child]);
				}
				parent = child;
			}
			else if (buffer[child] < buffer[child + 1])
			{
				if (buffer[parent] < buffer[child + 1])
				{
					swap(buffer[parent], buffer[child + 1]);
				}
				parent = child + 1;
			}
		}

		return result;
	}

	void Show()
	{
		for (T element : buffer)
		{
			cout << element << " ";
		}
	}
};

#pragma endregion

int main()
{
	Heap<int> heap;

	heap.Insert(1);
	heap.Insert(2);
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(5);

	for (int i = 0; i < 5; i++)
	{
		heap.Show();
		cout << heap.Delete() << endl;
	}

	return 0;
}
