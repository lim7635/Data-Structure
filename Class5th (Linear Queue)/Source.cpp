#include <iostream>
using namespace std;

#define SIZE 5

template <typename T>
class LinearQueue
{
private:
	T data;
	T array[SIZE];

	int size;
	int rear;
	int front;

public:
	LinearQueue()
	{
		size = 0;
		rear = 0;
		front = 0;
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Queue is Full" << endl;
		}
		else
		{
			array[rear] = data; // array[rear++] = data와 동일(후위 증감)
			rear++;
			size++;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Queue is Empty" << endl;
		}
		else
		{
			array[front++] = NULL; // (array[front] = NULL -> front++)와 동일(후위 증감)
			size--;
		}
	}

	bool IsFull()
	{
		if (rear == SIZE && front == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Empty()
	{
		if (rear == front)
		{
			return true;
		}
		return false;
	}

	// 복사 비용을 줄이기 위해 '참조자(&)' 사용
	int& Size()
	{
		return size;
	}

	T& Front()
	{
		if (rear == front)
		{
			exit(1);
		}
		else
		{
			return array[front];
		}
	}
};

int main()
{
#pragma region 선형 큐
	// 배열의 공간에 들어간 데이터가 고정되어 데이터를 빼내더라도 초기화하지 않으며
	// 원래 데이터가 있던 배열의 자리에 더 이상 다른 값이 들어올 수 없는 Queue입니다.

	LinearQueue<int> linearqueue;

	linearqueue.Push(10);
	linearqueue.Push(20);
	linearqueue.Push(30);
	linearqueue.Push(40);
	linearqueue.Push(50);

	while (linearqueue.Empty() == false)
	{
		cout << linearqueue.Front() << endl;
		linearqueue.Pop();
	}

#pragma endregion

	return 0;
}