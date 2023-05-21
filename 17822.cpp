#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_SIZE = 51;
const int CLOCKWISE = 0;
const int COUNTERCLOCKWISE = 1;

int N, M, T; // N개 원판, 각 원판 M개 숫자, T번 회전

int plate[MAX_SIZE][MAX_SIZE];

vector<int> tmp_v;
queue<pair<int, int> > q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef struct {
	int x; // x배수 원판 회전
	int d; // d 방향 0 시계, 1 반시계
	int k;
}TurnInfo;

TurnInfo turn[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M >> T;

	// 원판 정보
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> plate[i][j];
		}
	}

	// 회전 정보
	for (int i = 0; i < T; i++) {
		cin >> turn[i].x;
		cin >> turn[i].d;
		cin >> turn[i].k;
	}
}


void TurnPlate(int n, int d, int k) {
	tmp_v.clear();

	int idx = -1;

	// 시계 방향
	if (d == CLOCKWISE) {
		idx = M - k + 1;
		for (int i = idx; i <= M; i++) {
			tmp_v.push_back(plate[n][i]);
		}
		for (int i = 1; i < idx; i++) {
			tmp_v.push_back(plate[n][i]);
		}
	} 
	//  반시계 방향
	else if (d == COUNTERCLOCKWISE) {
		idx = 1 + k;
		for (int i = idx; i <= M; i++) {
			tmp_v.push_back(plate[n][i]);
		}
		for (int i = 1; i < idx; i++) {
			tmp_v.push_back(plate[n][i]);
		}
	}

	// 회전 데이터 갱신
	for (int i = 1; i <= M; i++) {
		plate[n][i] = tmp_v[i - 1];
	}
}


bool Bfs(int n, int m) {
	while(!q.empty()) {
		q.pop();
	}
	if (plate[n][m] == 0)
		return false;

	q.push(make_pair(n, m));

	int plate_value = plate[n][m];


	int cnt = 0;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 인접 범위 조정
			if (ny == 0 || ny > N) continue;
			if (nx == 0) nx = M;
			if (nx > M) nx = 1;


			if (plate[ny][nx] == 0) continue; // visited or 값 없음
			if (plate[ny][nx] != plate_value) continue;

			// 같은 값
			plate[ny][nx] = 0;
			q.push(make_pair(ny, nx));
			cnt++;
		}
	}

	if (cnt > 0) {
		plate[n][m] = 0;
		return true;
	}

	return false;
}


// 2-2
void CalcEvgAndPlusMinus() {
	double avg = 0;
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (plate[i][j] > 0) {
				cnt++;
			}
			sum += plate[i][j];
		}
	}
	avg = (double)sum / cnt;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (plate[i][j] == 0) continue;
			if (plate[i][j] > avg) 
				plate[i][j]--;
			else if (plate[i][j] < avg) 
				plate[i][j]++;
		}
	}

}

bool Oper2(int n) {
	bool hasEqualNum = false;
	for (int j = 1; j <= M; j++) {
		if (Bfs(n, j)) { // Bfs에서 인접 수 찾기+ 2-1 수행
			hasEqualNum = true;
		}
	}
	return hasEqualNum;	
}

bool HasNumber(int n) {
	bool hasNumber = false;

	// 숫자 있는지 확인
	for (int j = 1; j <= M; j++) {
		if(plate[n][j]) {
			return true;
		}
	}
	return false;
}



void PrintPlateInfo() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << plate[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



void Turn(int turn_idx) {
	TurnInfo& info = turn[turn_idx];

	// 1. x 배수 원판 d 방향으로 k칸 회전
	for (int i = 1; i <= N; i++) {
		if (i % info.x == 0)
			TurnPlate(i, info.d, info.k);
	}

	bool hasEqualNumber = false;
	for (int i = 1; i <= N; i++) {	
		// 해당 원판 숫자 가지고 있음 -> 2. 연산 수행
		if (HasNumber(i)) {
			if(Oper2(i)) {
				hasEqualNumber = true;
			}
		}
	}

	// 2-2 같은 수 없음
	if (!hasEqualNumber) {
		CalcEvgAndPlusMinus();
	}

}

int Solution() {
	for (int t = 0; t < T; t++) {
		Turn(t);
		//PrintPlateInfo();
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum += plate[i][j];
		}
	}

	return sum;
}

int main() {
	FastIO();
	Input();

	cout << Solution();

	return 0;
}
