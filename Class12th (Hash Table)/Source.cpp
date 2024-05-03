#include <iostream>
#define SIZE 6
using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template<typename T>
	int HashFunction(T key)
	{
		int hashIndex = (int)key % SIZE;

		return hashIndex;
	}

	template<>
	int HashFunction(string key)
	{
		int result = 0;

		for (const char& element : key)
		{
			result += (int)element;
		}

		int hashIndex = result % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시 변수를 만듭니다.
		int hashIndex = HashFunction(key);

		// 2. 새로운 노드를 생성합니다.
		Node* newNode = CreateNode(key, value);

		// 3-1. 노드가 1개라도 존재하지 않을 경우
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]의 head 포인터에 새로운 노드를 저정합니다.
			bucket[hashIndex].head = newNode;

			// bucket[hashIndex]의 count 변수의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}
		// 3-2. 노드가 1개라도 존재할 경우
		else
		{
			// 1. newNode의 next에 bucket[hashIndex]의 head값을 저장합니다.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head를 방금 새로 생성한 노드의 주소를 가리키게 합니다.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]의 count 변수의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 2. 노드를 탐색할 수 있는 순회용 포인터 변수 선언
		Node* currentNode = bucket[hashIndex].head;

		// 3. 이전 노드를 저장할 수 있는 포인터 변수 선언
		Node* traceNode = nullptr;

		// 4. currentNode가� nullptr이라고 하면 함수 종료
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNode를 이용해서 찾고자 하는 key 값을 찾습니다.
		while (currentNode != nullptr)
		{
			// currentNode->key 값과 삭제하고 싶은 key 값이 같을 경우
			if (currentNode->key == key)
			{
				// 삭제하고자 하는 key가 head에 있는 노드일 경우
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				// 삭제하고자 하는 key가 중간에 있는 노드일 경우
				else
				{
					traceNode->next = currentNode->next;
				}

				// 6. 각 bucket의 카운트 값을 감소시킵니다.
				bucket[hashIndex].count--;

				// 7. 해당 메모리를 삭제시킵니다.
				delete currentNode;

				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;
		}

		cout << "Not Key Found" << endl;
	}

	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* currentNode = bucket[i].head;

			while (currentNode != nullptr)
			{
				cout << "[" << i << "]" << "KEY : " << currentNode->key << " VALUE : " << currentNode->value << " ";
				currentNode = currentNode->next;
			}

			cout << endl;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;

			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}
	}
};

int main()
{
#pragma region 해시 테이블(Hash Table)
	// (Key, Value)로 데이터를 저장하는 자료 구조 중 하나로
	// 빠르게 데이터를 검색할 수 있는 자료 구조입니다.

	// 해시 충돌을 해결하는 방법

	// 1. 체이닝 기법
	// 각 해시 버킷을 연결 리스트로 구성하는 방식입니다.
	// 해시 충돌 발생 시 동일한 해시 값에 데이터들을 연결리스트로 연결하여 저장합니다.

	// 2. 개방 주소법
	// 충돌 발생 시 빈 버킷에 데이터를 저장하는 방식입니다.
	// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라집니다.

	// 2.1 선형 탐사 : 충돌 발생 시 앞에서부터 차례대로
	// 빈 버킷을 찾아 저장하는 방식입니다.

	// 2.2 이차 탐사 : 충돌 발생 시 2제곱 또는 2의 3제곱만큼
	// 떨어진 빈 버킷을 찾아 값을 저장하는 방식입니다.

	// 2.3 이중 해싱 : 해시 값을 한번 더 해시 함수에서
	// 다른 함수를 도출하는 방식입니다.
#pragma endregion

	HashTable<int, string> hashTable;

	hashTable.Insert(10, "Soccer");
	hashTable.Insert(27, "BaseBall");
	hashTable.Insert(14, "Tennis");
	hashTable.Insert(97, "BasketBall");
	hashTable.Insert(99, "Swimming");

	hashTable.Remove(10);
	hashTable.Remove(14);
	hashTable.Remove(99);

	hashTable.Show();

	return 0;
}
