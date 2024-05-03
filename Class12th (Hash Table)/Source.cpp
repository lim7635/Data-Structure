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
		// 1. ÇØ½Ã ÇÔ¼ö¸¦ ÅëÇØ¼­ °ªÀ» ¹Ş´Â ÀÓ½Ã º¯¼ö¸¦ ¸¸µì´Ï´Ù.
		int hashIndex = HashFunction(key);

		// 2. »õ·Î¿î ³ëµå¸¦ »ı¼ºÇÕ´Ï´Ù.
		Node* newNode = CreateNode(key, value);

		// 3-1. ³ëµå°¡ 1°³¶óµµ Á¸ÀçÇÏÁö ¾ÊÀ» °æ¿ì
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]ÀÇ head Æ÷ÀÎÅÍ¿¡ »õ·Î¿î ³ëµå¸¦ ÀúÁ¤ÇÕ´Ï´Ù.
			bucket[hashIndex].head = newNode;

			// bucket[hashIndex]ÀÇ count º¯¼öÀÇ °ªÀ» Áõ°¡½ÃÅµ´Ï´Ù.
			bucket[hashIndex].count++;
		}
		// 3-2. ³ëµå°¡ 1°³¶óµµ Á¸ÀçÇÒ °æ¿ì
		else
		{
			// 1. newNodeÀÇ next¿¡ bucket[hashIndex]ÀÇ head°ªÀ» ÀúÀåÇÕ´Ï´Ù.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head¸¦ ¹æ±İ »õ·Î »ı¼ºÇÑ ³ëµåÀÇ ÁÖ¼Ò¸¦ °¡¸®Å°°Ô ÇÕ´Ï´Ù.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]ÀÇ count º¯¼öÀÇ °ªÀ» Áõ°¡½ÃÅµ´Ï´Ù.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. ÇØ½Ã ÇÔ¼ö¸¦ ÅëÇØ¼­ °ªÀ» ¹Ş´Â ÀÓ½Ã º¯¼ö
		int hashIndex = HashFunction(key);

		// 2. ³ëµå¸¦ Å½»öÇÒ ¼ö ÀÖ´Â ¼øÈ¸¿ë Æ÷ÀÎÅÍ º¯¼ö ¼±¾ğ
		Node* currentNode = bucket[hashIndex].head;

		// 3. ÀÌÀü ³ëµå¸¦ ÀúÀåÇÒ ¼ö ÀÖ´Â Æ÷ÀÎÅÍ º¯¼ö ¼±¾ğ
		Node* traceNode = nullptr;

		// 4. currentNode°¡€ nullptrÀÌ¶ó°í ÇÏ¸é ÇÔ¼ö Á¾·á
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNode¸¦ ÀÌ¿ëÇØ¼­ Ã£°íÀÚ ÇÏ´Â key °ªÀ» Ã£½À´Ï´Ù.
		while (currentNode != nullptr)
		{
			// currentNode->key °ª°ú »èÁ¦ÇÏ°í ½ÍÀº key °ªÀÌ °°À» °æ¿ì
			if (currentNode->key == key)
			{
				// »èÁ¦ÇÏ°íÀÚ ÇÏ´Â key°¡ head¿¡ ÀÖ´Â ³ëµåÀÏ °æ¿ì
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				// »èÁ¦ÇÏ°íÀÚ ÇÏ´Â key°¡ Áß°£¿¡ ÀÖ´Â ³ëµåÀÏ °æ¿ì
				else
				{
					traceNode->next = currentNode->next;
				}

				// 6. °¢ bucketÀÇ Ä«¿îÆ® °ªÀ» °¨¼Ò½ÃÅµ´Ï´Ù.
				bucket[hashIndex].count--;

				// 7. ÇØ´ç ¸Ş¸ğ¸®¸¦ »èÁ¦½ÃÅµ´Ï´Ù.
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
#pragma region ÇØ½Ã Å×ÀÌºí(Hash Table)
	// (Key, Value)·Î µ¥ÀÌÅÍ¸¦ ÀúÀåÇÏ´Â ÀÚ·á ±¸Á¶ Áß ÇÏ³ª·Î
	// ºü¸£°Ô µ¥ÀÌÅÍ¸¦ °Ë»öÇÒ ¼ö ÀÖ´Â ÀÚ·á ±¸Á¶ÀÔ´Ï´Ù.

	// ÇØ½Ã Ãæµ¹À» ÇØ°áÇÏ´Â ¹æ¹ı

	// 1. Ã¼ÀÌ´× ±â¹ı
	// °¢ ÇØ½Ã ¹öÅ¶À» ¿¬°á ¸®½ºÆ®·Î ±¸¼ºÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.
	// ÇØ½Ã Ãæµ¹ ¹ß»ı ½Ã µ¿ÀÏÇÑ ÇØ½Ã °ª¿¡ µ¥ÀÌÅÍµéÀ» ¿¬°á¸®½ºÆ®·Î ¿¬°áÇÏ¿© ÀúÀåÇÕ´Ï´Ù.

	// 2. °³¹æ ÁÖ¼Ò¹ı
	// Ãæµ¹ ¹ß»ı ½Ã ºó ¹öÅ¶¿¡ µ¥ÀÌÅÍ¸¦ ÀúÀåÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.
	// ºó ¹öÅ¶À» ¾î¶»°Ô °áÁ¤ÇÒ Áö¿¡ µû¶ó ±¸Çö ¹æ½ÄÀÌ ´Ş¶óÁı´Ï´Ù.

	// 2.1 ¼±Çü Å½»ç : Ãæµ¹ ¹ß»ı ½Ã ¾Õ¿¡¼­ºÎÅÍ Â÷·Ê´ë·Î
	// ºó ¹öÅ¶À» Ã£¾Æ ÀúÀåÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.

	// 2.2 ÀÌÂ÷ Å½»ç : Ãæµ¹ ¹ß»ı ½Ã 2Á¦°ö ¶Ç´Â 2ÀÇ 3Á¦°ö¸¸Å­
	// ¶³¾îÁø ºó ¹öÅ¶À» Ã£¾Æ °ªÀ» ÀúÀåÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.

	// 2.3 ÀÌÁß ÇØ½Ì : ÇØ½Ã °ªÀ» ÇÑ¹ø ´õ ÇØ½Ã ÇÔ¼ö¿¡¼­
	// ´Ù¸¥ ÇÔ¼ö¸¦ µµÃâÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.
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
