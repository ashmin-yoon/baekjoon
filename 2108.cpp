//
// 틀린 부분 찾기 어려워서 여러 풀이 글들 찾아봄
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // round 함수 = 반올림

using namespace std;

int main() {
	double avg = 0;	// 평균
	double sum = 0;	// 합산
	int median; 		// 중앙값
	vector<int> mode;// 최빈값
	int scale;			// 범위 최대 - 최소


	int num;
	cin >> num;
	int count = 0;

	vector<int> v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
		sum += v[i];
	}

	// 정렬
	sort(v.begin(), v.end());

	// 산술평균
	avg = (double)sum / num;
    if (avg < 0)
    {
        avg -= 0.5; // 블로그 아이디어
    } else {
        avg += 0.5;
    }

	// 중앙값
	median = v[v.size() / 2];

	// 최빈값
	int tmp_count = 0;
	int tmp = v[0];
	int max_count = 0;
	for (int i = 0; i < num; i++) {
		// 같으면
		if (tmp == v[i]) {
			tmp_count++;
			continue;
		}

		// 다르면
		if (max_count < tmp_count) {
			max_count = tmp_count;
			mode.clear();
			mode.push_back(tmp);
		}
		else if (max_count == tmp_count) {
			mode.push_back(tmp);
		}
		tmp = v[i];
		tmp_count = 1;
	}

	if (max_count < tmp_count) {
		max_count = tmp_count;
		mode.clear();
		mode.push_back(tmp);
	}
	else if (max_count == tmp_count) {
		mode.push_back(tmp);
	}

	// 범위
	scale = abs(v.back() - v.front());

	// 결과 출력
	cout << (int)avg << endl;

	// 중앙값
	cout << median << endl;

	// 최빈값
	if (mode.size() == 1)
		cout << mode[0] << endl;
	else
		cout << mode[1] << endl;

	// 범위
	cout << scale << endl;

	return 0;
}
