#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 8000001;
const int ZERO_POSITION = 4000000;
// 정수 절대값 <= 100,000
int N, S;
int mid;
unsigned long long ans;
int arr[40];

long long SumA[MAX_SIZE];
long long SumB[MAX_SIZE];

// 계속 틀려서 접근 방법 힌트를 봤다.

int main() {

	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	mid = (N+1) / 2;

	// 앞 반절
	for (int tc = 0; tc < (1 << mid); tc++)
	{
		int sum = 0;

		for (int i = 0; i < mid; i++)
		{
			if (tc & (1 << i))
				sum += arr[i];
		}
		SumA[ZERO_POSITION + sum]++;
	}

	// 뒷 반절
	for (int tc = 0; tc < (1 << (N - mid)); tc++)
	{
		int sum = 0;
		for (int i = 0; i < N - mid; i++)
		{
			if (tc & (1 << i))
				sum += arr[mid + i];
		}
		SumB[ZERO_POSITION + sum]++;
	}



	// 내부 count int -> long 변경

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (SumA[i] == 0) continue;
		int value_a = i - ZERO_POSITION;
		long long count_a = SumA[i];

		int value_b = S - value_a;
		int value_b_idx = value_b + ZERO_POSITION;

		// 범위 벗어남
		if (value_b_idx < 0 || value_b_idx >= MAX_SIZE)
			continue;

		long long count_b = SumB[value_b_idx];
		ans += (count_a * count_b);
	}

	// S 가 0 이면 양쪽 부분 합 또한 0
	// 공집합 빼주기
	if (S == 0)
		ans -= 1;
	cout << ans;

	return 0;
}
