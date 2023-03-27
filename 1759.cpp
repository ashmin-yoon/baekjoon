#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> alphabet;
vector<bool> isVowel;
char selectedChar[15];

void PrintAlphabet()
{
	for (int i = 0; i < L; i++)
	{
		cout << selectedChar[i];
	}
	cout << endl;
}

// vowelCount 모음 개수
// consonantCount 자음 개수
void Solution(int idx, int vowelCount, int consonantCount)
{
	//printf("idx = %d, vowelCount = %d, consonantCount = %d\n", idx, vowelCount, consonantCount);
	int count = vowelCount + consonantCount;
	if (L == count)
	{	
		if (vowelCount >= 1 && consonantCount >= 2)
			PrintAlphabet();
		return;
	}


	for (int i = idx; i < alphabet.size(); i++)
	{
		selectedChar[count] = alphabet[i];
		if (isVowel[i])
			Solution(i + 1, vowelCount + 1, consonantCount);
		else
			Solution(i + 1, vowelCount, consonantCount + 1);
	}
}

int main()
{
	// 입력
	cin >> L >> C;
	char ch;
	for (int i = 0; i < C; i++)
	{
		cin >> ch;
		alphabet.push_back(ch);
	}

	// 정렬
	sort(alphabet.begin(), alphabet.end());

	// 자음 모음 구분
	for (int i = 0; i < C; i++) 
	{
		switch(alphabet[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				isVowel.push_back(true);
				break;
			default:
				isVowel.push_back(false);
				break;
		}
	}

	Solution(0, 0, 0);

	return 0;
}
