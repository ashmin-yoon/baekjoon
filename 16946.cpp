#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_SIZE = 1000;

int N, M;
bool isWall[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int group[MAX_SIZE][MAX_SIZE];
int group_cnt[MAX_SIZE * MAX_SIZE + 1]; // 계속 틀린 이유 - 그룹 번호의 최대값보다 배열 사이즈가 작아서..
int ans[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= M) return true;
	return false;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	FastIO();
}

void InitVisited() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = false;
		}
	}
}

void Input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			isWall[i][j] = line[j] == '1' ? true : false;
		}
	}
}


void SpaceBFS(int y, int x, int group_number) {
	if (isWall[y][x] || visited[y][x])
		return;

	visited[y][x] = true;

	// 빈공간만 가능
	queue<pair<int, int> > q;
	int cnt = 0;
	q.push(make_pair(y, x));

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		cnt++;

		group[y][x] = group_number;

		for (int i = 0; i < 4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (OutOfRange(next_y, next_x)) continue;
			if (visited[next_y][next_x]) continue;
			if (isWall[next_y][next_x]) continue;

			visited[next_y][next_x] = true;
			q.push(make_pair(next_y, next_x));
		}
	}

	// 해당 그룹 번호의 0 개수
	group_cnt[group_number] = cnt;

}

bool HasEqualGroup(vector<int> &group_v, int group_number) {

	for (int i = 0; i < group_v.size(); i++)
	{
		if (group_v[i] == group_number)
		{
			return true;
		}
	}

	return false;
}

void CalcAdjSpace(int y, int x) {

	if (!isWall[y][x]) return;

	ans[y][x] = 1;

	vector<int> group_v;

	for (int i = 0; i < 4; i++)
	{
		int adj_y = y + dy[i];
		int adj_x = x + dx[i];

		if (OutOfRange(adj_y, adj_x)) continue;
		if (isWall[adj_y][adj_x]) continue;

		int group_number = group[adj_y][adj_x];
		if (HasEqualGroup(group_v, group_number)) continue; // 같은 그룹 소유 확인
		ans[y][x] += group_cnt[group_number];
		group_v.push_back(group_number);
	}

	ans[y][x] %= 10;

}

int main() {

	Init();
	Input();

	// 빈 공간 BFS로 칸 수 계산
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int group_number = i*M + j + 1; // [1 ~ N*M]
			SpaceBFS(i, j, group_number);
		}
	}

	// 인근 칸 합산
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			CalcAdjSpace(i, j);
		}
	}

	// 결과 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << ans[i][j];
		}
		cout << "\n";
	}

	return 0;
}
