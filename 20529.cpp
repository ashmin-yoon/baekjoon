#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int T, N;
int mbtiCnt[16];
int selection[3];
int ans;

string mbti[16] = {
	"ISTJ",
	"ISFJ",
	"INFJ",
	"INTJ",
	"ISTP",
	"ISFP",
	"INFP",
	"INTP",
	"ESTP",
	"ESFP",
	"ENFP",
	"ENTP",
	"ESTJ",
	"ESFJ",
	"ENFJ",
	"ENTJ"
};

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;	
	string _mbti;
	for (int i = 0; i < N; i++) {
		cin >> _mbti;
		// 해당 mbti 있음
		for (int j = 0; j < 16; j++) {
			if (_mbti == mbti[j]) {
				mbtiCnt[j]++;
				break;
			}
		}
	}
}

// 초기화
void Init() {
	ans = INF;
	for (int i = 0; i < 16; i++) {
		mbtiCnt[i] = 0;
	}
}

int GetDiffCnt(int mbti_index1, int mbti_index2) {
	string m1 = mbti[mbti_index1];
	string m2 = mbti[mbti_index2];

	int diff_cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (m1[i] != m2[i])
			diff_cnt++;
	}

	return diff_cnt;
}

int Calc() {
	int cnt = 0;
	//cout << "선택된 번호 " << selection[0] << ", " << selection[1] << ", " << selection[2] << endl;
	
	cnt += GetDiffCnt(selection[0], selection[1]);
	cnt += GetDiffCnt(selection[1], selection[2]);
	cnt += GetDiffCnt(selection[2], selection[0]);

	return cnt;
}

void Solution(int count, int index) {

	// 3명 선택됨 계산하기
	if (count == 3) {
		int dist = Calc();
		ans = min(ans, dist);
		return;
	}

	for (int i = index; i < 16; i++) {
		// 없으면 무시
		if (mbtiCnt[i] <= 0) 
			continue; 
		// 선택
		selection[count] = i;

		// 2개 이상일 경우
		if (mbtiCnt[i] >= 2) {
			mbtiCnt[i]--; // 감소
			Solution(count + 1, i); // 자신 또 선택
			mbtiCnt[i]++; // 복원
		}
		// 1개
		else {
			Solution(count + 1, i + 1);
		}
	}
}

int main() {

	cin >> T;
	while(T--) {
		Init();
		Input();
		Solution(0, 0);
		cout << ans << "\n";
	}


	return 0;
}
