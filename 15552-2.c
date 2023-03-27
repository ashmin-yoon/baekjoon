#include <stdio.h>


int main() {
	int t;
	scanf("%d", &t);
	int r[t+2];

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &r[i+1], &r[i+2]);
		r[i] = r[i+1]+r[i+2];
	}

	for (int i = 0; i < t; i++) {
		printf("%d\n", r[i]);
	}

	return 0;
}
