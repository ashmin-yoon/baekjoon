#include <iostream>
using namespace std;
const int MAX_SIZE = 50;

int N;
int M;
int r, c;
int direction;
int arr[MAX_SIZE][MAX_SIZE];
int ans;

enum Direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

const int DIRTY = 0;
const int WALL = 1;
const int CLEAR = 2;

// direction 0 north
// 1 east
// 2 south
// 3 west

int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> r >> c;
	int d;
	cin >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	Direction dir = static_cast<Direction>(d);

	while(true) 
	{
		//cout << "r = " << r << ", c = " << c << "\t" << arr[r][c] << endl;
		// 1.
		if (arr[r][c] == DIRTY)
		{
			arr[r][c] = CLEAR;
			ans++;
		}

		// 2.
		bool isExistence = false; 
		for (int i = 0; i < 4; i++) {
			if (arr[r + dy[i]][c + dx[i]] == DIRTY)
			{
				isExistence = true;
				break;
			}
		}

		// 2-1
		if (!isExistence) 
		{
			switch(dir)
			{
				case NORTH:
					r++;
					break;
				case EAST:
					c--;
					break;
				case SOUTH:
					r--;
					break;
				case WEST:
					c++;
					break;
			}

			// 2-2
			if (arr[r][c] == WALL)
			{
				break;
			}
			else
			{ 
				// 2-1
				continue;
			}
		}

		int nextY = r;
		int nextX = c;
		// 3.1
		switch(dir)
		{
			case NORTH:
				dir = WEST;
				nextX--;
				break;
			case EAST:
				dir = NORTH;
				nextY--;
				break;
			case SOUTH:
				dir = EAST;
				nextX++;
				break;
			case WEST:
				dir = SOUTH;
				nextY++;
				break;
		}

		if (arr[nextY][nextX] == DIRTY)
		{
			r = nextY;
			c = nextX;
		}
	}

	cout << ans << "\n";

	return 0;
}
