#include <iostream>
#include <cmath>
#include <vector>
#define TARGET 2
#define VISIT 1
using namespace std;

typedef struct {
	int r;
	int c;
}Point;


int MAP_SIZE = 0;
int my_move[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

Point cur, desti;

bool OutOfIndex(int r, int c);
double GetDistance(Point p1, Point p2);

int main() {
	cin >> MAP_SIZE;
	cin >> cur.r >> cur.c;
	cin >> desti.r >> desti.c;

	vector<Point> v;
	int **map;
	map = new int * [MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++) {
		map[i] = new int [MAP_SIZE];
	}

	// 초기 세팅
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			map[i][j] = 0;
		}
	}
	map[cur.r][cur.c] = VISIT;
	map[desti.r][desti.c] = TARGET;
	

	Point next_p;
	int ans = 0;
	double pre_min_dist = 987654321; 
	double tmp_dist = 987654321;

	while(map[cur.r][cur.c] != TARGET) {
		//cout << "cur = {" << cur.r << ", " << cur.c << ")" << endl;
		double min_dist = 987654321;
		int change_count = 0;
		
		// 6가지 위치 확인
		for (int i = 0; i < 6; i++) {
			int dr = my_move[i][0];
			int dc = my_move[i][1];

			Point tmp_p = { cur.r + dr, cur.c + dc };

			// 벗어난 범위
			if(OutOfIndex(tmp_p.r, tmp_p.c)) {
				continue;
			}

			// 방문 했던 위치
			if (map[tmp_p.r][tmp_p.c] == VISIT)
			{
				continue;
			}

			
			tmp_dist = GetDistance(tmp_p, desti);
			if (tmp_dist < min_dist) {
				change_count++;
				next_p = tmp_p;
				min_dist = tmp_dist;
				//cout << "min_dist = " << min_dist << endl;
			}

		}

		// 정답을 찾을 수 없다면
		if(change_count == 0 || min_dist >= pre_min_dist)
		{
			ans = -1;
			break;
		}

		pre_min_dist = min_dist;
		cur = next_p; // 좌표 이동
		if (map[cur.r][cur.c] != TARGET)
			map[cur.r][cur.c] = VISIT;
		ans++;
		//cout << "ans count = " << ans << endl;
	}
	//cout << "cur = {" << cur.r << ", " << cur.c << ")" << endl;
	cout << ans << endl;

	// 동적 할당 해제
	for (int i = 0; i < MAP_SIZE; i++){
		delete [] map[i];
	}
	delete [] map;

	return 0;
}


bool OutOfIndex(int r, int c) {
	if (r >= MAP_SIZE || r < 0)
		return true;
	if (c >= MAP_SIZE || c < 0)
		return true;
	return false;
}

// 이동할 좌표와 목표 지점 거리 구해서 최소값이 되는 포인트로 이동
double GetDistance(Point p1, Point p2) {
	return sqrt(pow(p2.r - p1.r, 2) + pow(p2.c - p1.c, 2));
}


