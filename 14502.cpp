#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_SIZE = 8;
const int INF = 987654321;

const int SPACE = 0;
const int WALL = 1;
const int VIRUS = 2;

int N, M;
int ans = INF;

int map[MAX_SIZE][MAX_SIZE];
int tmp_map[MAX_SIZE][MAX_SIZE];

int min_virus_count = INF;
int wall_count = 0;

vector<pair<int, int> > virus_point;

int dy[4] = {-1, 0, 1, 0 }; // 위 오 아 왼
int dx[4] = {0, 1, 0, -1 };

bool visited[MAX_SIZE][MAX_SIZE];

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

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == VIRUS)
				virus_point.push_back(make_pair(i, j));
			else if (map[i][j] == WALL)
				wall_count++;
		}
	}
}

void PrintMap() {
	cout << "PrintMap" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void CopyMapToTmpMap() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp_map[i][j] =  map[i][j];
		}
	}
}

int BFS_TmpMap(int y, int x, int cnt) {

	if (tmp_map[y][x] != VIRUS)
		return cnt;

	// 바이러스 위치 부터 시작
	cnt++;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		//cout << "(" << y << ", " << x << ")\n";

		// 중단 조건
		// 현재 발견한 최소 값을 초과하지 않도록
		if (cnt >= min_virus_count)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			if (OutOfRange(next_y, next_x)) continue;
			if (tmp_map[next_y][next_x] == SPACE)
			{
				tmp_map[next_y][next_x] = VIRUS;
				q.push(make_pair(next_y, next_x));
				cnt++;
			}
		}
	}

	return cnt;
}

int CalcVirusCount() {

	// map -> tmp_map 복사
	CopyMapToTmpMap();

	int cnt = 0;

	for (int i = 0; i < virus_point.size(); i++)
	{
		int y = virus_point[i].first;
		int x = virus_point[i].second;
		cnt = BFS_TmpMap(y, x, cnt);
	}

	return cnt;
}

void WallBruteFroce(int count, int level)
{
	if (count == 3)
	{
		//PrintMap();
		min_virus_count= min(min_virus_count, CalcVirusCount());
		return;
	}

	for (int l = level; l < N*M; l++)
	{
		int i = l / M;
		int j = l % M;

		if (map[i][j] == SPACE && !visited[i][j])
		{
			map[i][j] = WALL;
			WallBruteFroce(count + 1, l + 1);
			map[i][j] = SPACE;
		}

	}
}

int main()
{
	FastIO();
	Input();

	wall_count += 3; // 벽 3개 추가

	WallBruteFroce(0, 0);

	ans = (N * M) - min_virus_count - wall_count;
	cout << ans << endl;
	return 0;
}
