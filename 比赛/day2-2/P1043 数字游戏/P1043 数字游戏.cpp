#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int maxx[105][105][15],minn[105][105][15];
int n,m;
int a[105];

int mod(int a) {
	return ((a%10) + 10) % 10;
}

int main() {
	scanf("%d %d",&n,&m);
	for(ri i = 1;i <= n;i ++) {
		scanf("%d",&a[i]);
		a[i+n] = a[i];
	}
	for(ri i = 1;i <= n+n;i ++)
		a[i]+=a[i-1];
	for (ri i = 1;i <= n+n;i ++)
		for (ri j = i;j <= n+n;j ++)
			maxx[i][j][1] = minn[i][j][1] = mod(a[j]-a[i-1]);
	for (ri i = 2;i <= m;i ++)
		for (ri j = 1;j <= n+n;j ++)
			for (ri k = j+i-1;k <= n+n;k ++)
				minn[j][k][i]=INT_MAX;
	for (ri i = 2;i <= m;i ++)
		for (ri j = 1;j <= n+n;j ++) 
			for (ri k = j+i-1;k <= n+n;k ++) {
				for (ri l = j+i-2;l < k;l ++) {
					minn[j][k][i] = min(minn[j][k][i],minn[j][l][i-1] * mod(a[k]-a[l]));
					maxx[j][k][i] = max(maxx[j][k][i],maxx[j][l][i-1] * mod(a[k]-a[l]));
				}
			}
	int Max = 0,Min = INT_MAX;
	for (ri i = 1;i <= n;i ++) {
		Max = max(Max,maxx[i][i+n-1][m]);
		Min = min(Min,minn[i][i+n-1][m]);
	}
	printf("%d\n%d\n",Min,Max);
	return 0;
}
