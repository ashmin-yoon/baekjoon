#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	string str;
	cin >> str;

	int result = 0;

	// - 를 만나면 - 시작 지점 부터 다음 - 를 만나는 지점까지 괄호로 묶인다고 생각
	// 그렇다면 최소값이 될 것
	// 또는 마이너스가 하나라도 나온 시점부터는 뒤에 숫자들은 전부 마이너스라고 생각해도 될 듯함
	string str_num;
	vector<char> op;
	vector<int> nums;

	// 값 세팅
	for (int i = 0; i < str.length(); i++) {
		switch(str[i]) {
			case '+': case '-':
				op.push_back(str[i]); // 연산자 추가
				nums.push_back(stoi(str_num)); // 숫자 추가
				str_num = "";
				break;
			
			default:
				str_num += str[i];
				break;
		}
	}
	nums.push_back(stoi(str_num));


	// 값 연산
	bool minus_on = false;
	int minus_value = 0;
	int first_minus_index = op.size(); // 초기값 = 전체가 플러스라 가정

	for (int i = 0; i < op.size(); i++) {
		if(op[i] == '-') {
			first_minus_index = i;
			break;
		}
	}


	for (int i = 0; i < nums.size(); i++) {
		if (i <= first_minus_index)
			result += nums[i];
		else
			result -= nums[i];
	}
	cout << result << endl;

	return 0;
}
