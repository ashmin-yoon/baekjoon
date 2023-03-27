#include <iostream>

using namespace std;

int N;
int L;

int main() {


	cin >> N;
	cin >> L;



	bool isFind = false;
	int left = 0;
	int right = 0;
	for (int length = L; length <= 100; length++)
	{
		// 각 길이별 탐색
		// 해당 길이로 만든 합이 N 보다 작아지면 길이를 늘림
		left = N / length;
		right = left + length - 1;
		int sum = (left + right) * length / 2;


		while(left >= 0)
		{
			if (sum < N)
			{
				break;
			}
			else if (sum == N) {
				isFind = true;
				break;
			}
			else 
			{
				left--;
				sum += left;
				sum -= right;
				right--;
			}

		}

		if (isFind)
			break;
	}


	// 출력
	if (isFind)
	{
		for (int i = left; i <= right; i++)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << -1 << endl;
	}
	

	return 0;
}
