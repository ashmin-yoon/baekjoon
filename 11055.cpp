#include <iostream>
#include <cmath>

using namespace std;
const int MAX_SIZE = 1000;

int N;
int arr[MAX_SIZE];
int sum[MAX_SIZE];
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

	// sum[i] = arr[i] + 이전의 최고치
	for (int i = 0; i < N; i++)
	{
		int preMaxSum = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && preMaxSum < sum[j])
			{
				preMaxSum = sum[j];
			}
		}
		sum[i] = arr[i] + preMaxSum;
		ans = max(ans, sum[i]);
	}

	cout << ans;

	return 0;
}
