#include <iostream>

using namespace std;

long long value[1001] = { 0, 1, 2 };

int main(int argc, char* argv[]) {

	long long result = 0;
	int num = 0;

	cin >> num;

	for (int i = 3; i <= num; i++) {
		value[i] = value[i - 1] +  value[i - 2];
		value[i] %= 10007; // 오버플로 발생해서 값이 달라져서 추가

		// 세로 한 줄짜리와 2칸을 만드는방법  =, ||
		// ||는 세로 한 줄 짜리와 겹치기 때문에 2는 = 만 신경 써야 함 
	}

	result = value[num];
	cout << result << endl;

	return 0;
}
