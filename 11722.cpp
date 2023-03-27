#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;

int N;
int arr[MAX_SIZE];
int subCount[MAX_SIZE];
int ans;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && subCount[j] > subCount[i])
			{
				subCount[i] = subCount[j];
			}
		}
		subCount[i]++;
		ans = max(ans, subCount[i]);
	}
	cout << ans;

	return 0;
}
