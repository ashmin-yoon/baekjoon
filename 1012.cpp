#include <iostream>
#include <vector>

using namespace std;

int map[50][50] = { {0, 0}, };
int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

// 인덱스 범위 확인 - Out = true
bool IsIndexOutOfRange(int x, int y) {
	if ((x < 0) || (x >= 50))
		return true;
	if ((y < 0) || (y >= 50))
		return true;
	return false;
}

// dfs 구현 방식
void Solution(int x, int y) {
	vector<int> v;

	if (!map[x][y])
		return;

	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int tmp_x = x + move_x[i];
		int tmp_y = y + move_y[i];
		if (IsIndexOutOfRange(tmp_x, tmp_y))
			continue;

		if (map[tmp_x][tmp_y]) {
			Solution(tmp_x, tmp_y);
		}
	}	
}

void PrintMap(int length, int height) {
	cout << "======================" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < height; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void Init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
		}
	}
}

int main() {
	int num = 0;
	cin >> num;

	vector<int> answer(num, 0);
	int length, height, count;

	for (int test = 0; test < num; test++) {
		Init(); // 맵 초기화
		cin >> length;
		cin >> height;
		cin >> count;

		// 배추 입력
		for (int c = 0; c < count; c++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		// 답 구하기
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < height; j++) {
				if(map[i][j]) {
					answer[test]++;
					Solution(i, j);	
					//PrintMap(length, height);
				}
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

}
