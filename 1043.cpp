#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 51;

// Union, Find 사용

int N, M;
vector<int> trueVec;
vector<int> party[MAX_SIZE];

int parent[MAX_SIZE];

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int groupX = Find(x);
	int groupY = Find(y);

	if (groupX == groupY)
		return;

	parent[groupY] = groupX;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		parent[i] = i;
	}
}

void Input() {
	cin >> N >> M;
	int num;
	cin >> num;
	int tNum;
	for (int i = 0; i < num; i++) {
		cin >> tNum;
		trueVec.push_back(tNum);
		if (i > 0) {
			Union(trueVec[0], trueVec.back());
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		party[i].resize(num);
		for (int j = 0; j < num; j++) {
			cin >> party[i][j];
			if (j > 0) {
				Union(party[i][0], party[i][j]);
			}
		}
	}
}

int main() {
	FastIO();
	Init();
	Input();

	if (trueVec.size() == 0) {
		cout << M;
		return 0;
	}


	int group = Find(trueVec[0]);
	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool isFind = false;
		for (int num : party[i]) {
			if (group == Find(num)) {
				isFind = true;
				break;
			}
		}

		if (!isFind) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
