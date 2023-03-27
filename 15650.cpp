#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 8;

char str[MAX];
int N, M;
bool selected[MAX + 1];

void Solution(int pick, int count)
{
	if (count == M)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%c ", str[i]);
		}
		printf("\n");
		return;
	}

	for (int i = pick; i <= N; i++) 
	{
		if (selected[i])
			continue;
		selected[i] = true;
		str[count] = i + '0';
		Solution(i+1, count+1);
		selected[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		selected[i] = false;
	}
	Solution(1, 0);

	return 0;
}
