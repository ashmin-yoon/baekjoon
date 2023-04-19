#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 50;

int board[MAX_SIZE][MAX_SIZE];
int my_group[MAX_SIZE][MAX_SIZE]; // init -1
vector<int> group; 

int N, M;

int dy[4] = {0, -1, 0, 1}; // 서 북 동 남
int dx[4] = {-1, 0, 1, 0};
int max_room_size = 0;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= M) return true;
	if (x < 0 || x >= N) return true;
	return false;
}

void SetGroup(int start_y, int start_x) {
	if (my_group[start_y][start_x] != -1)
		return;

	// 그룹이 없다면 BFS
	queue<pair<int, int> > q;
	q.push(make_pair(start_y, start_x));
	my_group[start_y][start_x] = group.size(); // 그룹 번호 지정
	group.push_back(1); // 그룹 추가

	while(!q.empty()) 
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		// cout << y << ", " << x << endl;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OutOfRange(ny, nx)) continue;

			// 비트 연산
			// 현재 칸 기준 - 해당 방향 벽 있는지 확인 - 있으면 continue;
			if (board[y][x] & (1 << i)) continue;
			if (my_group[ny][nx] != -1) continue; // 그룹 있음

			my_group[ny][nx] = my_group[start_y][start_x];
			q.push(make_pair(ny, nx));
			group[group.size() - 1]++; // 해당 그룹 개수 추가
		}
	}

	// 최대 방 크기 갱신
	max_room_size = max(max_room_size, group.back());
}

void BfsSetGroup() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			SetGroup(i, j);
		}
	}
}

void Init() {
	group.clear();
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			my_group[i][j] = -1;
		}
	}
}

// 각 칸 별 연결시 크기
int FindConnectingSize(int y, int x) {
	int my_grp = my_group[y][x];
	int rev = group[my_grp];

	// 자기 자신 기준 4방향 확인
	// 다른 그룹일 경우
	// 자신 그룹 + 해당 그룹 개수

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (OutOfRange(ny, nx)) continue;

		int neighbor_grp = my_group[ny][nx];
		if (my_grp == my_group[ny][nx]) continue;
		rev = max(rev, group[my_grp] + group[neighbor_grp]);
	}

	return rev;
}

// Get 방 연결시 최대 크기
int GetMaxSizeAfterConnecting() {
	int rev = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			rev = max(rev, FindConnectingSize(i, j));
		}
	}
	return rev;
}

int main() {
	
	FastIO(); 
	Input();
	Init();

	// 그룹 세팅
	BfsSetGroup();

	// ans 
	cout << group.size() << endl; // 방 개수
	cout << max_room_size << endl;// 최대 크기	
	cout << GetMaxSizeAfterConnecting() << endl;
	return 0;
}
