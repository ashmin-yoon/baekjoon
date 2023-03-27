#include <iostream>

using namespace std;

const int MAX = 7;

int N, M;
char ch[MAX];
bool selected[MAX+1];

void Solution(int count)
{
	if (count == M)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%c ", ch[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		ch[count] = i + '0';
		Solution(count+1);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	Solution(0);
	return 0;
}
