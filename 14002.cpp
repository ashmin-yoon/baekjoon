#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;

int arr[MAX];
int ans = 0;
int N;
int preIndex[MAX];
int dp[MAX];
int ansIndex = -1;

vector<int> v;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		preIndex[i] = -1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j]) 
			{
				dp[i] = dp[j] + 1;
				preIndex[i] = j;
			}
		}
		if (ans < dp[i])
		{
			ans = dp[i];
			ansIndex = i;
		}
	}
	
	while(ansIndex != -1)
	{
		v.push_back(arr[ansIndex]);
		ansIndex = preIndex[ansIndex];
	}

	cout << ans << '\n';
	for (int i = v.size() -1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}


	return 0;
}

