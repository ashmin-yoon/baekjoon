#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int value[1000001] = { 0, 0 };

int main() {

	int num = 0;
	cin >> num;

	//value[2] = 1;
	//value[3] = 1;

	vector<int> v;
	for (int i = 2; i <= num; i++) {
		v.push_back(value[i - 1]);
		if (i % 2 == 0)
			v.push_back(value[i / 2]);
		if (i % 3 == 0)
			v.push_back(value[i / 3]);

		sort(v.begin(), v.end());

		value[i] = 1 + v[0];
		v.clear();
	}

	cout << value[num] << endl;
	// value[index] 값은
	// value[index - 1], value[index/2], value[index/3] 값 중 작은 값 + 1

    // 기존에는 탑다운 재귀 방식으로 접근해서 풀고 있었으나
    // 반례 발생
    // 반례 해결하니 재귀가 너무 깊어 다른 사람 거 참고해서 품

	return 0;
}
