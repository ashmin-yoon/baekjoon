#include <iostream>
#include <vector>

using namespace std;

int value[41];

int main() {

	int num, vip_count;
	cin >> num;
	cin >> vip_count;

	//vip 설정 제일 앞, 뒤 따로 추가
	vector<int> vip(vip_count + 1);
	for (int i = 1; i < vip.size(); i++) {
		cin >> vip[i];
	}
	vip.push_back(num + 1);

	//vip 좌석을 기준으로 각 사이사이 좌석 수 계산
	vector<int> sit_count;
	for (int i = 1; i < vip.size(); i++) {	
		int tmp = vip[i] - vip[i - 1] - 1;
		if (tmp > 0) {
			sit_count.push_back(tmp);
		}
	}

	value[1] = 1;
	value[2] = 2;

	for (int i = 3; i <= 40; i++) {
		value[i] = value[i - 1] + value[i - 2];
		// 해당 수식은 초기 범위를 손으로 써본 결과 발견
	}

	int result = 1;

	for (int i = 0; i < sit_count.size(); i++) {
		//cout << sit_count[i] << endl; 
		// 해당 각 좌석 수로 만들 수 있는 경우의 수를 곱하면 답이 나옴
		result *= value[sit_count[i]];
	}

	cout << result << endl;

	return 0;
}
