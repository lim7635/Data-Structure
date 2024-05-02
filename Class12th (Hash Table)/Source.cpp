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
		// ?�시 ?�수�??�해??값을 받는 ?�시 변??
		int hashIndex = HashFunction(key);

		// ?�로???�드�??�성?�니??
		Node* newNode = CreateNode(key, value);

		// ?�드가 1개라??존재?��? ?�는?�면
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]??head ?�인?�에 ?�로???�드�??�?�합?�다.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]??count 변?�의 값을 증�??�킵?�다.
			bucket[hashIndex].count++;
		}
		else // ?�드가 1개라??존재?�다�?
		{
			// 1. newNode??next??bucket[hashIndex]??head값을 ?�?�합?�다.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head�?방금 ?�로 ?�성???�드??주소�?가리키�??�니??
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]??count 변?�의 값을 증�??�킵?�다.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. ?�시 ?�수�??�해??값을 받는 ?�시 변??
		int hashIndex = HashFunction(key);

		// 2. Node�??�색?????�는 ?�회???�인??변???�언
		Node* currentNode = bucket[hashIndex].head;

		// 3. ?�전 ?�드�??�?�할 ???�는 ?�인??변???�언
		Node* traceNode = nullptr;

		// 4. currentNode가 nullptr?�라�??�면 ?�수�?종료?�니??
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNode�??�용?�서 ?��? 찾고???�는 key 값을 찾습?�다.
		while (currentNode != nullptr)
		{
			// currentNode->key 값과 ?��? ??��?�고 ?��? key값이 같다�?
			if (currentNode->key == key)
			{
				// ?��? ??��?�고???�는 key가 head???�는 ?�드?�면
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// �?bucket??카운??값을 감소?�킵?�다.
				bucket[hashIndex].count--;

				// ?�당 메모리�? ??��?�니??
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
#pragma region ?�시 ?�이�?
	// (Key, Value)�??�이?��? ?�?�하???�료 구조 �??�나�?
	// 빠르�??�이?��? 검?�할 ???�는 ?�료 구조?�니??

	// ?�시 충돌???�결?�는 방법

	// <체이??기법>
	// �??�시 버킷???�결 리스?�로 구성?�는 방식?�니??

	// ?�시 충돌 발생 ???�일???�시 값에 ?�당?�는 ?�이?�들??
	// ?�결리스?�로 ?�결?�여 ?�?�합?�다.

	// <개방 주소�?
	// 충돌 발생 ??�?버켓???�이?��? ?�?�하??방식?�니??

	// �?버킷???�떻�?결정??지???�라 구현 방식???�라집니??

	// ?�형 ?�사 : 충돌 발생 ???�에??부??차�??��?�?버킷??
	// 찾아 ?�?�하??방식?�니??

	// ?�차 ?�사 : 충돌 발생 ??2^, 2^3 만큼 ?�어�?�?버킷??
	// 찾아 값을 ?�?�하??방식?�니??

	// ?�중 ?�싱 : ?�시 값을 ?�번 ???�시 ?�수?�서 ?�른 ?�수�?
	// ?�출?�는 방식?�니??
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
