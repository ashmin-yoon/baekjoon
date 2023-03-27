#include <stdio.h>
#include <unistd.h>

int table[50] = { 1, 5 };

long long hamburger(long long n, long long x) {
	//우선 햄버거의 총 재료 수 먼저 구해보자
//	if (n == 0) return 1;
//	if (n == 1) return 5;
//	table[n] =  
//	return 2 * hamburger(n - 1, x) + 3;

	//우선 총 패티 수는
	//f(0) = 1, 0;
	
	//만약 먹은 수< 총 개수/2 라면 f(n-1)안의 패티를 다 먹음
	//f(1) = 5, 3;
	//f(2) = 7;
	//f(3) = 15;
	int a = 1;
	int eat_func_n = 1; // 다 먹은 f 계산
	int eat_patty = 1;
	for(int i=0; i<n && a<x; ++i) { 
		a = 2 * a + 3;
		eat_patty = eat_patty * 2 + 1;
		//if(a>x)
		//	br
	}
	printf("a = %d, eat_patty = %d", a, eat_patty);


}

//long long get_total_raw_material_num(int )
long long have_patty(int n) {
	if( n == 1) return 3;
	return have_patty(n-1) * 2 + 1;
}

long long eat_patty() {
	
}

int eat_layer(long long x){
	int layer = -1;	//다 먹은 레이어를 나타내야 해서 -1부터 시작함
	int num = 1;
	if (x <= 0) return 0;

	for(; num<x; ++layer ){
		num = (2 * num) + 3;
	}
	printf("%d\n", layer);
}


int main() {
	long long n, x;

	scanf("%lld %lld", &n, &x);
	//printf("%lld", hamburger(n, x));
	eat_layer(x);
	return 0;
}
