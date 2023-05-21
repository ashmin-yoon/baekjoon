#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100000;

int N, M;
int arr[MAX_SIZE];
int findNum[MAX_SIZE];


// 시간 초과 이유
// 정답 출력 endl
// "\n" 으로 처리해야함

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> findNum[i];
	}
}

bool Exist(int number) {
	int left = 0;
	int right = N - 1;
	int mid = (left + right) / 2;

	while(left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > number) {
			right = mid - 1;
		} else if (arr[mid] < number) {
			left = mid + 1;
		} else { // equal
			return true;
		}
	}
	return false;
}

int main() {
	FastIO();
	Input();


	sort(arr, arr + N); // 정렬

	for (int i = 0; i < M; i++) {
		cout << Exist(findNum[i]) << "\n";
	}


	return 0;
}
