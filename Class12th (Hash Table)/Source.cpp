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
		// ?ด์ ?จ์๋ฅ??ตํด??๊ฐ์ ๋ฐ๋ ?์ ๋ณ??
		int hashIndex = HashFunction(key);

		// ?๋ก???ธ๋๋ฅ??์ฑ?ฉ๋??
		Node* newNode = CreateNode(key, value);

		// ?ธ๋๊ฐ 1๊ฐ๋ผ??์กด์ฌ?์? ?๋?ค๋ฉด
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]??head ?ฌ์ธ?ฐ์ ?๋ก???ธ๋๋ฅ???ฅํฉ?๋ค.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]??count ๋ณ?์ ๊ฐ์ ์ฆ๊??ํต?๋ค.
			bucket[hashIndex].count++;
		}
		else // ?ธ๋๊ฐ 1๊ฐ๋ผ??์กด์ฌ?๋ค๋ฉ?
		{
			// 1. newNode??next??bucket[hashIndex]??head๊ฐ์ ??ฅํฉ?๋ค.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head๋ฅ?๋ฐฉ๊ธ ?๋ก ?์ฑ???ธ๋??์ฃผ์๋ฅ?๊ฐ๋ฆฌํค๊ฒ??ฉ๋??
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]??count ๋ณ?์ ๊ฐ์ ์ฆ๊??ํต?๋ค.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. ?ด์ ?จ์๋ฅ??ตํด??๊ฐ์ ๋ฐ๋ ?์ ๋ณ??
		int hashIndex = HashFunction(key);

		// 2. Node๋ฅ??์?????๋ ?ํ???ฌ์ธ??๋ณ??? ์ธ
		Node* currentNode = bucket[hashIndex].head;

		// 3. ?ด์  ?ธ๋๋ฅ???ฅํ  ???๋ ?ฌ์ธ??๋ณ??? ์ธ
		Node* traceNode = nullptr;

		// 4. currentNode๊ฐ nullptr?ด๋ผ๊ณ??๋ฉด ?จ์๋ฅ?์ข๋ฃ?ฉ๋??
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNode๋ฅ??ด์ฉ?ด์ ?ด๊? ์ฐพ๊ณ ???๋ key ๊ฐ์ ์ฐพ์ต?๋ค.
		while (currentNode != nullptr)
		{
			// currentNode->key ๊ฐ๊ณผ ?ด๊? ?? ?๊ณ  ?ถ์? key๊ฐ์ด ๊ฐ๋ค๋ฉ?
			if (currentNode->key == key)
			{
				// ?ด๊? ?? ?๊ณ ???๋ key๊ฐ head???๋ ?ธ๋?ผ๋ฉด
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// ๊ฐ?bucket??์นด์ด??๊ฐ์ ๊ฐ์?ํต?๋ค.
				bucket[hashIndex].count--;

				// ?ด๋น ๋ฉ๋ชจ๋ฆฌ๋? ?? ?ฉ๋??
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
#pragma region ?ด์ ?์ด๋ธ?
	// (Key, Value)๋ก??ฐ์ด?ฐ๋? ??ฅํ???๋ฃ ๊ตฌ์กฐ ์ค??๋๋ก?
	// ๋น ๋ฅด๊ฒ??ฐ์ด?ฐ๋? ๊ฒ?ํ  ???๋ ?๋ฃ ๊ตฌ์กฐ?๋??

	// ?ด์ ์ถฉ๋???ด๊ฒฐ?๋ ๋ฐฉ๋ฒ

	// <์ฒด์ด??๊ธฐ๋ฒ>
	// ๊ฐ??ด์ ๋ฒํท???ฐ๊ฒฐ ๋ฆฌ์ค?ธ๋ก ๊ตฌ์ฑ?๋ ๋ฐฉ์?๋??

	// ?ด์ ์ถฉ๋ ๋ฐ์ ???์ผ???ด์ ๊ฐ์ ?ด๋น?๋ ?ฐ์ด?ฐ๋ค??
	// ?ฐ๊ฒฐ๋ฆฌ์ค?ธ๋ก ?ฐ๊ฒฐ?์ฌ ??ฅํฉ?๋ค.

	// <๊ฐ๋ฐฉ ์ฃผ์๋ฒ?
	// ์ถฉ๋ ๋ฐ์ ??๋น?๋ฒ์ผ???ฐ์ด?ฐ๋? ??ฅํ??๋ฐฉ์?๋??

	// ๋น?๋ฒํท???ด๋ป๊ฒ?๊ฒฐ์ ??์ง???ฐ๋ผ ๊ตฌํ ๋ฐฉ์???ฌ๋ผ์ง๋??

	// ? ํ ?์ฌ : ์ถฉ๋ ๋ฐ์ ???์??๋ถ??์ฐจ๋??๋ก?๋น?๋ฒํท??
	// ์ฐพ์ ??ฅํ??๋ฐฉ์?๋??

	// ?ด์ฐจ ?์ฌ : ์ถฉ๋ ๋ฐ์ ??2^, 2^3 ๋งํผ ?จ์ด์ง?๋น?๋ฒํท??
	// ์ฐพ์ ๊ฐ์ ??ฅํ??๋ฐฉ์?๋??

	// ?ด์ค ?ด์ฑ : ?ด์ ๊ฐ์ ?๋ฒ ???ด์ ?จ์?์ ?ค๋ฅธ ?จ์๋ฅ?
	// ?์ถ?๋ ๋ฐฉ์?๋??
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
