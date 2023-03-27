#include <iostream>
#include <cmath>

using namespace std;
const int MAX_SIZE = 100000;
const int INF = 987654321;

int N;
int arr[MAX_SIZE];
int sum = 0;
int maxSum = -INF;
int tmpArr[MAX_SIZE];

int eliminateSum = 0;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> N;

	// 설명하기 애매하지만
	// sum - arr[i] 는 현재 음수 값을 포함하지 않음
	// elimiateSum + arr[i] 는 현재 음수 값 포함
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		maxSum = max(maxSum, sum);

		tmpArr[i] = sum;

		if (arr[i] > 0)	
			eliminateSum += arr[i];
		if (arr[i] < 0)
		{
			eliminateSum = max(eliminateSum + arr[i], sum - arr[i]);
		}

		if (eliminateSum != 0)
			maxSum = max(maxSum, eliminateSum);

		if (sum < 0)
		{
			sum = 0;
		}
	}

	cout << '\n' << maxSum;
	return 0;
}
