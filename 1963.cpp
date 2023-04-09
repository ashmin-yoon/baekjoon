#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int MAX_SIZE = 10000;

bool isPime[MAX_SIZE];
bool visited[MAX_SIZE];



void InitVisited() {
	for (int i = 2; i < MAX_SIZE; i++) {
		visited[i] = false;
	}
}

bool OutOfRange(int index) {
	if (index < 1000 || index >= 10000) return true;
	return false;
}

void SetPrime() {
	for (int i = 2; i < MAX_SIZE; i++) {
		isPime[i] = true;
	}

	for (int i = 2; i < MAX_SIZE; i++) {
		if (!isPime[i]) continue;
		for (int j = i * 2; j < MAX_SIZE; j += i) {
			isPime[j] = false;
		}
	}

}

int Solution(int start, int target) {

	queue<pair<int, int> > q;
	q.push(make_pair(start, 0));
	visited[start] = true;

	while(!q.empty()) 
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//cout << "num = " << num << ", cnt = " << cnt << endl;
		if (num == target) {
			return cnt;
		}

		string str_num = to_string(num);
		// 각 자리별 숫자
		for (int i = 0; i < 4; i++) {
			int value = num - (pow(10, i) * (str_num[3 - i] - '0')); // 현재 자리 값만 뺀 값

			for (int j = 0; j < 10; j++)  // 0 ~ 9
			{
				int next = value + j * pow(10, i);
				if (OutOfRange(next)) continue;
				if (!isPime[next]) continue;
				if (visited[next]) continue;
				q.push(make_pair(next, cnt + 1));
				visited[next] = true;
			}
		}

	}

	return 0;
}

int main() {

	SetPrime();
	int T;
	int start;
	int target;

	cin >> T;
	while(T--)
	{
		InitVisited();
		cin >> start >> target;


		cout << Solution(start, target) << "\n";

	}



	return 0;
}
