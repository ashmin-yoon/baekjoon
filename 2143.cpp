#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 1000;


int T;
int n, m;
long ans = 0;
int A[MAX_SIZE], B[MAX_SIZE];

vector<int> subSumA;
vector<int> subSumB;

void CalcSubSum(int *arr, int size, vector<int> &subSumVector) {
	for (int i = 0; i < size; i++)
	{
		int sum = arr[i];
		subSumVector.push_back(sum);

		for (int j = i + 1; j < size; j++)
		{
			sum += arr[j];
			subSumVector.push_back(sum);
		}
	}
}


int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];

	// 부분합 구하기
	CalcSubSum(A, n, subSumA);
	CalcSubSum(B, m, subSumB);

	// 오름차순 정렬
	sort(subSumA.begin(), subSumA.end(), less<int>());
	sort(subSumB.begin(), subSumB.end(), less<int>());


	// a는 오른쪽으로
	// b는 왼쪽 방향으로 진행
	int a_index = 0;	
	int b_index = subSumB.size() -1;

	// 찾기
	long a_count = 1;
	long b_count = 1;
	while(a_index < subSumA.size() && b_index >= 0)
	{
		int a_value = subSumA[a_index];
		int b_value = subSumB[b_index];

		// 같은 값 마지막 위치에서 멈춤
		// a 개수
		for (; a_index < subSumA.size() - 1; a_index++)
		{
			if (subSumA[a_index + 1] != a_value)
				break;
			a_count++;
		}

		// b 개수
		for (; b_index > 0; b_index--)
		{
			if (subSumB[b_index - 1] != b_value)
				break;
			b_count++;
		}

		//printf("a = %d, aCount = %d, \tb = %d, bCount = %d\n", a_value, a_count, b_value, b_count);

		if (a_value + b_value < T)
		{
			a_index++;
			a_count = 1; // 초기화
		}
		else if (a_value + b_value > T)
		{
			b_index--;
			b_count = 1;
		}
		else // ==
		{ 
			ans += a_count * b_count;

			a_index++;
			b_index--;

			a_count = 1;
			b_count = 1;
		}
	}

	cout << ans;
	return 0;
}
