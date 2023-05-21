#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int N;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	bool discard_turn = true;
	while(q.size() > 1) {
		if (discard_turn) {
			q.pop();
			discard_turn = false;
			continue;
		}

		q.push(q.front());
		q.pop();
		discard_turn = true;
	}

	cout << q.front();

}
