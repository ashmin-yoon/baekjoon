#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int section[20001];
//int out_section[10001];
int adj[20001][3]; // 인접 - 위, 옆, 
int Test;
int N;
int platoon_num;		// 소대별 인원 수
int common_platoon_count;	// 공통 소대 숫자
int platoon_count;

vector<pair<int, int> > pair_v; // 짝 지어질 수 있는 경우들

void GetMaxPairCount(int pair_v_index, int count, bool preIsPaired[]) {
	int f_index = pair_v[pair_v_index].first;
	int s_index = pair_v[pair_v_index].second;
	
	if (preIsPaired[f_index] || preIsPaired[s_index]) {
		return;
	}

	bool isPaired[N*2 + 1];
	for (int i = 1; i <= N*2; i++) {
		isPaired[i] = preIsPaired[i];
	}


	
	isPaired[f_index] = true;
	isPaired[s_index] = true;
	count++;

	for (int i = pair_v_index + 1; i < pair_v.size(); i++) {
		if (!isPaired[pair_v[i].first] && !isPaired[pair_v[i].second])
			GetMaxPairCount(i, count, isPaired);
	}

	common_platoon_count = max(count, common_platoon_count);
}

void init() {
	for (int i = 1; i < 20001; i++) {
		section[i] = 0;
	}
	pair_v.clear();
}


int GetPreIndex(int cur_index) {
	int pre_index = cur_index - 1;
	// 안 원일 때
	if (cur_index == 1) {
		return N;
	}

	// 밖 원일 때
	if (cur_index == (N + 1)) {
		return 2 * N;
	}

	return pre_index;
}

int GetNextIndex(int cur_index) {
	int next_index = cur_index + 1;

	if (cur_index == N) {
		return 1;
	}

	if (cur_index == (2 * N)) {
		return 1 + N;
	}

	return next_index;
}

int GetInOutIndex(int cur_index) {
	// 현재 안쪽 원 범위
	if (cur_index <= N) {
		return cur_index + N;
	}
	// 바깥쪽 원 범위
	else {
		return cur_index - N;
	}
}

int main() {

	cin >> Test;

	while(Test--) {
		cin >> N >> platoon_num;
		init();
		//InitIsPaired();

		// 데이터 입력
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> section[N*i + j];
			}
		}

		// 인접한 위치 저장
		for (int i = 1; i <= 2 * N; i++) {
			adj[i][0] = GetPreIndex(i);
			adj[i][1] = GetNextIndex(i); // 범위를 넘어갈 때 고려
			adj[i][2] = GetInOutIndex(i);// 인, 아웃 경우에 따라 달라짐
		}

		// 가장 짝을 많이 지을 수 있는 경우 탐색
		// 우선 가능한 경우 부터 탐색
		// 1, 3, ...
		// 10, 12, ... 만 본다면 전체 탐색 가능할 듯
		int adjacent;

		// 1, 3, ... 
		for (int i = 1; i <= N; i+=2) {
			for (int j = 0; j < 3; j++) {
				adjacent = adj[i][j];
				if (section[i] + section[adjacent] <= platoon_num) {
					pair_v.push_back(make_pair(i, adjacent));
				}
			}
		}

		// n+2, n+4, ... 
		for (int i = N + 2; i <= 2 * N; i+=2) 
		{
			for (int j = 0; j < 3; j++)
			{
				adjacent = adj[i][j];
				if (section[i] + section[adjacent] <= platoon_num) {
					pair_v.push_back(make_pair(i, adjacent));
				}
			}
		}

		
		bool isPaired[20001]; // 짝 지어 졌음
		for (int i = 0; i < 20001; i++) {
			isPaired[i] = false;
		}
		for (int i = 0; i < pair_v.size(); i++) {
			GetMaxPairCount(i, 0, isPaired);
		}
		
		platoon_count = 2 * N - common_platoon_count;
		cout << platoon_count << endl;
	}



	return 0;
}
