#include <iostream>
#define SIZE 4
using namespace std;

#pragma region 원형 큐
// 물리적으로는 선형 구조를 가지고 있으며
// 큐의 시작점과 끝점을 연결한 Queue입니다.

template <typename T>
class CircleQueue
{
private:
	T data;
	T buffer[SIZE];

	int rear;
	int front;

public:
	CircleQueue()
	{
		rear = front = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Queue is Full" << endl;
		}
		else
		{
			buffer[rear] = data;
			rear = (rear + 1) % SIZE;
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
			buffer[front] = NULL;
			front = (front + 1) % SIZE;
		}
	}

	bool IsFull()
	{
		if ((rear + 1) % SIZE == front)
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
		else
		{
			return false;
		}
	}

	T& Front()
	{
		if (rear == front)
		{
			exit(1);
		}
		else
		{
			return buffer[front];
		}
	}
};
#pragma endregion

int main()
{
	CircleQueue<char> circlequeue;

	circlequeue.Push('A');
	circlequeue.Push('B');
	circlequeue.Push('C');

	while (circlequeue.Empty() == false)
	{
		cout << circlequeue.Front() << endl;
		circlequeue.Pop();
	}

	circlequeue.Push('D');
	circlequeue.Push('E');
	circlequeue.Push('F');

	while (circlequeue.Empty() == false)
	{
		cout << circlequeue.Front() << endl;
		circlequeue.Pop();
	}

	return 0;
}