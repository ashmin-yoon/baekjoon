#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 10 + 1;

int nutrient[MAX_SIZE][MAX_SIZE]; // 땅 속 양분
int A[MAX_SIZE][MAX_SIZE]; // 겨울 - 추가되는 양분의 양
vector<int> tree[MAX_SIZE][MAX_SIZE];
int N, M, K; // 땅 크기, 심을 나무 수, K년 후

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}


bool OutOfRange(int r, int c) {
	if (r < 1 || r > N) return true;
	if (c < 1 || c > N) return true;
	return false;
}

void Input() {
	cin >> N >> M >> K;

	// 추가되는 양분 값
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	// 심을 나무
	int r, c, age;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> age;
		tree[r][c].push_back(age); // 추후 정렬은 오름차순
	}
}

// r, c 트리 오름차순 정렬
void TreeSortAsc(int r, int c) {
	sort(tree[r][c].begin(), tree[r][c].end());
}

void SpringAndSummer() {

	// 나무가 자신의 나이만큼 양분 먹고, 나이 1 증가
	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			TreeSortAsc(i, j); // 해당 칸 나무 정렬
			int del_idx = tree[i][j].size();
			for (int t = 0; t < tree[i][j].size(); t++) 
			{
				// 양분 부족
				if (nutrient[i][j] < tree[i][j][t]) {
					del_idx = t; // t 부터 삭제
					break;
				}

				// 양분 흡수 -> 나이 + 1
				nutrient[i][j] -= tree[i][j][t];
				tree[i][j][t]++;
			}


			// 죽은 나무 -> 여름의 양분
			for (int t = del_idx; t < tree[i][j].size(); t++) 
			{
				nutrient[i][j] += (tree[i][j][t] / 2);
			}
			// 삭제
			tree[i][j].erase(tree[i][j].begin() + del_idx, tree[i][j].end());
		}
	}
}

void Propagate(int r, int c, int t) {
	// 인접 8칸
	for (int i = 0; i < 8; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (OutOfRange(ny, nx)) continue;
		tree[ny][nx].push_back(1); 
	}
}

// 나무 번식
void Fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int t = 0; t < tree[i][j].size(); t++) {
				int age = tree[i][j][t];
				if (age % 5 == 0) {
					Propagate(i, j, t);
				}
			}		
		}
	}
}

// 겨울 - 양분 추가
void Winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			nutrient[i][j] += A[i][j];
		}
	}
}

void Init() {
	// 양분 초기값 5
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			nutrient[i][j] = 5;
		}
	}
}


// 살아있는 나무 수
int FindAliveTreeCount() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += tree[i][j].size();
		}
	}
	return cnt;
}

int Solution() {
	Input();
	Init();

	// K 년 진행
	while(K--) {
		SpringAndSummer();
		Fall();
		Winter();
	}

	return FindAliveTreeCount();
}

int main() {
	FastIO();

	cout << Solution();

	return 0;
}
