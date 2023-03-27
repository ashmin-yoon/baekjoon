#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ROW;
int COL;
int T;
int air_cleaner_row[2];

vector<vector<int> > map;	// 맵에 있는 양
vector<vector<int> > tmp_map; // 확산되는 양 저장하기 위해서

typedef struct {
	int dr;
	int dc;
}Around;

Around around[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void InputData();
void SearchAirCleaner();
void TmpMapInit();
void SpreadFineDust(); // 미세먼지 확산(전체)
void Spread(int r, int c);	// 미세먼지 확산map[r][c] 칸
void CirculateAir();

void RunAirCleaner_0();
void RunAirCleaner_1();
void PrintMap();
int GetFindDustTotalAmount();

bool OutOfIndex(int r, int c);

int main() {

	int spread_amount; // 자신 - (자신/5 소수점 버림) * 확산된 방향 수

	InputData();				// 데이터 입력
	SearchAirCleaner();	// 공기 청정기 위치 찾기

	while(T--) {
		SpreadFineDust();
		CirculateAir();
		//PrintMap();
		//cout << endl << endl;
	}

	cout << GetFindDustTotalAmount() << endl;

	return 0;
}


void TmpMapInit() {
	for (int i = 0; i < tmp_map.size(); i++) {
		for (int j = 0; j < tmp_map[i].size(); j++) {
			tmp_map[i][j] = 0;
		}
	}
}

void InputData() {
	cin >> ROW >> COL;
	cin >> T;

	vector<int> zero_v(COL);

	for (int i = 0; i < ROW; i++) {
		int tmp;
		vector<int> tmp_v;
		for (int j = 0; j < COL; j++) {
			cin >> tmp;
			tmp_v.push_back(tmp);
		}
		map.push_back(tmp_v);
		tmp_map.push_back(zero_v);
	}
}

// 공기 청정기 위치 탐색
void SearchAirCleaner() {
	for (int i = 0; i < map.size(); i++) {
		if (map[i][0] == -1) {
			air_cleaner_row[0] = i;
			air_cleaner_row[1] = i + 1;
			break;
		}
	}
}


// 미세먼지 확산
void SpreadFineDust() {
	TmpMapInit();
	// 전체 순회
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			Spread(i, j);		
		}
	}
	

	// tmp_map 에는 확산된 값들
	// map 에는 확산 후 자기 자신의 자리에 남은 값
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] += tmp_map[i][j];
		}
	}

	// 인덱스 확인
	// 상하좌우에 청정기 있는지 확인 후
	// 확산 값 tmp_map에 + 더하기

}

void Spread(int r, int c) {
	int direction_count = 0;
	int spread_amount = map[r][c] / 5;
	vector<pair<int, int> > spread_point;

	for (int i = 0; i < 4; i++) {
		int dr = around[i].dr;
		int dc = around[i].dc;
		// 비정상 인덱스, 공기 청정기 칸이면 무시
		if (OutOfIndex(r + dr, c + dc) || map[r + dr][c + dc] == -1)
			continue;

		spread_point.push_back(make_pair(r + dr, c + dc));
	}	

	// 자신 칸
	map[r][c] = map[r][c] - spread_amount * spread_point.size();

	// 흩어진 칸들
	for (int i = 0; i < spread_point.size(); i++) {
		int t_row = spread_point[i].first;
		int t_col = spread_point[i].second;
		tmp_map[t_row][t_col] += spread_amount;
	}
}

void CirculateAir() {
	RunAirCleaner_0();
	RunAirCleaner_1();
}


void RunAirCleaner_0() {
	// 윗 공기 청정기
	// 0 ~ air_cleaner_row[0];
	int row = air_cleaner_row[0];
	int tmp = map[row][COL-1];

	// 아래 행
	for (int c = COL-1; c > 1; c--) {
		map[row][c] = map[row][c-1];
	}
	map[row][1] = 0; // 공기 청정기 옆칸

	// 왼쪽 열
	for (int r = row - 1; r > 0; r--) {
		map[r][0] = map[r-1][0];
	}

	// 윗 행
	for (int c = 0; c < COL - 1; c++) {
		map[0][c] = map[0][c+1];
	}

	// 오른쪽 열
	for (int r = 0; r < row; r++) {
		map[r][COL-1] = map[r+1][COL-1];
	}

	map[row-1][COL-1] = tmp;
}

void RunAirCleaner_1() {
	// 윗 공기 청정기
	// 0 ~ air_cleaner_row[0];
	int row = air_cleaner_row[1];

	// 왼쪽 열
	for (int r = row + 1; r < ROW - 1; r++) {
		map[r][0] = map[r+1][0];
	}

	// 아래 행
	for (int c = 0; c < COL - 1; c++) {
		map[ROW-1][c] = map[ROW-1][c+1];
	}

	// 오른쪽 열
	for (int r = ROW - 1; r > row; r--) {
		map[r][COL-1] = map[r-1][COL-1];
	}

	// 윗 행
	for (int c = COL-1; c > 1; c--) {
		map[row][c] = map[row][c-1];
	}

	// 공기 청정기 옆칸
	map[row][1] = 0;

	//map[row-1][COL-1] = tmp;
}



void PrintMap() {
	cout << "PrintMap()" << endl;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}


bool OutOfIndex(int r, int c) {
	if (r >= ROW || r < 0)
		return true;
	if (c >= COL || c < 0)
		return true;
	return false;
}


int GetFindDustTotalAmount() {
	int sum = 0;
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			if (map[r][c] == -1)
				continue;
			sum += map[r][c];
		}
	}

	return sum;
}
