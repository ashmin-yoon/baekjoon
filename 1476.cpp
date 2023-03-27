#include <iostream>
using namespace std;

int main() {
	int earth;
	int sun;
	int moon;

	const int E = 15;
	const int S = 28;
	const int M = 19;

	// 수학적으로 풀고 싶다면
	// 확장 유클리드, 중국인의 나머지 정리 찾아보기
	

	cin >> earth >> sun >> moon;

	int x = 1;
	for (int i = 0; ; i++) {
		x = sun + S * i;
		
		int m = x % M == 0 ? M : x % M;
		int e = x % E == 0 ? E : x % E;
		if (moon == m && earth == e) {		
			cout << x << endl;
			break;
		}
	}

	return 0;
}
