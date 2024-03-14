#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 10007

using namespace std;

long long pow_mod(int a,int x){
    if(x == 1)
        return a;
    long long temp = (pow_mod(a,x/2) % mod);
    temp = temp*temp % mod;
    if(x % 2 == 0)
        return temp;
    else 
        return temp * (a%mod);
}

int x[1005][1005];

int main(){
	ios::sync_with_stdio(false);
	int a,b,k,n,m;
	cin >> a >> b >> k >> n >> m;
	a=a % mod;
    b=b % mod;
	x[0][1] = 0;
	x[1][1] = 1;x[1][2] = 1;
	for(ri i = 2;i <= k;i ++)
		for(ri j = 1;j <= i+1;j ++)
			if((j == 1)||(j == (i+1)))
				x[i][j] = 1;
		    else 
				x[i][j] = (x[i-1][j-1]+x[i-1][j]) % mod;
	long long a1 = pow_mod(a,n);
	long long b1 = pow_mod(b,m);
	x[k][m+1] = x[k][m+1] % mod;
	long long ans = (x[k][m+1]*a1) % mod;
	ans = (ans*b1) % mod;
	cout << ans;
	return 0;
}
