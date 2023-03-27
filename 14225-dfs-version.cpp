#include <iostream>
using namespace std;

int N;
bool check[200001];
int arr[21];


void dfs(int idx, int count, int sum)
{
	if (count == N)
	{
		check[sum] = true;	
		return;
	}

	for (int i = idx; i < N; i++)
	{
		dfs(idx + 1, count + 1, sum);
		dfs(idx + 1, count + 1, sum + arr[idx]);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0, 0);

	int ans = 0;
	for (int i = 1; i < 200000; i++)
	{
		if (check[i] == false)
		{
			ans = i;
			break;
		}
	}

	cout << ans;
	

	return 0;
}
