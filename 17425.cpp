#include <iostream>
using namespace std;
const int MAX_SIZE = 1000001;

// 풀이 해석 https://csloth.tistory.com/20

long long SumOfAliquotArray[MAX_SIZE] = { 0 };

int main() {
	int T;
	int n;
	long sum = 0;

	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; i*j < MAX_SIZE; j++) {
			SumOfAliquotArray[i*j] += i;
		}
		SumOfAliquotArray[i] += SumOfAliquotArray[i-1];
	}

	cin >> T;

	// cout 으로 결과를 냈을 때 시간 초과
	// 속도가 빠른 printf로 처리
	while(T--) {
		scanf("%d", &n);
		printf("%lld\n", SumOfAliquotArray[n]);
	}

	return 0;
}
