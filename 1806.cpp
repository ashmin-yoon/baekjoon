#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100000;
const int INF = 987654321;

int arr[MAX_SIZE];
int N;
int S;

int ans = INF;


int main() {

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = arr[0];
	int count = 1;


	while(start < N && end < N)
	{
		if (sum >= S)
		{
			ans = min(ans, count);
			sum -= arr[start];
			start++;
			count--;
		}
		else if (sum < S && end < N)
		{
			sum += arr[++end];
			count++;
		}
	}


	if (ans == INF)
		cout << 0;
	else
		cout << ans;


	return 0;
}
