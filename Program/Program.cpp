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
		int sum = 0;
		for (int i = 0; i < strlen(key); i++)
		{
			int hashIndex = key[i] % SIZE;
			sum += hashIndex;
		}

		sum = sum % SIZE;

		return sum;
	}

	~HashTable()
	{

	}
};
#pragma endregion

int main()
{

	return 0;
}