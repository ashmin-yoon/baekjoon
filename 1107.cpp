#include <iostream>
#include <string>
#include <cmath>

using namespace std;
const int INF = 987654321;
const int DEFAULT_CHANNEL = 100;

int targetChannel = 0;
string strChannel;
int buttons[10];

enum Status{
	EQUAL,
	LOWER,
	HIGHER
};

int Solution(string selectedStr, Status preStatus) {
	if (selectedStr.length() == strChannel.length()) {
		int diff = abs(targetChannel - stoi(selectedStr));
		//cout << selectedStr << ", " << preStatus << ", 횟수 = " << selectedStr.length() + diff << endl;

		// 채널 0 선택시
		if (stoi(selectedStr) == 0) {
			return 1 + diff;
		}

		return selectedStr.length() + diff;
		// 최종 결과 계산 후 return;
	}

	int idx = selectedStr.length();
	int target = strChannel[idx] - '0';
	
	// 선택한 버튼이 목표와 같을 경우
	if (preStatus == EQUAL) {
		// 계속 같을 경우
		int equalChoice = INF;
		if (buttons[target]) {
			equalChoice =  Solution(selectedStr + strChannel[idx], EQUAL);
		}

		char lowBtn;
		char highBtn;
		int lowChoice = INF;
		int highChoice = INF;

		// 낮은 버튼
		for (int i = target - 1; i >= 0; i--) {
			if (buttons[i]) {
				lowBtn = i + '0';
				lowChoice = Solution(selectedStr + lowBtn, LOWER);
				break;
			}
		}

		// 높은 버튼
		for (int i = target + 1; i <= 9; i++) {
			if (buttons[i]) {
				highBtn = i + '0';
				highChoice = Solution(selectedStr + highBtn, HIGHER);
				break;
			}
		}

		
		return min(equalChoice, min(lowChoice, highChoice));
	}


	char choice;
	if (preStatus == LOWER) {
		for (int i = 9; i >= 0; i--) {
			if (buttons[i]) {
				choice = i + '0';
				break;
			}
		}
	}

	if (preStatus == HIGHER) {
		for (int i = 0; i <= 9; i++) {
			if (buttons[i]) {
				choice = i + '0';
				break;
			}
		}
	}

	return Solution(selectedStr + choice, preStatus);
}


// 자리수가 더 큰 가장 낮은 수
int Solution2(string selectedStr) {
	if (selectedStr.length() == strChannel.length() + 1) {
		int diff = abs(targetChannel - stoi(selectedStr));
		return selectedStr.length() + diff;
	}

	for (int i = 0; i < 10; i++) {
		if (selectedStr == "" && i == 0)
			continue;
		if (buttons[i])
			return Solution2(selectedStr + (char)(i + '0'));
	}

	// 누를 수 없는 경우
	return abs(targetChannel - DEFAULT_CHANNEL);
}

// 자리수가 더 작은 가장 높은 수 
int Solution3(string selectedStr) {
	//cout << "Solution3 " << selectedStr << endl;
	if (strChannel.length() - 1 == 0)
		return INF;

	if (selectedStr.length() == strChannel.length() - 1) {
		int diff = abs(targetChannel - stoi(selectedStr));
		return selectedStr.length() + diff;
	}

	for (int i = 9; i >= 0; i--) {
		if (buttons[i])
			return Solution3(selectedStr + (char)(i + '0'));
	}

	return INF;
}
	
int main() {
	cin >> targetChannel;

	int brokenButtonCount = 0;
	cin >> brokenButtonCount;

	// 초기화
	// memset(buttons, true, sizeof(buttons));
	for (int i = 0; i < 10; i++) {
		buttons[i] = true;
	}

	// 고장난 버튼 설정
	for (int i = 0; i < brokenButtonCount; i++) {
		int btnNumber;
		cin >> btnNumber;
		buttons[btnNumber] = false;
	}

	// 첫 글자부터 접근하기 위함
	strChannel = to_string(targetChannel);

		// 기본 채널 100에서의 이동
	int moveCountFromBase = abs(targetChannel - DEFAULT_CHANNEL);
	int ans = min(moveCountFromBase, Solution("", EQUAL));
	ans = min(ans, Solution2(""));
	ans = min(ans, Solution3(""));
	cout << ans<< endl;

	return 0;
}
