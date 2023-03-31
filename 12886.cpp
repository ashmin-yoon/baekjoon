#include <iostream>
#include <queue>
using namespace std;
const int MAX_SIZE = 501 + 500 + 500; // 더할 경우 생각


bool ans = false;
bool visited[MAX_SIZE][MAX_SIZE]; // 총 합은 같기에 A B 만 체크
int A, B, C;

typedef struct Data{
	int A;
	int B;
	int C;
	Data(int a, int b, int c) : A(a), B(b), C(c) {}
}Data;



int main() {

	int total = 0;
	cin >> A >> B >> C;
	total = A + B + C;

	// 1차 기본 조건
	if (total % 3 != 0) {
		cout << 0;
		return 0;
	}


	queue<Data> q;
	q.push(Data(A, B, C));

	while (!q.empty())
	{		
		A = q.front().A;
		B = q.front().B;
		C = q.front().C;
		q.pop();

		// printf("%d %d %d \t=%d\n", A, B, C, A+B+C);

		if (visited[A][B]) continue;
		visited[A][B] = true;

		// 정답
		if ((A == B) && (B == C)) {
			ans = true;
			break;
		}


		// 다른 그룹 선택
		int a, b, c;
		if (A != B)
		{
			a = A < B ? A + A : A - B;
			b = A < B ? B - A : B + B;
			q.push(Data(a, b, C));
		}

		if (B != C)
		{
			b = B < C ? B + B : B - C;
			c = B < C ? C - B : C + C;
			q.push(Data(A, b, c));
		}

	}


	cout << ans;

	return 0;
}
