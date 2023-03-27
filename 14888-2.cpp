#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 20;

int N;
int arr[MAX_SIZE];
int oper[4]; // +, -, *, /
int oper_count[4];
int MAX = -1e9;
int MIN = +1e9;


// 오랜만에 푸는 유형이라
// 정답 맞춘 후 다른 사람 답안 참고

void Solution(int count, int value) {
	if (count == N - 1)
	{
		MAX = max(MAX, value);
		MIN = min(MIN, value);
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper_count[i])
		{
			oper_count[i]--;
			int value2 = arr[count+1];
			if (i == 0)
				Solution(count+1, value + value2);
			if (i == 1)
				Solution(count+1, value - value2);
			if (i == 2)
				Solution(count+1, value * value2);
			if (i == 3)
				Solution(count+1, value / value2);
			oper_count[i]++;
		}
	}

}

using namespace std;
int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper_count[i];
	}

	Solution(0, arr[0]);
	cout << MAX << "\n" << MIN << "\n";

	return 0;
}
