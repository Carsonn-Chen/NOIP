#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define mod 1000000007

using namespace std;

long long f[205][205],sum[205][205];
char a[1005],b[205];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	cin >> a >> b;
	f[0][0] = 1;
	for(int i = 1;i <= n;i ++)
		for(int j = m;j >= 1;j --)
			for(int k1 = 1;k1 <= k;k1 ++){
				if(a[i-1] == b[j-1]){
					sum[j][k1] = (sum[j-1][k1] + f[j-1][k1-1]) % mod;
					f[j][k1] = (f[j][k1] + sum[j][k1]) % mod;
				}
				else
					sum[j][k1] = 0;
			}
	printf("%lld",f[m][k]);
	return 0;
}
