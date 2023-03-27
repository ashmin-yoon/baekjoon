#include <iostream>
using namespace std;
const int MIN = -10;
const int MAX = 10;

char S[MAX][MAX];
int n; // 1 <= n <= 10
int selection[MAX];
bool isFind = false;

bool CheckCondition(int pick, int count) {
	char ch;
	int sum = pick;
	for (int i = count - 1; i >= 0; i--) {
		ch = S[i][count];		
		sum += selection[i];

		if (ch == '0' && sum != 0)
		{
			return false;
		}
		if (ch == '-' && sum >= 0)
		{
			return false;
		}
		if (ch == '+' && sum <= 0)
		{
			return false;
		}
	}
	//printf("Check Condition : pick = %d, count = %d\n", pick, count);
	return true;
}

void Solution(int count)
{
	if (isFind)
		return;

	if (count == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << selection[i] << " ";
		}
		cout << "\n";
		isFind = true;
		return;
	}
	
	// 큰 분류
	char ch = S[count][count];
	int start = MIN;
	int end = MAX + 1;
	// cout << ch << endl;
	switch(ch)
	{
		case '-':
			start = MIN;
			end = 0;
			break;
		case '0':
			start = 0;
			end = 1;
			break;
		case '+':
			start = 1;
			end = MAX + 1;
			break;
	}

	for (int i = start; i < end; i++)
	{
		// cout << i << endl;
		// 조건 확인
		if (!CheckCondition(i, count)) continue;
		selection[count] = i;
		Solution(count + 1);
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> S[i][j];
		}
	}

	Solution(0);
	return 0;
}
