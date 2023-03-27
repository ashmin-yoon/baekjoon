#include <iostream>

using namespace std;
const int MAX_SIZE = 10000;

int N;
int M;
int arr[MAX_SIZE];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		cin >> arr[i];
	}

	int sum = arr[0];
	int ans = 0;

	int start = 0;
	int end = 0;

	//[start, end] 
	while(end < N)
	{
		if (sum > M) 
		{
			sum -= arr[start];
			start++;
		}
		else if (sum > M && start == end)
		{
			start++;
			end++;
			sum = arr[start];
		}
		else if (sum == M) {
			ans++;
			sum -= arr[start++];
			end++;
			sum += arr[end];
		}
		else // sum < M
		{
			end++;
			sum += arr[end];
		}

	}

	cout << ans;

	return 0;
}
