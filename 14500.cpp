#include <iostream>
#include <algorithm>
#define MAP_SIZE 500

using namespace std;

int map[MAP_SIZE][MAP_SIZE];
int rotation_map[4][MAP_SIZE][MAP_SIZE];

int width = 0;
int height = 0;

// dx, dy 0~6 7가지 도형 순서
// ㅁㅁㅁㅁ

// ㅁㅁㅁ
//   ㅁ

// ㅁㅁㅁ
// ㅁ

// ㅁㅁㅁ
//     ㅁ

// ㅁㅁ
//   ㅁㅁ

//   ㅁㅁ
// ㅁㅁ

// ㅁㅁ
// ㅁㅁ

int dx[7][4] = { 
	{0, 0, 0, 0},
	{0, 0, 0, 1},
	{0, 0, 0, 1},
	{0, 0, 0, 1},
	{0, 0, 1, 1},
	{0, 0, -1, -1},
	{0, 0, 1, 1}
};

int dy[7][4] = { 
	{0, 1, 2, 3},
	{0, 1, 2, 1},
	{0, 1, 2, 0},
	{0, 1, 2, 2},
	{0, 1, 1, 2},
	{0, 1, 1, 2},
	{0, 1, 0, 1}
};


void PrintMap(int rotation) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			cout << rotation_map[rotation][i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool OutOfRange(int i, int j) {
	if (i < 0 || i >= MAP_SIZE)
		return true;
	if (j < 0 || j >= MAP_SIZE)
		return true;
	return false;
}

int GetValue(int r, int x, int y) {
	int value = 0;
	for (int t = 0; t < 7; t++)
	{
		int tmp_value = 0;
		for (int i = 0; i < 4; i++)
		{
			int tmp_x = x + dx[t][i];
			int tmp_y = y + dy[t][i];
			if (OutOfRange(tmp_x, tmp_y)) 
			{
				tmp_value = -1;
				break;
			}
			else
			{
				tmp_value += rotation_map[r][tmp_x][tmp_y];
			}
		}
		value = max(value, tmp_value);
		if (value == tmp_value && value != 0) // 새롭게 갱신됐다면
		{

			//cout << value << "  r : " << r << " x : " << x << " y : " << y << endl;
		}
	}
	return value;
}


int GetMaxValue() {
	int max_value = 0;
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				max_value = max(max_value, GetValue(r, i, j));
			}
		}
	}

	return max_value;
}

int main() {

	cin >> height;	// 세로 먼저
	cin >> width; 	// 가로

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
			rotation_map[0][i][j] = map[i][j];
		}
	}

	// 시계 방향 90도 회전한 맵 저장
	for (int rotation = 1; rotation < 4; rotation++) {
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				rotation_map[rotation][i][j] = rotation_map[rotation-1][MAP_SIZE-1-j][i];
			}
		}
	}

	
	cout << GetMaxValue() << endl;

	return 0;	
}
