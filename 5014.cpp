#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 1e6 + 1; // 백만 + 1
const int ERROR = -1;

int floor;	// f
int curr; // s
int destination; // g
int up; // u
int down; // d

bool visited[MAX_SIZE];


void Input() {
	cin >> floor >> curr;
	cin >> destination;
	cin >> up >> down;
}

int Bfs() {

	queue<pair<int, int> > q;
	q.push(make_pair(curr, 0));

	while(!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();


		// 목적지
		if (pos == destination) {
			return cnt;
		}

		// 위로
		if (pos + up <= floor && !visited[pos + up]) {
			visited[pos + up] = true;
			q.push(make_pair(pos + up, cnt + 1));
		}

		// 아래로
		if (pos - down > 0 && !visited[pos - down]) {
			visited[pos - down] = true;
			q.push(make_pair(pos - down, cnt + 1));
		}
	}

	return ERROR;
}

int main() {
	Input();


	int result = Bfs();

	if (result == ERROR)
		cout << "use the stairs";
	else
		cout << result;


	return 0;
}
