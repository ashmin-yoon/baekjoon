#include <iostream>

using namespace std;

int main() {
	int fixed_costs;
	int variable_costs;
	int price;

	cin >> fixed_costs;
	cin >> variable_costs;
	cin >> price;

	// 손익 분기점 구하기
	// 없으면 -1

	int margin;
	margin = price - variable_costs;
	if (margin <= 0)
	{
		cout << -1 << endl;
		return 0; // 종료
	}


	int count = 0;
	count = fixed_costs / margin + 1;
	cout << count;

	return 0;
}
