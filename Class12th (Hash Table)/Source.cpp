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
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ������ ����ϴ�.
		int hashIndex = HashFunction(key);

		// 2. ���ο� ��带 �����մϴ�.
		Node* newNode = CreateNode(key, value);

		// 3-1. ��尡 1���� �������� ���� ���
		if (bucket[hashIndex].count == 0)
		{
			// bucket[hashIndex]�� head �����Ϳ� ���ο� ��带 �����մϴ�.
			bucket[hashIndex].head = newNode;

			// bucket[hashIndex]�� count ������ ���� ������ŵ�ϴ�.
			bucket[hashIndex].count++;
		}
		// 3-2. ��尡 1���� ������ ���
		else
		{
			// 1. newNode�� next�� bucket[hashIndex]�� head���� �����մϴ�.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head�� ��� ���� ������ ����� �ּҸ� ����Ű�� �մϴ�.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex]�� count ������ ���� ������ŵ�ϴ�.
			bucket[hashIndex].count++;
		}
	}

	void Remove(KEY key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// 2. ��带 Ž���� �� �ִ� ��ȸ�� ������ ���� ����
		Node* currentNode = bucket[hashIndex].head;

		// 3. ���� ��带 ������ �� �ִ� ������ ���� ����
		Node* traceNode = nullptr;

		// 4. currentNode��� nullptr�̶�� �ϸ� �Լ� ����
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}

		// 5. currentNode�� �̿��ؼ� ã���� �ϴ� key ���� ã���ϴ�.
		while (currentNode != nullptr)
		{
			// currentNode->key ���� �����ϰ� ���� key ���� ���� ���
			if (currentNode->key == key)
			{
				// �����ϰ��� �ϴ� key�� head�� �ִ� ����� ���
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				// �����ϰ��� �ϴ� key�� �߰��� �ִ� ����� ���
				else
				{
					traceNode->next = currentNode->next;
				}

				// 6. �� bucket�� ī��Ʈ ���� ���ҽ�ŵ�ϴ�.
				bucket[hashIndex].count--;

				// 7. �ش� �޸𸮸� ������ŵ�ϴ�.
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
#pragma region �ؽ� ���̺�(Hash Table)
	// (Key, Value)�� �����͸� �����ϴ� �ڷ� ���� �� �ϳ���
	// ������ �����͸� �˻��� �� �ִ� �ڷ� �����Դϴ�.

	// �ؽ� �浹�� �ذ��ϴ� ���

	// 1. ü�̴� ���
	// �� �ؽ� ��Ŷ�� ���� ����Ʈ�� �����ϴ� ����Դϴ�.
	// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �����͵��� ���Ḯ��Ʈ�� �����Ͽ� �����մϴ�.

	// 2. ���� �ּҹ�
	// �浹 �߻� �� �� ��Ŷ�� �����͸� �����ϴ� ����Դϴ�.
	// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

	// 2.1 ���� Ž�� : �浹 �߻� �� �տ������� ���ʴ��
	// �� ��Ŷ�� ã�� �����ϴ� ����Դϴ�.

	// 2.2 ���� Ž�� : �浹 �߻� �� 2���� �Ǵ� 2�� 3������ŭ
	// ������ �� ��Ŷ�� ã�� ���� �����ϴ� ����Դϴ�.

	// 2.3 ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ�����
	// �ٸ� �Լ��� �����ϴ� ����Դϴ�.
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
