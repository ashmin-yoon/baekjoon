#include <iostream>
using namespace std;
const int MAX_SIZE = 20000001;
const int ZERO = 10000000;

int cnt[MAX_SIZE];
int N, M;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		cnt[ZERO + tmp]++;
	}

}

int main() {
	FastIO();
	Input();

	cin >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;	
		cout << cnt[ZERO + tmp] << " ";
	}

	return 0;
}
