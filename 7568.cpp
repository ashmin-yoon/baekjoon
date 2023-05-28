#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

typedef struct Info {
	int height;
	int weight;
}Info;

Info info[MAX_SIZE];
int N;


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input(){
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> info[i].weight;
		cin >> info[i].height;
	}
}

int GetRank(int idx) {
	int my_w = info[idx].weight;
	int my_h = info[idx].height;
	int rank = 1;

	for (int i = 0; i < N; i++) {
		if (i == idx) continue; // 자기자신

		if (info[i].weight > my_w && info[i].height > my_h)
			rank++;
	}
	return rank;
}

void Solution() {
	for (int i = 0; i < N; i++) {
		cout << GetRank(i) << " ";
	}
	cout << endl;
}

int main() {
	FastIO();
	Input();
	Solution();

	return 0;
}
