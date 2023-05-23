#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100;

int N, M;
int arr[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main() {
	FastIO();
	Input();

	sort(arr, arr + N);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum > M) 
					break;
				ans = max(ans, sum);
			}
		}
	}

	cout << ans;

	return 0;
}
