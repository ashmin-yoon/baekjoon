#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 20;

int N;
int M;

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];


typedef struct FindData {
	int y;
	int x;
	int time;
	FindData(int y, int x, int time) :
		y(y), x(x), time(time) {}
}FindData;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input(int &y, int &x) {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				y = i; x = j;
			}
		}
	}
}

bool OutOfRange(int y, int x) {
	if (y < 0 || y >= N) return true;
	if (x < 0 || x >= N) return true;
	return false;
}


void PrintMap() {
	cout << "================\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

void InitVisited() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	}
}


bool IsEatable(int y, int x, int size) {
	if(OutOfRange(y, x)) return false;
	if (0 < map[y][x] && map[y][x] < size) return true;
	return false;
}

FindData FindEatableFish(int start_y, int start_x, int size) {
	int time = 0;

	InitVisited(); // 방문 초기화

	queue<pair<int, int> > q;
	q.push(make_pair(start_y, start_x));
	visited[start_y][start_x] = true;

	vector<pair<int, int> > list;
	while(!q.empty())
	{
		int q_size = q.size();
		while(q_size--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			//cout << "y = " << y << ", x = " << x << ", time = " << time << endl;

			// 먹을 수 있음 - 후보 추가
			if (0 < map[y][x] && map[y][x] < size)
			{
				list.push_back(make_pair(y, x));
				continue;
			}

			// 이동
			for (int i = 0; i < 4; i++)
			{
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (OutOfRange(next_y, next_x)) continue;
				if (visited[next_y][next_x]) continue;
				if (map[next_y][next_x] > size) continue; // 상어보다 큼
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = true;
			}
		}

		sort(list.begin(), list.end()); // 후보 정렬

		// 조건을 만족하는 가장 근접한 위치
		if (list.size())
		{
			return FindData(list[0].first, list[0].second, time);
		}


		time++;
		//cout << endl;
	}

	return FindData(-1, -1, 0);
}

int main() {
	int y, x;
	int size = 2;

	FastIO();
	Input(y, x); // y, x 에 상어 위치 넣어줌


	int time = 0;
	int eat_count = 0;
	pair<int, int> p;
	//while(!q.empty()) {
	while(true) {

		FindData result = FindEatableFish(y, x, size);
		// 종료 조건
		if (result.time == 0)
		{
			break;
		}

		// 시간
		time += result.time;

		// 물고기 잡아먹음
		map[y][x] = 0;
		y = result.y;
		x = result.x;
		map[y][x] = 0;
		//map[y][x] = 9; // 해당 라인은 상어가 성장해서 9를 넘기면 자기 자신을 잡아먹고 종료

		// 성장
		eat_count++;
		if (eat_count == size)
		{
			eat_count = 0;
			size++;
		}
	}

	cout << time;

	return 0;
}
 

