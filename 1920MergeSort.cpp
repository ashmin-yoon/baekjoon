#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_SIZE = 100000;

int N, M;
int arr[MAX_SIZE];
int findNum[MAX_SIZE];
vector<int> sorted;
 
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

// [start, end]
void MergeSort(int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	MergeSort(start, mid);
	MergeSort(mid + 1, end);

	// 정렬 시작점
	int pos_left = start;
	int pos_right = mid + 1;

	// 벡터 초기화
	sorted.clear();

	while(pos_left <= mid && pos_right <= end) {
		if (arr[pos_left] <= arr[pos_right]) {
			sorted.push_back(arr[pos_left]);
			pos_left++;
		}
		else {
			sorted.push_back(arr[pos_right]);
			pos_right++;
		}
	}

	// 남은 데이터
	for (; pos_left <= mid; pos_left++) {
		sorted.push_back(arr[pos_left]);
	}
	for (; pos_right <= end; pos_right++) {
		sorted.push_back(arr[pos_right]);
	}

	// 데이터 저장
	for (int i = 0; i < sorted.size(); i++) {
		arr[start + i] = sorted[i];
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

	MergeSort(0, N - 1);

	for (int i = 0; i < M; i++) {
		cout << Exist(findNum[i]) << "\n";
	}


	return 0;
}
