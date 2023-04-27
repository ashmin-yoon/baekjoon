#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_SIZE = 501;
const int INF = 987654321;

/*
	 문제에서 요구하는 것
	 인접한 파일 합쳐 비용 최소

	 접근 방법은 어느정도 비슷했지만
	 결국 다른 사람 코드 봄
	https://www.acmicpc.net/board/view/94412
	해당 코드 조금 수정
*/

int K;
int T;
int arr[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE]; // [start][end]  start~end 합
int pSum[MAX_SIZE];
int ans;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	ans = INF; 

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			dp[i][j] = INF;
		}
	}
}


int FindCost(int start, int end) {

	// 자기 자신 0반환
	// 포함된 값은 sum에 있음
	if (start == end) {
		return 0;
	}

	int &ret = dp[start][end];

	// 이미 구함
	if (ret != INF) {
		return ret;
	}

	// [0]은 비워져있음
	int sum = pSum[end] - pSum[start - 1];


	int rev = 0;
	for (int mid = start; mid < end; mid++) {
		int s_value = FindCost(start, mid) + FindCost(mid + 1, end) + sum;
		ret = min(ret, s_value);
	}

	// 현재 비용 합 =  단순 start ~ end 합 + 조합으로 만든 가중치
	return ret;
}

int Solution() {
	Init();
	// Top down
	return FindCost(1, K);
}

void Input() {
	cin >> K;
	// index [1, K]
	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		pSum[i] = pSum[i - 1] + arr[i];
	}
}

int main() {
	FastIO();

	cin >> T;
	while(T--) 
	{
		Input();
		cout << Solution() << "\n";
	}
}
