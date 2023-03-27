#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

vector<int> v;

void Solution(vector<int> numbers, int M)
{	
	if (numbers.size() == M)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			printf("%d ", numbers[i]);
		}
		printf("\n");
		return;
	}

	vector<bool> selected(v.size(), false);
	for (int i = 0; i < numbers.size(); i++) {
		selected[numbers[i]] = true;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (selected[v[i]])
			continue;
		numbers.push_back(v[i]);
		Solution(numbers, M);
		numbers.pop_back();
	}
}


int main()
{
	int N;
	int M;

	// 1 ~ N 까지 자연수 중 M개를 고른 수열
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}
	Solution(vector<int>(), M);
}
