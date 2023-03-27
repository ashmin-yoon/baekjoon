#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetResult(int distance) {

	if (distance == 0)
		return 0;
	if (distance == 1)
		return 1;
	if (distance == 2)
		return 2;

	int rev = 2;
	long long value = 2; // value 가 int 자료형 일 때 범위값 때문에 특정 범위에서 오버플로로 인한 시간 초과 발생
	int plus_count = 0;
	int plus_number = 2;
	while(value < distance) {
		value = value + plus_number;
		plus_count++;
		rev++;
		cout << "plus_number = " << plus_number << endl;

		if (plus_count == 2) {
			plus_count = 0;
			plus_number++;
		}
	}

	cout << "value = " << value << endl;
	cout << "distance = " << distance << endl;
	cout << "rev = " << rev << endl;
	return rev;
}

int main() {
	int num;
	int x, y;
	cin >> num;

	vector<int> distance;
	int max_distance = 0;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		distance.push_back(y - x);
	}


	for (int i = 0; i < distance.size(); i++) {
		cout << GetResult(distance[i]) << endl;
	}

}
