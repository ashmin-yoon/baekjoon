#include <iostream>
#include <vector>

using namespace std;

int main() {

	int test_case = 0;
	cin >> test_case;

	int n, m;
	vector<int> answer;
	for (int i = 0; i < test_case; i++) {
		cin >> n >> m;

		double result = 1;
		for (int i = 0; i < n; i++) {
			result *= (m - i);
			result /= (i + 1);
		}

		for (int i = 1; i <= n; i++) {
		}

		answer.push_back((int)result);
	}

	// 전체 경우의 수
	// m * m-1 * m-2 *...  n 개 만큼
	// 중복 제거
	// 나누기 n!

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}	

	return 0;
}
