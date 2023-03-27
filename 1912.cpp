#include <iostream>
using namespace std;
const int MAX = 100000;

int arr[MAX];
int N;
int ans = -987654321;
int sum = 0;

// 알고리즘 문제 해결 전략에서 본 내용 토대로 연습 중
// low <=    < high 
int findMaxSum(int low, int high) {

	// 중간 걸친 위치
	int mid = (low + high) / 2;

	int middle = arr[mid];
	int middleRight = 0;
	int middleLeft = 0;
	int tmpSum = 0;
	for (int i = mid+1; i < high; i++) {
		if (arr[i] < 0)
		{
			break;
		}
		middle += arr[i];
	}
	
	for (int i = mid - 1; i >= low; i--)
	{
		if (arr[i] < 0)
		{
			break;
		}
		middle += arr[i];
	}


	// 앞
	int front = findMaxSum(low, mid);


	// 뒤
	int back = findMaxSum(mid, high);

	return max(max(front, back), middle);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	/*
	ans = -987654321;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		ans = max(ans, sum);
		if (sum < 0) {
			sum = 0;
		}
	}
	cout << ans;
	*/

	findMaxSum

	return 0;
}
