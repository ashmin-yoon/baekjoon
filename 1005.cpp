#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int time;
	bool visit;
	vector<int> previous_buildings;
}Building;


int T; // 테스트 케이스
int N; // 건물 수
int K; // 규칙 수
int target;


void Calculate(vector<Building>& buildings, int target) {
	//buildings[target].time = 자식들의 시간 중 가장 오래 된 것
	// 방문 했던 경우 그냥 지나침
	if (buildings[target].visit)
		return;

	int pre_size;
	pre_size = buildings[target].previous_buildings.size();


	vector<int> pre_time;
	int max_time = 0;

	for (int i = 0; i < pre_size; i++) {
		int pre = buildings[target].previous_buildings[i];
		Calculate(buildings, pre);
		pre_time.push_back(buildings[pre].time);
	}

	for (int i = 0; i < pre_time.size(); i++) {
		max_time = max(max_time, pre_time[i]);
	}

	//cout << "건물 " << target << "자기자신 시간 = " << buildings[target].time << endl;
	//cout << "건물 " << target << "pre_max_time = " << max_time << endl;
	buildings[target].time += max_time; // 자기 자신과 자식 중 가장 큰 값을 더함
	//cout << "건물 " << target << " = " << buildings[target].time << endl;
	
	buildings[target].visit = true;
}


void Solution() {
	cin >> N >> K;	
	vector<Building> buildings(N + 1);

	
	for (int i = 1; i <= N; i++) {
		cin >> buildings[i].time; 	// 건물 소요 시간 입력
		buildings[i].visit = false; // 방문 초기화
	}

	// 규칙 K 개 입력
	int required, b_number;
	for (int i = 0; i < K; i++) {
		cin >> required >> b_number;
		buildings[b_number].previous_buildings.push_back(required); // 이전 건물 추가
	}
	cin >> target;

	Calculate(buildings, target);
	cout << "result = " <<  buildings[target].time << endl;
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		Solution();
	}
	
	return 0;
}
