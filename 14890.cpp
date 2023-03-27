#include <iostream>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100;

int N;
int L;
int arr[MAX_SIZE][MAX_SIZE];
int ans;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}


	// 행 검사
	for (int r = 0; r < N; r++) {
		int preHeight = arr[r][0];
		int count = 0;
		bool isTrue = true;
		bool availableStairs = false;

		for (int c = 0; c < N; c++) {
		//	cout << "(" << r << ", " << c << ")" << isTrue << "\n";
			if (preHeight == arr[r][c])
			{
				count++;
			}
			else if (preHeight > arr[r][c])
			{
				count = 1;
				int diff = abs(preHeight - arr[r][c]);
				if (diff > 1)
				{
					isTrue = false;
					break;
				}
				// 왼쪽으로 계단 필요
				// 현재칸~L 개 탐색 
				int equalCount = 0;
				for (int right = 0; right < L; right++)
				{
					if (arr[r][c] == arr[r][c+right])
							equalCount++;
				}

				if (equalCount == L)
				{
					// 패스
					preHeight = arr[r][c];
					c = c + L - 1;
					count = 0;
					availableStairs = false;
					continue;
				}
				else {
					// 실패
					isTrue = false;
					break;
				}
				
			} 
			else // preHeight < arr[r][c]
			{
				// 실패
				int diff = abs(preHeight - arr[r][c]);
				if (diff > 1 || (diff == 1 && !availableStairs))
				{
					isTrue = false;
					break;
				}

				if (diff == 1 && availableStairs)
				{
					availableStairs = false;
				}

				count = 1;
			}

			// 계단 사용 가능
			if (count >= L)
				availableStairs = true;
			preHeight = arr[r][c];
		}

		if (isTrue) {
			// cout << r << "행 이용 가능\n";
			ans++;
		}

	}

	// 열 검사
	for (int c = 0; c < N; c++) {
		int preHeight = arr[0][c];
		int count = 0;
		bool isTrue = true;
		bool availableStairs = false;

		for (int r = 0; r < N; r++) {
			//	cout << "(" << r << ", " << c << ")" << isTrue << "\n";
			if (preHeight == arr[r][c])
			{
				count++;
			}
			else if (preHeight > arr[r][c])
			{
				count = 1;
				int diff = abs(preHeight - arr[r][c]);
				if (diff > 1)
				{
					isTrue = false;
					break;
				}
				// 왼쪽으로 계단 필요
				// 현재칸~L 개 탐색 
				int equalCount = 0;
				for (int down = 0; down < L; down++)
				{
					if (arr[r][c] == arr[r+down][c])
						equalCount++;
				}

				if (equalCount == L)
				{
					// 패스
					preHeight = arr[r][c];
					r = r + L - 1;
					count = 0;
					availableStairs = false;
					continue;
				}
				else {
					// 실패
					isTrue = false;
					break;
				}

			} 
			else // preHeight < arr[r][c]
			{
				// 실패
				int diff = abs(preHeight - arr[r][c]);
				if (diff > 1 || (diff == 1 && !availableStairs))
				{
					isTrue = false;
					break;
				}

				if (diff == 1 && availableStairs)
				{
					availableStairs = false;
				}

				count = 1;
			}

			// 계단 사용 가능
			if (count >= L)
				availableStairs = true;
			preHeight = arr[r][c];
		}

		if (isTrue) {
			//cout << c << "열 이용 가능\n";
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
