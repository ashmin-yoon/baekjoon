#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100;
const int INF = 987654321;

int W, H;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]; // 방문

const char WALL = '*';
const char SPACE = '.';


// 진행 방향
enum Direction{
	UP, RIGHT, DOWN, LEFT, NONE
};

typedef struct Info{
	int y;
	int x;
	Direction direction;
	Info() {
		direction = NONE;  // 초기 방향값
	}
	Info(int y, int x) : y(y), x(x) {}
	Info(int y, int x, Direction direction) :
		y(y), x(x), direction(direction) {}
}Info;

Info info[2];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

void PrintMap() {
	cout << "=======MAP============\n";
	for (int i =0 ; i < H; i++) {
		for (int j =0 ; j < W; j++) {
			cout << map[i][j] <<  " ";
		}
		cout << endl;
	}
}


void Input() {
	cin >> W >> H;
	int info_idx = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			// C 위치
			if (map[i][j] == 'C')
			{
				info[info_idx].y = i;
				info[info_idx].x = j;
				info_idx++;
			}
		}
	}
}

int BFS(Info& start, Info& end) {

	queue<Info> q;
	q.push(start);
	visited[start.y][start.x] = true;

	// 접근 방법을 바꾸자.
	// 빛을 쏜다는 느낌

	int mirror_cnt = -1;
	while(!q.empty())
	{
		int q_size = q.size();
		//cout << "mirror cnt = " << mirror_cnt << endl;
		while(q_size--)
		{
			int y = q.front().y;
			int x = q.front().x;
			Direction dir = q.front().direction;
			q.pop();

			//cout << "y = " << y << ", x = " << x << ", dir = " << dir << endl;

			if (dir == NONE || dir == LEFT || dir == RIGHT) {
				// 아래로
				for (int i = y + 1; i < H; i++) {
					if(visited[i][x]) continue;
					if(map[i][x] == WALL) break; // 벽 만나면 멈춤
					q.push(Info(i, x, DOWN));
					visited[i][x] = true;
				}


				// 위로 
				for (int i = y - 1; i >= 0; i--) {
					if(visited[i][x]) continue;
					if(map[i][x] == WALL) break;
					q.push(Info(i, x, UP));
					visited[i][x] = true;
				}
			}

			if (dir == NONE || dir == UP|| dir == DOWN) {
				// 왼쪽
				for (int j = x - 1; j >= 0; j--) {
					if(visited[y][j]) continue;
					if(map[y][j] == WALL) break;
					q.push(Info(y, j, LEFT));
					visited[y][j] = true;
				}

				// 오른쪽
				for (int j = x + 1; j < W; j++) {
					if(visited[y][j]) continue;
					if(map[y][j] == WALL) break;
					q.push(Info(y, j, RIGHT));
					visited[y][j] = true;
				}
			}
		}

		//cout << "\n\n";
		mirror_cnt++;

		// 정답
		if (visited[end.y][end.x]) {
			return mirror_cnt;
		}


	}

	return mirror_cnt;
}

int main() {

	Init();
	FastIO();
	Input();

	cout << BFS(info[0], info[1]) << endl;
	//PrintMap();

	return 0;
}
