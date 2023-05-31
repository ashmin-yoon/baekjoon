#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000000;

int N;

typedef struct Data {
	int value;
	int index;
}Data;

Data data_arr[MAX_SIZE];
int ans[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data_arr[i].value;
		data_arr[i].index = i;
	}
}

bool cmp(Data& d1, Data& d2) {
	if (d1.value == d2.value) {
		return d1.index < d2.index;
	}

	return d1.value < d2.value;
}


int main() {
	FastIO();
	Input();

	sort(data_arr, data_arr + N, cmp);

	ans[0] = 0;
	for (int i = 1; i < N; i++) {
		// 이전 데이터랑 같음 = 같은 개수
		if (data_arr[i - 1].value == data_arr[i].value) {
			ans[data_arr[i].index] = ans[data_arr[i - 1].index];
		}
		else { // 다름
			ans[data_arr[i].index] = ans[data_arr[i - 1].index] + 1;
		}
	}


	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
