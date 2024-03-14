#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 2012

using namespace std;

int n,k;
int f[1005][1005];
//int c[1005][1005];

int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d",&n,&k);
	//int l = k,r = n-k-1;
	f[1][0] = 1;
	for(ri i = 2;i <= n;i ++){
		f[i][0] = 1;
		for(ri j = 1;j < i;j ++)
			f[i][j] = (f[i-1][j-1] * (i-j) + f[i-1][j] * (j+1)) % mod;
	}
	/*c[0][1] = 1;
	for(ri i = 1;i <= n;i ++){
		c[i][0] = c[i][i] = 1;
		for(ri j = 1;j < i;j ++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}*/
	/*for(ri i = 0;i <= n;i ++){
		for(ri j = 1;j <= i+1;j ++)
			cout << c[i][j] << " ";
		cout << endl;
	}*/
	
	/*int ans = 0;
	for(ri i = 0;i <= n;i ++)
		//for(ri j = 0;j <= n;j ++)
			ans = (ans + c[n-1][i] * f[i][l]) % mod;*/
	printf("%d\n",f[n][k]);
	return 0;
}
