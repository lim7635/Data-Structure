#include <iostream>
#define SIZE 10
using namespace std;

template <typename T>
class Stack
{
private:
	int top;

	T buffer[SIZE];

public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}
	}

	void Push(T data)
	{
		if (top == SIZE - 1)
		{
			cout << "Stack is Full" << endl;
		}
		else
		{
			buffer[++top] = data;
		}
	}

	T Pop()
	{
		if (top <= -1)
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			return buffer[top--];
		}
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		return false;
	}

	bool IsFull()
	{
		if (top == SIZE - 1)
		{
			return true;
		}
		return false;
	}

	T& Top()
	{
		if (top <= -1)
		{
			exit(1);
		}
		return buffer[top];
	}
};

bool CheckBracket(string content)
{
	Stack<char> stack;
	for (int i = 0; i < content.length(); i++)
	{
		// 1. character에 content[i] 선언
		char character = content[i];

		// 2-1. character가 열린 괄호일 경우
		if (character == '(' || character == '{' || character == '[')
		{
			// character를 stack.Push
			stack.Push(character);
		}

		// 2-2. character가 닫힌 괄호일 경우
		else if (content[i] == ')' || content[i] == '}' || content[i] == ']')
		{
			// alphabet에 stack.Pop의 반환값(buffer[top]) 선언
			char alphabet = stack.Pop();

			// alphabet과 character 비교(괄호 모양이 서로 다르면 false 반환)
			switch (alphabet)
			{
			case '(': if (character != ')') { return false; }
					break;

			case '{': if (character != '}') { return false; }
					break;

			case '[': if (character != ']') { return false; }
					break;

			default:
				break;
			}
		}
	}

	if (stack.Empty() == true)
	{
		return true;
	}
	return false;
}

int main()
{
	/*Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);*/

	bool flag = CheckBracket("({[]})");
	if (flag == true)
	{
		cout << "성공" << endl;
	}
	else if (flag == false)
	{
		cout << "실패" << endl;
	}

	return 0;
}