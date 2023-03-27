#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int num = 0;
	cin >> num;

	vector<int> v;

	int time = 0;
	for (int i = 0; i < num; i++) {
		cin >> time;
		v.push_back(time);
	}

	sort(v.begin(), v.end()); // 정렬

	int total_time = 0;
	vector<int> value(v.size());

	value[0] = v[0];
	for (int i = 1; i < v.size(); i++) {
		value[i] = v[i] + value[i - 1];
	}

	for (int i = 0; i < value.size(); i++) {
		total_time += value[i];
	}

	cout << total_time;

	return 0;
}
