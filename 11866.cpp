#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;


void Solution() {
	cout << "<";


	vector<int> tmp;

	while(v.size() > 0) {
		tmp.clear();
		int remove_idx = (K - 1) % v.size();
		int value = v[remove_idx];

		// 삭제할 다음칸
		for (int i = remove_idx + 1; i < v.size(); i++) {
			tmp.push_back(v[i]);
		}
		
		// 처음 ~ 삭제할 이전칸
		for (int i = 0; i < remove_idx; i++) {
			tmp.push_back(v[i]);
		}


		v = tmp;

		if (v.size()) {
			cout << value << ", ";
		} else {
			cout << value;
		}
	}

	cout << ">";
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	Solution();

	return 0;
}
