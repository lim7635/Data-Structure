#include <iostream>
#define SIZE 6
using namespace std;

#pragma region 해시 테이블(Hash Table)
// (Key, Value)로 데이터를 저장하는 자료 구조 중 하나로
// 빠르게 데이터를 검색할 수 있는 자료 구조입니다.

// 해시 충돌을 해결하는 방법
// 1. 체이닝 기법
// 각 해시 버킷을 연결 리스트로 구성하는 방식입니다.
// 해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을 연결리스트로 연결하여 저장합니다.

// 2. 개방 주소법
// 충돌 발생 시 빈 버킷에 데이터를 저장하는 방식입니다.
// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라집니다.

// 2.1 선형 탐사 : 충돌 발생 시 앞에서부터 차례대로 빈 버킷을 찾아 저장하는 방식입니다.
// 2.2 이차 탐사 : 충돌 발생 시 2제곱 또는 2의 3제곱만큼 떨어진 빈 버킷을 찾아 값을 저장하는 방식입니다.
// 2.3 이중 해싱 : 해시 값을 한번 더 해시 함수에서 다른 함수를 도출하는 방식입니다.

template <typename KEY, typename VALUE>
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

	template <typename T>
	int HashFunction(T key)
	{
		int hashIndex = (int)key % SIZE;

		return hashIndex;
	}

	// HashFunction 템플릿 특수화
	template <>
	int HashFunction(string key)
	{
		int result = 0;
		for (const char & element : key)
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
			// bucket[hashIndex]의 head 포인터에 새로운 노드를 저장합니다.
			bucket[hashIndex].head = newNode;

			// bucket[hashIndex]의 count 변수의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}

		// 3-2. 노드가 1개라도 존재할 경우
		else
		{
			// newNode의 next에 bucket[hashIndex]의 head값을 저장합니다.
			newNode->next = bucket[hashIndex].head;

			// bucket[hashIndex].head를 방금 새로 생성한 노드의 주소를 가리키게 합니다.
			bucket[hashIndex].head = newNode;

			// bucket[hashIndex]의 count 변수의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		int hashIndex = HashFunction(key);

		Node* CurrentNode = bucket[hashIndex].head;
		Node* traceNode = nullptr;

		while (key != CurrentNode->key)
		{
			traceNode = CurrentNode;
			CurrentNode = CurrentNode->next;
		}
		if (traceNode == nullptr)
		{

		}
		else
		{
			traceNode->next = CurrentNode->next;
		}

		delete CurrentNode;
	}

	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* CurrentNode = bucket[i].head;
			while (CurrentNode != nullptr)
			{
				cout << "[" << i << "]" << "KEY : " << CurrentNode->key << ", VALUE : " << CurrentNode->value << " | ";
				CurrentNode = CurrentNode->next;
			}
			cout << endl;
		}
	}

	~HashTable()
	{

	}
};
#pragma endregion

int main()
{
	HashTable<int, string> hashtable;

	hashtable.Insert(10, "Soccer");
	hashtable.Insert(27, "Baseball");
	hashtable.Insert(14, "Tennis");
	hashtable.Insert(97, "Basketball");
	hashtable.Insert(16, "Swimming");
	hashtable.Insert(22, "Swimming");
	hashtable.Remove(22);

	hashtable.Show();

	return 0;
}