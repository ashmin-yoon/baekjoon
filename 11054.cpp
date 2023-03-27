#include <iostream>
#include <cmath>

using namespace std;
const int MAX_SIZE = 1000;

int arr[MAX_SIZE];
int N;
int increment[MAX_SIZE];
int decrement[MAX_SIZE];
int ans;

int GetIncrement(int curr)
{
	if (curr == N)
	{
		return 0;
	}

	int& ret = increment[curr];
	if (ret != -1)
		return ret;
	ret = 1;

	for (int pre = 0; pre < curr; pre++)
	{
		if (arr[pre] < arr[curr])
			ret = max(ret, GetIncrement(pre) + 1);
	}

	return ret;
}

int GetDecrement(int curr)
{
	int& ret = decrement[curr];
	if (ret != -1)
		return ret;
	ret = 1;

	for (int next = curr + 1; next < N; next++)
	{
		if (arr[next] < arr[curr])
			ret = max(ret, GetDecrement(next) + 1);
	}

	return ret;
}


int main() 
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	memset(increment, -1, sizeof(increment));
	memset(decrement, -1, sizeof(decrement));

	for (int i = 0; i < N; i++)
	{
		ans = max(ans, GetIncrement(i) + GetDecrement(i) - 1);
	}
	cout << ans << '\n';

	for (int i = 0; i < N; i++)
		cout << increment[i] << " ";
	cout << '\n';
	for (int i = 0; i < N; i++)
		cout << decrement[i] << " ";
	cout << '\n';
	return 0;
}
