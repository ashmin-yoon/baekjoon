#include <stdio.h>
#include <unistd.h>

int farm(int N, int K) {
	//printf("%d, %d\n",N ,K);
	//sleep(1);
	if( N <= K) return 1;
	if ( N > 0 && (N - K) % 2 == 0)
		return (farm((N-K)/2, K) + farm((N+K)/2, K));
	else {
		return 1;
	}

}

int main() {
	int N = 0;
	int K = 0;
	int result = 0;

	scanf("%d %d", &N, &K);
	//printf("%d, %d\n", N, K);
	result = farm(N, K);
	printf("%d\n", result);

	return 0;
}
