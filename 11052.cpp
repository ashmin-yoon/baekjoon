#include <iostream>
#include <algorithm>

using namespace std;

// 합산 가격 저장
int arr[1001] = { 0 };

int main() {

	int N = 0;
	cin >> N;

	int pack[1001] = { 0 };

	for (int i = 1; i <= N; i++) {
		cin >> pack[i];	
	}

	// 초기값 세팅
	arr[0] = 0;
	arr[1] = pack[1];

	// arr 가격 정해서 최대값 넣기
	for (int i = 2; i <= N; i++) {
		int compare_value = 0;	
		for (int j = 1; j < i; j++) {
			compare_value = max(compare_value, arr[j] + arr[i-j]);
		}
		arr[i] = max(pack[i], compare_value);	

		//cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (result < arr[i])
			result = arr[i];
	}

	cout << result << endl;
	return 0;
}
