#include <iostream>
using namespace std;
const int MAX_SIZE = 100001;

int N, M;
int arr[MAX_SIZE];
int sum[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
}

int main() {
	FastIO();
	Input();

	
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		cout << sum[end] - sum[start - 1] << "\n";
	}

	return 0;
}
