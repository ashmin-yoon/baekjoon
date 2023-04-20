#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

/**
	컴파일 
	g++ -std=c++17 옵션 추가

	문제 분류 힌트 확인
	stl map 활용법 검색

	효율적인 코드를 작성하지 못하겠어서
	문제 풀 목적으로 풀어서 씀

	*/


string str[3];

typedef struct Data{
	string stick[3];

	Data() {}
	Data(string stick[]) {
		for (int i = 0; i < 3; i++) {
			this->stick[i] = stick[i];
		}
	}

	Data(string & st0, string & st1, string& st2) {
		stick[0] = st0;
		stick[1] = st1;
		stick[2] = st2;
	}

	// 키 값의 순서 비교 정의
	// 이부분은 stl 사용법 예시를 안 보고는 작성 힘들 듯 하다.
	bool operator< (const Data& b) const {
		if (stick[0] == b.stick[0])
		{
			if (stick[1] == b.stick[1])
			{
				return stick[2] < b.stick[2];
			}
			return stick[1] < b.stick[1];
		}
		return stick[0] < b.stick[0];
	};

}Data;


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}


void Input() {
	int count = 0;
	char ch;
	for (int i = 0; i < 3; i++) {
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> ch;
			str[i] += ch;
		}
	}
}

// 원판들, 막대 번호
bool validate(string data, int stick_num) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i] != stick_num + 'A')
			return false;
	}

	return true;
}

int Solution() {

	string stick[3];
	map<Data, int> m; // map 원판들, 원판 개수
	map<Data, int>::iterator it;

	// [i] 기둥에 str[i] 원판들, 원판 개수 넣음
	for (int i = 0; i < 3; i++) {
		stick[i] = str[i];
	}


	queue<Data> q;
	q.push(Data(stick));

	int move_cnt = 0;
	string next[3];


	m.insert( {Data(stick[0], stick[1], stick[2]), move_cnt} ); 


	while(!q.empty()) {
		int q_size = q.size();
		//cout << move_cnt << "이동 =================" << endl;
		while(q_size--) {
			// 데이터 꺼내기
			Data data = q.front();
			for (int i = 0; i < 3; i++) {
				stick[i] = q.front().stick[i];
				//cout << i << "번 스틱 = " << stick[i] << endl;
			}
			//cout << "\n";
			q.pop();


			int true_cnt = 0;
			// 스틱 0
			Data next_data;
			if (validate(stick[0], 0)) {
				true_cnt++; // 조건 만족 개수
			}
			else {
				string my = stick[0].substr(0, stick[0].size() - 1);
				char top = stick[0].back();
				next[1] = stick[1] + top;
				next[2] = stick[2] + top;


				// 0 -> 1 이동
				next_data = Data(my, next[1], stick[2]);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(Data(my, next[1], stick[2]));
					m.insert( {next_data, move_cnt + 1} );
				}

				// 0 -> 2 이동
				next_data = Data(my, stick[1], next[2]);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(next_data);
					m.insert( {next_data, move_cnt + 1} );
				}
			}


			// 스틱 1
			if (validate(stick[1], 1)) {
				true_cnt++; // 조건 만족 개수
			}
			else {
				string my = stick[1].substr(0, stick[1].size() - 1);
				char top = stick[1].back();
				next[0] = stick[0] + top;
				next[2] = stick[2] + top;

				// 1 -> 0 이동
				next_data = Data(next[0], my, stick[2]);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(next_data);
					m.insert( {next_data, move_cnt + 1} );
				}

				// 1 -> 2 이동
				next_data = Data(stick[0], my, next[2]);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(next_data);
					m.insert( {next_data, move_cnt + 1} );
				}
			}


			// 스틱 2
			if (validate(stick[2], 2)) {
				true_cnt++; // 조건 만족 개수
			}
			else {
				string my = stick[2].substr(0, stick[2].size() - 1);
				char top = stick[2].back();
				next[0] = stick[0] + top;
				next[1] = stick[1] + top;

				// 2 -> 0 이동
				next_data = Data(next[0], stick[1], my);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(next_data);
					m.insert( {next_data, move_cnt + 1} );
				}

				// 2 -> 1 이동
				next_data = Data(stick[0], next[1], my);
				it = m.find(next_data);
				if (it == m.end()) {
					q.push(next_data);
					m.insert( {next_data, move_cnt + 1} );
				}
			}


			// 목표 달성
			if (true_cnt == 3) {
//				cout << "목표 달성\n";
//				for (int i = 0; i < 3; i++ ){
//					cout << i << "번 스틱 = " << stick[i] << endl;
//				}
				return move_cnt;
			}
		}

		move_cnt++; // 이동 회수 증가
	}

	return move_cnt;
}



int main() {

	FastIO();
	Input();
	cout << Solution();

	return 0;
}
