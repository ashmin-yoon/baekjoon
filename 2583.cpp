#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ROW;
int COL;
int BOX;
int** map;
queue<pair<int, int> > q;
vector<int> ans;

// 위, 오른, 아래, 왼
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void ValueSetting();
void CreateMap();
void DeleteMap();
void InitMap();
void BFS(int r, int c);

bool OutOfIndex(int r, int c);

int main() {
	cin >> ROW >> COL;
	cin >> BOX;	

	
	CreateMap();
	InitMap();
	ValueSetting();

	int count = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (map[i][j] == 0) {	
				count++;
				BFS(i, j);
			}
		}
	}
	
	cout << count << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	DeleteMap();
	return 0;
}


void CreateMap() {
	map = new int * [ROW];
	for (int i = 0; i < ROW; i++) {
		map[i] = new int [COL];
	}
}

void DeleteMap() {
	for (int i = 0; i < ROW; i++) {
		delete [] map[i];
	}
	delete [] map;
}

void InitMap() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}
}

void ValueSetting() {
	int r1, r2, c1, c2;
	while (BOX--) 
	{
		cin >> c1 >> r1;
		cin >> c2 >> r2;
		for (int r = r1; r < r2; r++) {
			for (int c = c1; c < c2; c++) {
				map[r][c] = 1;
				//cout << "(" << r << ", " << c << ")" << endl;
			}
		}
	}
}


void BFS(int r, int c) {
	// 해당 영역 개수
	int tmp_count = 0;
	if (map[r][c] == 0)
	{
		q.push(make_pair(r, c));
		map[r][c] = 1;
		tmp_count++;
	}

	while(!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		//cout << "(" << pos.first << ", " << pos.second <<") 방문" << endl;

		for (int i = 0; i < 4; i++) {
			int move_r = pos.first + dr[i];
			int move_c = pos.second + dc[i];

			if (OutOfIndex(move_r, move_c)) {
				continue;
			}

			if (map[move_r][move_c] == 0) {
				q.push(make_pair(move_r, move_c));
				map[move_r][move_c] = 1;
				tmp_count++;
			}
		}
	}

	ans.push_back(tmp_count);
	
}

bool OutOfIndex(int r, int c) {
	if (r < 0 || r >= ROW)
		return true;
	if (c < 0 || c >= COL)
		return true;
	return false;
}
