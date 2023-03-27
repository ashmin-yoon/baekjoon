#include <iostream>
#include <vector>
#include <algorithm>

#define ARR_SIZE 10002
using namespace std;

int section[10002][2];
bool visit[10002][2];
vector<int> adj[10002][2];

int N;
int platoon_num;		// 소대별 인원 수
int common_platoon_count;	// 공통 소대 숫자
int platoon_count;


void Init(); 	// 초기화
void Input(); // 입력 받기

bool CheckUp(int line, int c);
bool CheckSide(int line);


int HandleFirstLine();
		// 접근 방법을 바꿔서 세로 2줄로 이어진 배열,
		// 그리고 불끄기 처럼 한줄씩 처리하면서 count 한다면
		// 전체 순회를 해서 최적의 값을 찾아낼 수 있지 않을까

	// 답이 틀리는 것을 보니 또 다시 조금 바꿔서
	// 연결되어 있는 칸의 개수를 찾아서 그 개수를 통해 몇 쌍을 만들 수 있는지
	// 도출하여 pair_count += 시켜줘야 할 것 같음
	
	// 4칸이 연결되어 있으면 = 최대 2 쌍
	// 하지만 ㅓ모양 같은 경우 반례 발생
	// 2칸이 겹치는 개수를 센다면 가능할까?
	// + 2칸이 겹치는 수 - 3칸이 겹치는 


		
int main() {

	int Test;
	cin >> Test;

	while(Test--) {
		Init();
		Input();
		//PrintSection();
		
		int pair_count = 0;

		pair_count += HandleFirstLine(); // 첫 라인은 따로
		for (int line = 2; line <= N; line++)
		{
			// 위
			for (int c = 0; c < 2; c++) {
				if (CheckUp(line, c))
				{
					pair_count++;
					cout << line << "행" << c << "열" << "그리고 윗 칸" << endl;
				}
			}

			// 옆
			if (CheckSide(line))
			{
				pair_count++;
				cout << line << "행" << endl;
			}
		}
		
		cout << "pair_count = " << pair_count << endl;
		int result = 2*N - pair_count;
		cout << "result = " << result << endl;
	}
		
	return 0;
}


void Init() {
	for (int i = 0; i < ARR_SIZE; i++) {
		section[i][0] = 0;
		section[i][1] = 0;
		visit[i][0] = false;
		visit[i][1] = false;
	}

	N = 0;
	platoon_num = 0;		// 소대별 인원 수
	common_platoon_count = 0;	// 공통 소대 숫자
	platoon_count = 0;
}

void Input() {
	cin >> N >> platoon_num;

	// 데이터 입력
	for (int c = 0; c < 2; c++) {
		for (int r = 1; r <= N; r++) {
			cin >> section[r][c];
		}
		section[0][c] = section[N][c]; // 0인덱스는 마지막 요소이고
		section[N + 1][c] = section[1][c]; // 마지막 요소 다음 위치는 처음 요소 - 얘는 안 해줘도 될 수 있음
	}
}

bool CheckUp(int line, int c) {
	if (visit[line - 1][c])
		return false;

	// 0열
	if (section[line - 1][c] + section[line][c] <= platoon_num)
	{
		visit[line - 1][0] = true;
		visit[line][0] = true;
		return true;
	}

	return false;

	// 1열
	if (section[line - 1][1] + section[line][1] <= platoon_num)
	{
		return true;
	}
}

bool CheckSide(int line) {
	if (section[line][0] + section[line][1] <= platoon_num)
	{
		adj[line][0].push_back(
		return true;
	}
	return false;
}

		// 첫 라인
int HandleFirstLine() {
	if ( N < 1 )
		return 0;

	int p_count = 0;
	for (int c = 0; c < 2; c++) {
		if (section[1][c] + section[N][c] <= platoon_num)
		{
			visit[1][c] = true;
			visit[N][c] = true;
			cout << "1행" << c << "열" << "그리고 윗 칸(마지막 줄)" << endl;
			p_count++;
		}
	}

	if (section[1][0] + section[1][1] <= platoon_num)
	{
		if(visit[1][0] || visit[1][1])
			return p_count;
		cout << "1행" << endl;
		visit[1][0] = true;
		visit[1][1] = true;
		p_count++;
	}

	return p_count;

}
