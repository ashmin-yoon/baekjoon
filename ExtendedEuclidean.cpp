#include <iostream>

using namespace std;

int ExtendedEuclidean(int a, int b) {
	int r1 = a;
	int r2 = b;
	int r;

	int s1 = 1;
	int s2 = 0;
	int s;

	int t1 = 0;
	int t2 = 1;
	int t;

	int q;

	while(r2 > 0) {
		q = r1 / r2;

		// gcd 계산
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		// s 계산
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}

	s = s1;
	t = t1;
	printf("gcd(%d, %d) = %d, s = %d, t = %d \n", a, b, r1, s, t);
	int result = a * s + b * t;
	printf("%d x %d     +     %d x %d = %d \n", a, s, b, t, result);

	if (result == r1)
		cout << true << endl;
	else
		cout << false << endl;
	return r1;
}


long long inverse(int n, int p)
{
	printf("inverse(%d, %d)\n", n, p);
	long long m = p, x = 1, y = 0, q, t;
	while( m ) 
	{ 
		q = n/m; 
		t = m;
		m = n % m;
		n = t; 

		t = y;
		y = x - q*y;
		x = t;

		printf("q = %d, m = %d, n = %d, p = %d, x = %d, y = %d\n", q, m, n, p, x, y);
	}
	printf("q = %d, m = %d, n = %d, p = %d, x = %d, y = %d\n", q, m, n, p, x, y);
	if( n != 1 ) return 0;
	return (x >= 0)?x:x+p;
}

//	x = a (mod m)
//  x = ms+a, 
//	x = b (mod n)
//	ms+a = b (mod n) 
//	rms + ra = rb (mod n)  
//	s = (rb-ra)/g (mod n)

// 확장 유클리드 알고리즘
// 기억 나지 않을 때 참고용
// 학습 필요

int main() {
	int a, b;
	int m, n;
	int g;

	while(true)
	{
		cin >> m >> n >> a >> b;
		// cout << Euclidean(a, b) << endl;
		g = ExtendedEuclidean(m, n);
		if (a%g != b%g)
		{
			cout << -1 << endl;
			continue;
		}
		long long r = inverse(m/g, n/g);
		cout << "r = " << r << endl;
		long long s = (r*(b-a)/g)%(n/g);
		cout << "s = " << s << endl;
		printf("%lld\n", (m*s+a+m/g*n-1)%(m/g*n)+1);
	}

	return 0;
}
