#include <iostream>
#include <vector>

using namespace std;

enum Direction { EAST = 1, WEST, NORTH, SOUTH };

typedef struct
{
	int dx;
	int dy;
}Point;

// 바닥면 기준으로 해당 방향 값
typedef struct {
	int north; 	// 북
	int south; 	// 남
	int east;		// 동
	int west;		// 서
	int top;		// 맞은편
	int bottom;	// 바닥
}Dice;

int width; // 가로 = 길이
int height;// 세로 = 높이

Dice dice; // 주사위


// index 1~4만 사용
// 1 동, 2 서, 3 북, 4 남
Point command_move[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

// 주사위 값
int dice_value[7] = {0, 0, 0, 0, 0, 0, 0};

// 맵 인덱스 체크
bool OutOfIndex(int r, int c) {
	if ( r >= height || r < 0 )
		return true;
	if ( c >= width || c < 0 )
		return true;
	return false;
}

// 주사위 초기화 (전역 변수)
void DiceInit() {
	dice.north	= 2; 	// 북
	dice.south	= 5; 	// 남
	dice.east		= 3;	// 동
	dice.west		= 4;	// 서
	dice.top		= 1;	// 맞은편
	dice.bottom	= 6;	// 바닥
}

// 주사위 업데이트
void UpdateDiceState(int cmd) {
	Dice tmp = dice;
	switch (cmd) {
		case EAST:
			dice.west = tmp.bottom;
			dice.east = tmp.top;
			dice.top	= tmp.west;
			dice.bottom = tmp.east;
			break;

		case WEST:
			dice.west = tmp.top;
			dice.east = tmp.bottom;
			dice.top	= tmp.east;
			dice.bottom = tmp.west;
			break;

		case SOUTH:
			dice.north	= tmp.bottom;
			dice.south	= tmp.top;
			dice.top	= tmp.north;
			dice.bottom = tmp.south;
			break;

		case NORTH:
			dice.north	= tmp.top;
			dice.south	= tmp.bottom;
			dice.top	= tmp.south;
			dice.bottom = tmp.north;
			break;
	}

	// 주사위가 오른쪽(동) 구르면
	// 동 = 윗면
	// 서 = 바닥
	// 남 = 동일
	// 북 = 동일
	// 윗면 = 서쪽
	// 바닥 = 동쪽

	// 주사위가 왼쪽(서) 구르면
	// 동 = 바닥
	// 서 = 윗면
	// 남 = 동일
	// 북 = 동일
	// 윗면 = 동쪽
	// 바닥 = 서쪽

	// 주사위가 아래(남) 구르면
	// 동 = 동일
	// 서 = 동일
	// 남 = 윗면 
	// 북 = 바닥
	// 윗면 = 북
	// 바닥 = 남

	// 주사위가 위로(북) 구르면
	// 동 = 동일
	// 서 = 동일
	// 남 = 바닥
	// 북 = 윗면
	// 윗면 = 남
	// 바닥 = 북
}

int main()
{

	// 지도 사이즈
	cin >> height >> width;
	int map[height][width];

	// 주사위 시작 좌표
	int x, y;
	cin >> x >> y;
	
	// 명령 개수
	int command_count;
	cin >> command_count;

	// 지도 세팅
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	// 명령 입력
	vector<int> command_v;
	for (int i = 0; i < command_count; i++) {
		int cmd;
		cin >> cmd;
		command_v.push_back(cmd);
	}

	// 주사위 초기화
	DiceInit();

	// 명령 실행
	for (int i = 0; i < command_v.size(); i++) {
		int cmd = command_v[i];
		int dx = command_move[cmd].dx;
		int dy = command_move[cmd].dy;
		//cout << cmd << " : ";

		// 해당 방향 인데스 체크
		if (OutOfIndex(x + dx, y + dy)) {
			//cout << "인덱스 에러" << endl;
			continue;
		}

		// 좌표 이동, 여기서 x 는 행, y 는 열을 의미
		x = x + dx;
		y = y + dy;

		// 주사위 상태 값 갱신
		UpdateDiceState(cmd);

		// 주사위 값과 지도 값 확인
		if (map[x][y] == 0) {
			map[x][y] = dice_value[dice.bottom];
		} 	
		else { // 해당 칸에 값이 있으면
			dice_value[dice.bottom] = map[x][y];
			map[x][y] = 0;
		}

		// 윗면 값 출력
		cout << dice_value[dice.top] << endl;
	}

	return 0;
}
