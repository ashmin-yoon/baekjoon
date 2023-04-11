#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int MAX_SIZE = 1e9 + 1;

const int MUL = 0;
const int PLUS = 1;
const int MINUS = 2;
const int DIV = 3;

char operations[4] = {'*', '+', '-', '/'};



// 기존 visited bool 배열 -> map 으로 변경
// 메모리 초과로 사람들 코드 일부 참고
map<int, string> m;


bool OutOfRange(int num, int op) {
	// 기본 제한
	if (num < 1 || num >= MAX_SIZE) 
		return true;

	switch (op)
	{
		case MUL:
			if (num > (int)sqrt(MAX_SIZE - 1))
				return true;
			break;
		case PLUS:
			if ((num + num) >= MAX_SIZE)
				return true;
			break;
		case MINUS:
			// 마이너스는 무조건 0
			return true;
			break;
		case DIV:
			// 0이 아닐 때만 - 기본 제한에서 걸러짐
			// 나누기는 무조건 1
			return false;
			break;
		default:
			return true;
			
	}

	// 정상 범위
	return false;
}

// 범위 예외는 밖에서 처리
int GetNextValue(int num, int op) {

	switch (op)
	{
		case MUL:
			return num * num;
		case PLUS:
			return num + num;
			break;
		case MINUS:
			return 0;
			break;
		case DIV:
			return 1;
			break;
		default:
			return -1;
	}
}

int Bfs(int s, int t) {
	if (s == t) {
		return 0;
	}

	queue<int> q;	// 값
	q.push(s);
	m.insert({s, ""});

	while(!q.empty()) {
		int value = q.front();
		string str = m.find(value)->second;
		q.pop();

		//cout << value << endl;

		if (value == t) {
			return t;
		}

		for (int i = 0; i < 4; i++) {
			if (OutOfRange(value, i)) continue; // 범위
			int next = GetNextValue(value, i);	// 다음 값
			if (m.find(next) != m.end()) continue; // 해당 값 있음

			q.push(next);
			m.insert({next, str + operations[i]});
		}
	}
	

	// 바꿀 수 없음
	return -1;
}

int main() {

	int s, t;
	cin >> s >> t;

	int result = Bfs(s, t);

	if (result != t) {
		cout << result << endl;
		return 0;
	}

	cout << m.find(t)->second << endl;


	return 0;
}
