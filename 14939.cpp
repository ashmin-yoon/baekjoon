#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <unistd.h>
#include <stack>

using namespace std;

//vector<int, pair<int, int>> v;	//  (주변 전구 수, (ij좌표))
int result = 0;


class Info {
	public:
		Info(int arroundBulbCount, bool isLightOn, int r, int c) {
			mArroundBulbCount = arroundBulbCount;
			mIsLightOn = isLightOn;
			this->r = r;
			this->c = c;
		}
		bool operator<(Info info) const {
			if (this->mArroundBulbCount == info.mArroundBulbCount) {
				return this->mIsLightOn; // 참이면 앞에 있음
			}
			else
			{
				// 주변에 있는 전구 수로 내림차순
				return this->mArroundBulbCount > info.mArroundBulbCount;
			}
		}

		int mArroundBulbCount;
		int mIsLightOn;
		int r;
		int c;
};



void PlusCountMap(int i, int j);
void MinusCountMap(int i, int j);
//void SetArroundCount();
//void PrintArroundBulbCountMap();
void TurnOnOffLight(int i, int j, bool map[][10]);
vector<Info> SearchRoute(bool map[][10], bool visit[][10]);
void PrintMap(bool map[][10]);
void PrintStack();
void Solution(int r, int c, bool pre_map[][10], bool pre_visit[][10]);


int GetArroundCount(int r, int c, bool map[][10]);
bool CheckSuccess(bool map[][10]);


int main() {
	// 맵 세팅

	/*

	bool map[10][10];
	string str;
	for (int i = 0; i < 10; i++) 
	{
		cin >> str;
		for (int j = 0; j < 10; j++) {
			if (str[j] == 'O') {
				map[i][j] = true; // 대문자 o 'O' => 1 전구 불 들어옴
				PlusCountMap(i, j);
			}
		}
	}

	vector<Info> v;
	v = SearchRoute();

	for (int i = 0; i < v.size(); i++) {
		Solution(v[i].r, v[i].c); // 문제 해결 함수
	}
	*/
	bool map[10][10] = { false };
	bool visit[10][10] = { false };
	string str;
	for (int i = 0; i < 10; i++) 
	{
		cin >> str;
		for (int j = 0; j < 10; j++) {
			if (str[j] == 'O') {
				map[i][j] = true; // 대문자 o 'O' => 1 전구 불 들어옴
				visit[i][j] = false;
			}
		}
	}
	//PrintMap(map);
	Solution(-1, -1, map, visit);
	//cout << visit_st.size() << endl;
	return 0;
}






/*
	 void PlusCountMap(int i, int j) {
	if (i > 0)
		count[i - 1][j]++; // 위
	if (i < 9)
		count[i + 1][j]++; // 아래
	if (j > 0)
		count[i][j - 1]++; // 왼
	if (j < 9)
		count[i][j + 1]++; // 오
}

void MinusCountMap(int i, int j) {
	if (i > 0)
		count[i - 1][j]--; // 위
	if (i < 9)
		count[i + 1][j]--; // 아래
	if (j > 0)
		count[i][j - 1]--; // 왼
	if (j < 9)
		count[i][j + 1]--; // 오
}
*/

int GetArroundCount(int r, int c, bool map[][10]) {
	int rev = 0;

	if ((r > 0) && map[r - 1][c])
		rev++;
	if ((r < 9) && map[r + 1][c])
		rev++;
	if ((c > 0) && map[r][c - 1])
		rev++;
	if ((c < 9) && map[r][c + 1])
		rev++;

	return rev;
}

/*
void SetArroundCount() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			count[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j]) {
				PlusCountMap(i, j); // 전구 불 빛이 있을 때 주변 값 변경
			}
		}
	}
}


void PrintArroundBulbCountMap() {
	cout << "Count Map" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << count[i][j];
		}
		cout << "\n";
	}
}
*/

void TurnOnOffLight(int i, int j, bool map[][10]) {
	// i, j 위치에 불 바꿈	
	if (i > 0)
		map[i - 1][j] = !map[i - 1][j]; // 위
	if (i < 9)
		map[i + 1][j] = !map[i + 1][j]; // 아래
	if (j > 0)
		map[i][j - 1] = !map[i][j - 1]; // 왼
	if (j < 9)
		map[i][j + 1] = !map[i][j + 1]; // 오

	map[i][j] = !map[i][j];
}

vector<Info> SearchRoute(bool map[][10], bool visit[][10]) {
	vector<Info> v; 

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int tmp_count = GetArroundCount(i, j, map);
			if ((tmp_count >= 2) && (visit[i][j] == false)) {
				v.push_back(Info(tmp_count, map[i][j], i, j));
				//cout << tmp_count << "(" << i << ", " << j << ") "<< endl;
				//cout << visit[i][j] << endl;
			}
		}
	}	

	sort(v.begin(), v.end()); // 내림차순 정렬 - 사용자 정의

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].first << " (" << v[i].second.first << ", " << v[i].second.second << ")"endl;
	//}

	//cout << "mArroundBulbCount" << "\t" << "mIsLightOn" << "\t" << "r" << "\t" << "c" << endl;
//	cout << "정렬된 결과" << endl;
	for (int i = 0; i < v.size(); i++) {
		//cout << v[i].mArroundBulbCount << "\t" << v[i].mIsLightOn << "\t" << v[i].r << "\t" << v[i].c << endl;
	}
	//sleep(4);
	return v;
}



void PrintMap(bool map[][10]) {
	cout << "========== Map 출력 ==========" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}

bool CheckSuccess(bool map[][10]) {
	int flag = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j])
				return false;
		}
	}

	return true;
}

void Solution(int r, int c, bool pre_map[][10], bool pre_visit[][10]) {
	bool map[10][10];
	int count[10][10]; // 자기 주변에 있는 1의 개수
	bool visit[10][10] = { false }; // 방문 표시

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = pre_map[i][j];
			visit[i][j] = pre_visit[i][j];
		}
	}



	//cout << "Solution(" << r << ", " << c << ")" << endl;

	// 지금 잘못 건드려서 전체적인 오류가 생겼음
	// dfs 형태로 작성하려 했는데
	// bfs 형태로 푸는 것이 올바를 것 같음 

	//PrintMap(map);
	if ( 0 <= r && r <= 9 && 0 <= c && c <= 9) { // 정상 범주일 때
		TurnOnOffLight(r, c, map);
		visit[r][c] = true;
		cout << r << " " << c << endl;
	}

	int visit_true_count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (visit[i][j])
				visit_true_count++;
		}
	}
	cout << visit_true_count << endl;

	if (CheckSuccess(map)) {
		cout << CheckSuccess(map) << endl;
		cout << "성공" << endl;
		exit(0);
	}
	else {
		//cout << "못 찾음" << endl;
	}

	//sleep(1);
	vector<Info> v; // 벡터에 저장
	v = SearchRoute(map, visit); // 가능한 경우 탐색

	for (int i = 0; i < v.size(); i++) {
		//if (visit[v[i].r][v[i].c] == false) {
			//visit[v[i].r][v[i].c] = true; // 재귀 함수 안에서 true 시켜줌
			Solution(v[i].r, v[i].c, map, visit);
	//	}
	}	


	
}


