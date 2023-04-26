#include <iostream>
using namespace std;
const int MAX_SIZE = 2001;
// 팰린드롬 palindrome
// 앞에서 읽으나 뒤에서 읽으나 같음

int arr[MAX_SIZE];
int N, M;
int S, E;

bool is_palindrome[MAX_SIZE][MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

}

bool OutOfRange(int s, int e) {
	if (s < 1 || s > N) return true;
	if (e < s || e > N) return true;
	return false;
}

void CalcPalindrome(int center) {

	// 짝수 기준
	int s = center;
	int e = center + 1;
	while(true) {
		if (OutOfRange(s, e))
			break;

		if (arr[s] != arr[e])
			break;

		is_palindrome[s][e] = true;
		s--;
		e++;
	}


	// 홀수 기준
	s = center;
	e = center;
	while(true) {
		if (OutOfRange(s, e))
			break;

		if (arr[s] != arr[e])
			break;

		is_palindrome[s][e] = true;
		s--;
		e++;
	}
}

void SetPalindrome() {
	// 센터 기준으로 palindrome 찾기
	for (int center = 1; center <= N; center++) {
		CalcPalindrome(center);
	}
}

/* 
void PrintPalindrome() {
	for (int i = 1; i <= N; i++) {
		cout << "i = " << i << " , ";
		for (int j = i; j <= N; j++) {
			cout << is_palindrome[i][j] << " ";
		}
		cout << endl;
	}
}
*/

int main() {
	FastIO();
	Input();
	SetPalindrome(); // 팰린드롬 계산
	//PrintPalindrome();

	cin >> M;
	while(M--) {
		cin >> S >> E;
		cout << is_palindrome[S][E] << "\n";
	}

	return 0;
}
