#include <iostream>

using namespace std;

int S;
string N;
int height;
int width;

// [숫자별][각 칸들]
// 각 칸은 젤 윗줄, 우측 상, 우측 하, 하단, 좌측 하, 좌측 상, 중앙
	
enum Position {
	NONE = -1,
	TOP,
	RIGHT_UP,
	RIGHT_DOWN,
	BOTTOM,
	LEFT_DOWN,
	LEFT_UP,
	MIDDLE
};
int lcd[10][7] = {
 {1, 1, 1, 1, 1, 1, 0}, // 0
 {0, 1, 1, 0, 0, 0, 0},
 {1, 1, 0, 1, 1, 0, 1}, // 2
 {1, 1, 1, 1, 0, 0, 1},
 {0, 1, 1, 0, 0, 1, 1}, // 4
 {1, 0, 1, 1, 0, 1, 1},
 {1, 0, 1, 1, 1, 1, 1},
 {1, 1, 1, 0, 0, 0, 0}, // 7
 {1, 1, 1, 1, 1, 1, 1}, 
 {1, 1, 1, 1, 0, 1, 1}  // 9
};

Position GetPosition(int r, int c)
{
	Position position = NONE;
	if (r == 0 && c != 0 && c != width-1)
		position = TOP;
	if (r == S+1 && c != 0 && c != width-1)
		position = MIDDLE;
	if (r == height-1 && c != 0 && c != width-1)
		position = BOTTOM;
	if (c == 0 && (0 < r && r <= S))
		position = LEFT_UP;
	if (c == 0 && (S+1 < r && r < height-1))
		position = LEFT_DOWN;
	if (c == width-1 && 0 < r && r <= S)
		position = RIGHT_UP;
	if (c == width-1 && S+1 < r && r < height-1)
		position = RIGHT_DOWN;

	return position;
}

int main() {
	cin >> S >> N;

	// 가로 s+2
	// 세로 2s+3
	height = 2*S + 3;
	width = S+2;
	 
	for (int r = 0; r < height; r++)
	{
		// 숫자 개수만큼
		for (int j = 0; j < N.size(); j++)
		{
			Position position = NONE;
			int number = N[j] - '0';
			for (int c = 0; c < width; c++)
			{
				position = GetPosition(r, c);
				char ch;
				switch(position)
				{
					case NONE:
						ch = ' ';
						break;
					case TOP: 
					case MIDDLE:
					case BOTTOM:
						ch = '-';
						break;
					default:
						ch = '|';
						break;
				}

				if (lcd[number][position]) cout << ch;
				else cout << " ";
			}
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
