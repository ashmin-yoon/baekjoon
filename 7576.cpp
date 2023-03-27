#include <iostream>
#include <queue>
#include <utility> //pair

using namespace std;
const int MAX_SIZE = 1000;

int tomato[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dy[4] = {-1, 0, 1, 0}; // 위 오른 아래 왼
int dx[4] = {0, 1, 0, -1};
int N, M;
int day;
queue<pair<int, int> > q1;
queue<pair<int, int> > q2;
enum SEQ { Q1, Q2 };
SEQ seq = Q1;

bool OutOfRange(int y, int x)
{
	if (y < 0 || N <= y) return true;
	if (x < 0 || M <= x) return true;

	return false;
}

void CheckSequence() {
	if (seq == Q1 && q1.empty())
	{
		seq = Q2;
		day++;
	}
	if (seq == Q2 && q2.empty())
	{
		seq = Q1;
		day++;
	}
}

pair<int, int> PopFront() {
	pair<int, int> rev;
	if (seq == Q1) 
	{
		rev = q1.front();
		q1.pop();
		
	} 
	else 
	{
		rev = q2.front();
		q2.pop();
		
	}
	return rev;
}

void PushBack(pair<int, int> p) {
	// 순서와 반대되는 큐에 넣어야 한다.
	if (seq == Q1) 
	{
		q2.push(p);
	} 
	else 
	{
		q1.push(p);
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> M;
	cin >> N;

	int zeroCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 0)
				zeroCount++;
			if (tomato[i][j] == 1)
				q1.push(make_pair(i, j)); // 시작 지점들
		}
	}

	// 성공 여부는 zeroCount 만큼 1로 바꿨으면 성공
	// 날짜는 queue를 두 개 이용해서
	// 임시와 전체용을 쓰면 가능하지 않을까
	pair<int, int> point;
	int count = 0;
	while(!q1.empty() || !q2.empty())
	{
		CheckSequence();
		point = PopFront();
		int y = point.first;
		int x = point.second;

		visited[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (OutOfRange(nextY, nextX)) continue;
			if (visited[nextY][nextX] || tomato[nextY][nextX]) continue;
			tomato[nextY][nextX] = 1;
			PushBack(make_pair(nextY, nextX));
			count++;
		}
	}

	if (count == zeroCount)
		cout << day << "\n";
	else
		cout << -1 << "\n";

	return 0;
}
