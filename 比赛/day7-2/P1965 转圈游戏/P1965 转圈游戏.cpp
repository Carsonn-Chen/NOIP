#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int mypow(int a,int b,int n){
    int ans = 1,base = a;
    while(b != 0){
        if(b&1)
            ans *= base,ans %= n;
        base *= base;
        base %= n;
        b >>= 1;
    }
    return ans;
}


int p[10000005];

int main(){
	int n,m,k,x;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	/*int pos = x,cnt = 0;
	p[0] = x;
	pos = (pos + m) % n;
	p[++cnt] = pos;
	while(pos != x){
		pos = (pos + m) % n;
		p[++cnt] = pos;
	}*/
	int cnt;
	if(2*m == n)
		cnt = 2;
	else
		cnt = n;
	//cout <<cnt << endl;
	/*cout << mypow(8,8) << endl;*/
	cout << (mypow(10,k,n) * m % cnt + x)%cnt;
	return 0;
}
