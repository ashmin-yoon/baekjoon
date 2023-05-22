#include <iostream>
using namespace std;

int data_arr[24 + 1];
int tmp[24 + 1];
int tmp_value;

// 1번만 돌리면 된다.
// 변의 길이가 2이기 때문에
// 한쪽만 양 방향으로 회전 검사
// 총 3축, 6번 검사

// 단순 구현이기에 무식한 방법으로 풀이

void PrintTmp() {
	for (int i = 1; i <= 24; i++) {
		printf("%2d ",i);
	}
	printf("\n");
	for (int i = 1; i <= 24; i++) {
		printf("%2d ", tmp[i]);
	}
	printf("\n");
}

void Input() {

	for (int i = 1; i <= 24; i++) {
		cin >> data_arr[i];
	}

}

void CopyDataToTmp() {
	for (int i = 1; i <= 24; i++) {
		tmp[i] = data_arr[i];
	}
}

// tmp 기준 검사
bool CheckAnswer() {
	// 각 면 검사
	for (int i = 0; i < 6; i++) {
		for (int j = 2; j <= 4; j++) {
			int idx = i * 4 + j;
			if (tmp[idx - 1] != tmp[idx])
				return false;
		}
	}

	return true;
}


bool TopTurnRight() {
	CopyDataToTmp();

	// 윗면
	tmp_value = tmp[1];
	tmp[1] = tmp[2];
	tmp[2] = tmp[4];
	tmp[4] = tmp[3];
	tmp[3] = tmp_value;

	// 윗면의 사이드
	for (int i = 0; i < 2; i++) {
		tmp_value = tmp[22 - i];
		tmp[22 - i] = tmp[18 - i];
		tmp[18 - i] = tmp[6 - i];
		tmp[6 - i] = tmp[14 - i];
		tmp[14 - i] = tmp_value;
	}


	return CheckAnswer();
}

bool TopTurnLeft() {
	CopyDataToTmp();

	// 윗면
	tmp_value = tmp[1];
	tmp[1] = tmp[3];
	tmp[3] = tmp[4];
	tmp[4] = tmp[2];
	tmp[2] = tmp_value;

	// 윗면의 사이드
	for (int i = 0; i < 2; i++) {
		tmp_value = tmp[22 - i];
		tmp[22 - i] = tmp[14 - i];
		tmp[14 - i] = tmp[6 - i];
		tmp[6 - i] = tmp[18 - i];
		tmp[18 - i] = tmp_value;
	}

	return CheckAnswer();
}

bool RightTurnUp() {
	CopyDataToTmp();

	// 옆면
	tmp_value = tmp[17];
	tmp[17] = tmp[19];
	tmp[19] = tmp[20];
	tmp[20] = tmp[18];
	tmp[18] = tmp_value;

	// 옆면의 사이드
	tmp_value = tmp[6];
	tmp[6] = tmp[10];
	tmp[10] = tmp[23];
	tmp[23] = tmp[2];
	tmp[2] = tmp_value;

	tmp_value = tmp[8];
	tmp[8] = tmp[12];
	tmp[12] = tmp[21];
	tmp[21] = tmp[4];
	tmp[4] = tmp_value;

	return CheckAnswer();
}

bool RightTurnDown() {
	CopyDataToTmp();

	// 옆면
	tmp_value = tmp[17];
	tmp[17] = tmp[18];
	tmp[18] = tmp[20];
	tmp[20] = tmp[19];
	tmp[19] = tmp_value;

	// 옆면의 사이드
	tmp_value = tmp[6];
	tmp[6] = tmp[2];
	tmp[2] = tmp[23];
	tmp[23] = tmp[10];
	tmp[10] = tmp_value;

	tmp_value = tmp[8];
	tmp[8] = tmp[4];
	tmp[4] = tmp[21];
	tmp[21] = tmp[12];
	tmp[12] = tmp_value;

	return CheckAnswer();
}

bool BackTurnRight() {
	CopyDataToTmp();

	// 뒷면
	tmp_value = tmp[21];
	tmp[21] = tmp[22];
	tmp[22] = tmp[24];
	tmp[24] = tmp[23];
	tmp[23] = tmp_value;

	// 뒷면의 사이드
	tmp_value = tmp[1];
	tmp[1] = tmp[15];
	tmp[15] = tmp[12];
	tmp[12] = tmp[18];
	tmp[18] = tmp_value;

	tmp_value = tmp[2];
	tmp[2] = tmp[13];
	tmp[13] = tmp[11];
	tmp[11] = tmp[20];
	tmp[20] = tmp_value;


	return CheckAnswer();
}

bool BackTurnLeft() {
	CopyDataToTmp();

	// 뒷면
	tmp_value = tmp[21];
	tmp[21] = tmp[23];
	tmp[23] = tmp[24];
	tmp[24] = tmp[22];
	tmp[22] = tmp_value;

	// 뒷면의 사이드
	tmp_value = tmp[1];
	tmp[1] = tmp[18];
	tmp[18] = tmp[12];
	tmp[12] = tmp[15];
	tmp[15] = tmp_value;

	tmp_value = tmp[2];
	tmp[2] = tmp[20];
	tmp[20] = tmp[11];
	tmp[11] = tmp[13];
	tmp[13] = tmp_value;

	return CheckAnswer();
}




int main() {
	Input();

	int ans = false;

	// 큐브를 앞면을 바라보고
	// 돌린다는 느낌
	
	if (ans || BackTurnRight())
		ans = true;
	if (ans || BackTurnLeft())
		ans = true;
	if (ans || RightTurnDown())
		ans = true;
	if (ans || RightTurnUp())
		ans = true;
	if (ans || TopTurnRight())
		ans = true;
	if (ans || TopTurnLeft()) 
		ans = true;

	cout << ans;

	return 0;
}
