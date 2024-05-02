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
		// ?´ì‹œ ?¨ìˆ˜ë¥??µí•´??ê°’ì„ ë°›ëŠ” ?„ì‹œ ë³€??
		int hashIndex = HashFunction(key);

		// ?ˆë¡œ???¸ë“œë¥??ì„±?©ë‹ˆ??
		Node* newNode = CreateNode(key, value);

		// ?¸ë“œê°€ 1ê°œë¼??ì¡´ì¬?˜ì? ?ŠëŠ”?¤ë©´
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]??head ?¬ì¸?°ì— ?ˆë¡œ???¸ë“œë¥??€?¥í•©?ˆë‹¤.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]??count ë³€?˜ì˜ ê°’ì„ ì¦ê??œí‚µ?ˆë‹¤.
			bucket[hashIndex].count++;
		}
		else // ?¸ë“œê°€ 1ê°œë¼??ì¡´ì¬?œë‹¤ë©?
		{
			// 1. newNode??next??bucket[hashIndex]??headê°’ì„ ?€?¥í•©?ˆë‹¤.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].headë¥?ë°©ê¸ˆ ?ˆë¡œ ?ì„±???¸ë“œ??ì£¼ì†Œë¥?ê°€ë¦¬í‚¤ê²??©ë‹ˆ??
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]??count ë³€?˜ì˜ ê°’ì„ ì¦ê??œí‚µ?ˆë‹¤.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. ?´ì‹œ ?¨ìˆ˜ë¥??µí•´??ê°’ì„ ë°›ëŠ” ?„ì‹œ ë³€??
		int hashIndex = HashFunction(key);

		// 2. Nodeë¥??ìƒ‰?????ˆëŠ” ?œíšŒ???¬ì¸??ë³€??? ì–¸
		Node* currentNode = bucket[hashIndex].head;

		// 3. ?´ì „ ?¸ë“œë¥??€?¥í•  ???ˆëŠ” ?¬ì¸??ë³€??? ì–¸
		Node* traceNode = nullptr;

		// 4. currentNodeê°€ nullptr?´ë¼ê³??˜ë©´ ?¨ìˆ˜ë¥?ì¢…ë£Œ?©ë‹ˆ??
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNodeë¥??´ìš©?´ì„œ ?´ê? ì°¾ê³ ???˜ëŠ” key ê°’ì„ ì°¾ìŠµ?ˆë‹¤.
		while (currentNode != nullptr)
		{
			// currentNode->key ê°’ê³¼ ?´ê? ?? œ?˜ê³  ?¶ì? keyê°’ì´ ê°™ë‹¤ë©?
			if (currentNode->key == key)
			{
				// ?´ê? ?? œ?˜ê³ ???˜ëŠ” keyê°€ head???ˆëŠ” ?¸ë“œ?¼ë©´
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// ê°?bucket??ì¹´ìš´??ê°’ì„ ê°ì†Œ?œí‚µ?ˆë‹¤.
				bucket[hashIndex].count--;

				// ?´ë‹¹ ë©”ëª¨ë¦¬ë? ?? œ?©ë‹ˆ??
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
#pragma region ?´ì‹œ ?Œì´ë¸?
	// (Key, Value)ë¡??°ì´?°ë? ?€?¥í•˜???ë£Œ êµ¬ì¡° ì¤??˜ë‚˜ë¡?
	// ë¹ ë¥´ê²??°ì´?°ë? ê²€?‰í•  ???ˆëŠ” ?ë£Œ êµ¬ì¡°?…ë‹ˆ??

	// ?´ì‹œ ì¶©ëŒ???´ê²°?˜ëŠ” ë°©ë²•

	// <ì²´ì´??ê¸°ë²•>
	// ê°??´ì‹œ ë²„í‚·???°ê²° ë¦¬ìŠ¤?¸ë¡œ êµ¬ì„±?˜ëŠ” ë°©ì‹?…ë‹ˆ??

	// ?´ì‹œ ì¶©ëŒ ë°œìƒ ???™ì¼???´ì‹œ ê°’ì— ?´ë‹¹?˜ëŠ” ?°ì´?°ë“¤??
	// ?°ê²°ë¦¬ìŠ¤?¸ë¡œ ?°ê²°?˜ì—¬ ?€?¥í•©?ˆë‹¤.

	// <ê°œë°© ì£¼ì†Œë²?
	// ì¶©ëŒ ë°œìƒ ??ë¹?ë²„ì¼“???°ì´?°ë? ?€?¥í•˜??ë°©ì‹?…ë‹ˆ??

	// ë¹?ë²„í‚·???´ë–»ê²?ê²°ì •??ì§€???°ë¼ êµ¬í˜„ ë°©ì‹???¬ë¼ì§‘ë‹ˆ??

	// ? í˜• ?ì‚¬ : ì¶©ëŒ ë°œìƒ ???ì—??ë¶€??ì°¨ë??€ë¡?ë¹?ë²„í‚·??
	// ì°¾ì•„ ?€?¥í•˜??ë°©ì‹?…ë‹ˆ??

	// ?´ì°¨ ?ì‚¬ : ì¶©ëŒ ë°œìƒ ??2^, 2^3 ë§Œí¼ ?¨ì–´ì§?ë¹?ë²„í‚·??
	// ì°¾ì•„ ê°’ì„ ?€?¥í•˜??ë°©ì‹?…ë‹ˆ??

	// ?´ì¤‘ ?´ì‹± : ?´ì‹œ ê°’ì„ ?œë²ˆ ???´ì‹œ ?¨ìˆ˜?ì„œ ?¤ë¥¸ ?¨ìˆ˜ë¥?
	// ?„ì¶œ?˜ëŠ” ë°©ì‹?…ë‹ˆ??
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
