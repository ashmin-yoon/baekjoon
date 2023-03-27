#include <iostream>
using namespace std;
const int MAX = 9;

int N;
int selected[MAX];
int visit[MAX];
void Solution(int count) {
	if (count == N)
	{
		for (int i = 0; i < count; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}


	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		selected[count] = i;
		Solution(count+1);
		visit[i] = false;
	}
}

int main() {
	cin >> N;

	Solution(0);


	return 0;
}
