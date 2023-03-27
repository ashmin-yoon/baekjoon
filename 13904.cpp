#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 사용자 정의 함수
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second; // first가 같다면 second 오름차순

	return a.first > b.first; // first 기준 내림차순
}

bool temp_compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

int main() {
	int num = 0;
	cin >> num;	

	vector<pair<int, int> > v;
	vector<bool> selected_index(num, false); // 선택된 인덱스는 true

	for (int i = 0; i < num; i++) {
		int day, point;
		cin >> day >> point;

		v.push_back(make_pair(day, point)); // 점수, 남은 날
	}

	sort(v.begin(), v.end(), compare);
	
	/*
	cout << "정렬 후 출력" << endl;
	for (int i = 0; i < num; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	*/

	vector<pair<int, int> > temp;
	for (int i = num; i >= 1; i--) {
		temp.clear();
		for (int j = 0; j < v.size(); j++) {
			// 해당 날 보다 남은 날이 작을 경우 break;
			if (v[j].first < i)
				break;

			if (!selected_index[j])
				temp.push_back(make_pair(j, v[j].second)); // 임시 항목으로 저장 (인덱스, 포인트)
		}	

		sort(temp.begin(), temp.end(), temp_compare);
		if (temp.size()) // 데이터가 있을 경우
			selected_index[temp[0].first] = true; // 해당 인덱스는 선택되었음 - v에 저장된 인덱스를 의미
	}

	//cout << "선택된 데이터 출력" << endl;
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		if(selected_index[i]) {
			//cout << "v[" << i << "].second = " << v[i].second << endl;
			result += v[i].second;
		}
	}

	//cout << "result = " << result << endl;
	cout << result;

	// 점수 순으로 정렬
	// 점수가 가장 높은 것 중
	return 0;
}
