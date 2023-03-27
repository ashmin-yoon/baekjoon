#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <unistd.h>

using namespace std;

int button[10];

bool chk(int n) {
	if (n < 0) return 0;
	do {
		if (button[n % 10]) return 0;
		n /= 10;
	} while (n);
	return 1;
}

int len(int n) {
	int l = 0;
	do {
		l++;
		n /= 10;
	} while (n);
	return l;
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int a; scanf("%d", &a);
		button[a] = 1;
	}
	int t = abs(100 - N);
	int cnt = 0;
	while (cnt < t) {
		//sleep(1);
		//cout << "cnt = " << cnt << ", N - cnt = " << N-cnt << ", N + cnt = " << N+cnt << endl;
		if (chk(N - cnt)) {
			// cout << "chk(N - cnt), cnt = " << cnt << ", " << N-cnt << endl;
			cnt += len(N - cnt);
			break;
		}
		else if (chk(N + cnt)) {
			// cout << "chk(N + cnt), cnt = " << cnt << ", " << N+cnt << endl;
			cnt += len(N + cnt);
			break;
		}
		//cout << cnt << endl;
		cnt++;
	}
	printf("%d", min(cnt, t));
}

