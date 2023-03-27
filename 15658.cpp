#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[100];
int op[4]; // +-*/
int MAX = -1e9;
int MIN = +1e9;

int selected[100];

void Solution(int count, int value)
{
	if (count == N-1)
	{
//		for (int i = 1; i < N; i++)
//			cout << selected[i] << " ";
//		cout << endl;
		MAX = max(MAX, value);
		MIN = min(MIN, value);
		return;
	}


	for (int i = 0; i < 4; i++)
	{
		if (op[i] <= 0) continue;
		int value2 = arr[count+1];

		op[i]--;
		selected[count+1] = i;
		if (i == 0)
			Solution(count+1, value+value2);
		if (i == 1)
			Solution(count+1, value-value2);
		if (i == 2)
			Solution(count+1, value*value2);
		if (i == 3)
			Solution(count+1, value/value2);
		op[i]++;
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	memset(selected, -1, 100);

	Solution(0, arr[0]);

	cout << MAX << "\n" << MIN << "\n";

	return 0;
}
