#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 3;
const int MAX_HP = 60;

int scv[MAX_SIZE];
int N;

bool visited[30][MAX_HP + 1][MAX_HP + 1][MAX_HP + 1]; // 공격 횟수, scv1, scv2, scv3 피

typedef struct Data {
	int scv1;
	int scv2;
	int scv3;
	Data() {}
	Data(int scv1, int scv2, int scv3) {
		this->scv1 = scv1;
		this->scv2 = scv2;
		this->scv3 = scv3;

		// 체력이 0 아래면 0으로 바꿔줌
		if (scv1 < 0) {
			this->scv1 = 0;
		}
		if (scv2 < 0) {
			this->scv2 = 0;
		}
		if (scv3 < 0) {
			this->scv3 = 0;
		}
	}
} Data;



void Attack(queue<Data>& q, int next_attack, int first, int second, int third) {
	int scv0;
	int scv1;
	int scv2;

	switch(first) {
		case 0:
			scv0 = scv[0] - 9;
			break;
		case 1:
			scv1 = scv[1] - 9;
			break;
		case 2:
			scv2 = scv[2] - 9;
			break;
	}


	switch(second) {
		case 0:
			scv0 = scv[0] - 3;
			break;
		case 1:
			scv1 = scv[1] - 3;
			break;
		case 2:
			scv2 = scv[2] - 3;
			break;
	}


	switch(third) {
		case 0:
			scv0 = scv[0] - 1;
			break;
		case 1:
			scv1 = scv[1] - 1;
			break;
		case 2:
			scv2 = scv[2] - 1;
			break;
	}

	// 체력 범위 벗어남
	if (scv0 < 0)
		scv0 = 0;

	if (scv1 < 0)
		scv1 = 0;

	if (scv2 < 0)
		scv2 = 0;


	if (!visited[next_attack][scv0][scv1][scv2]) {
		visited[next_attack][scv0][scv1][scv2] = true;
		q.push(Data(scv0, scv1, scv2));
	}
}

int Solution() {
	queue<Data> q;
	q.push(Data(scv[0], scv[1], scv[2]));
	visited[0][scv[0]][scv[1]][scv[2]] = true;

	// 단순 풀이를 위해 코드 지저분함
	int attack_cnt = 0;

	while(!q.empty()) {
		int q_size = q.size();
		while(q_size--) {
			scv[0] = q.front().scv1;
			scv[1] = q.front().scv2;
			scv[2] = q.front().scv3;
			q.pop();


			if (scv[0] <= 0 && scv[1] <= 0 && scv[2] <= 0) {
				return attack_cnt;
			}

			int next_attack = attack_cnt + 1;
			int n_scv0;
			int n_scv1;
			int n_scv2;

			// 공격 순서 
			Attack(q, next_attack, 0, 1, 2);
			Attack(q, next_attack, 0, 2, 1);
			Attack(q, next_attack, 1, 0, 2);
			Attack(q, next_attack, 1, 2, 0);
			Attack(q, next_attack, 2, 0, 1);
			Attack(q, next_attack, 2, 1, 0);

		}

		// 공격 횟수 증가
		attack_cnt++;
	}

	return attack_cnt;
}

int main() {

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> scv[i];
	}

	cout << Solution();

	return 0;
}
