/*
*    reference. https://www.acmicpc.net/source/2216526
*    + 확장된 유클리드 알고리즘 +
*/
#include <cstdio>

typedef struct _p{
    int x;
    int y;
}P;

int get_gcd(const int M, const int N, int* x, int* y)
// ax + by = gcd(x, y)
{   
    int a, b, q, r;
    P v1, v2, v3;
    
    a = M;
    b = N;
    q = a / b;
    r = a - b*q;
    if(r == 0){
        *x = 0, *y = 1;
        return N;   
    }
    v1.x = 1, v1.y = -q;
		printf("a = %d, b = %d, q = %d, r = %d, x = %d, y = %d\n", a, b ,q, r, *x, *y);
    
    a = b;
    b = r;
    q = a / b;
    r = a - b*q;
    if(r == 0){
        *x = v1.x, *y = v1.y;
        return b;
    }
    v2.x = -v1.x*q, v2.y = 1-v1.y*q;
		printf("a = %d, b = %d, q = %d, r = %d, x = %d, y = %d\n", a, b ,q, r, *x, *y);
        
    while(true){
        a = b;
        b = r;        
        q = a / b;
        r = a - b*q;
            
        if(r == 0){
            *x = v2.x, *y = v2.y;
            break;
        }
        v3.x = v1.x - v2.x*q, v3.y = v1.y - v2.y*q;
				v1 = v2;
				v2 = v3;
        //v1.x = v2.x, v1.y = v2.y;
        //v2.x = v3.x, v2.y = v3.y;
			printf("a = %d, b = %d, q = %d, r = %d, x = %d, y = %d\n", a, b ,q, r, *x, *y);
    }    
    return b;
}

int main(void)
{
    int T, M, N, x, y;
    int c1, c2, gcd, lcm;
    long long int ans, cnt;
    
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d %d %d %d", &M, &N, &x, &y);
        gcd = get_gcd(M, N, &c1, &c2);
        
        printf("%d %d %d %d %d\n", M, N, c1, c2, gcd);
        
        if( (y - x) % gcd != 0)
            puts("-1");
        else{
            cnt = (y - x)/gcd;
            if(cnt > 0)
                ans = c1 * cnt * M + x;
            else
                ans = -c2 * cnt * N + y;
            
            lcm = M*N/gcd;
            while(ans <= 0) ans += lcm;
            if(ans > lcm) ans %= lcm;
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}
