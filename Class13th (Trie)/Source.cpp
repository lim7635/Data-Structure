#include <iostream>
#define SIZE 26
using namespace std;

#pragma region 트라이(Trie)
// 문자열 검색에 용이
// 시간 복잡도 : 문자열의 길이(N)만큼 걸림 O(N)

class Trie
{
private:
	Trie* alphabet[SIZE];

	bool final;

public:
	Trie()
	{
		final = false;

		for (int i = 0; i < SIZE; i++)
		{
			alphabet[i] = nullptr;
		}
	}

	void Insert(const char* content)
	{
		if (*content == '\0')
		{
			final = true;
			return;
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				alphabet[index] = new Trie;
				alphabet[index]->Insert(content + 1);
			}
		}
	}

	bool Find(const char* content)
	{
		if (*content == NULL)
		{
			if (final == true)
			{
				return true;
			}
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] != nullptr)
			{
				return alphabet[index]->Find(content + 1);
			}
		}
		return false;
	}

	~Trie()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (alphabet[i] != nullptr)
			{
				delete alphabet[i];
			}
		}
	}
};
#pragma endregion

int main()
{
	Trie trie;

	trie.Insert("HELLO");
	trie.Insert("WORLD");
	trie.Insert("HALLO");
	trie.Insert("WELT");

	cout << trie.Find("HELLO") << endl;
	cout << trie.Find("WORLD!") << endl;

	return 0;
}