#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int n,l,r;
int ai[55];
int xo[55];
int f[55][55][1050];

int main(){
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	scanf("%d%d%d",&n,&l,&r);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&ai[i]);
		xo[i] = xo[i-1] ^ ai[i];
	}
	for(int i = 0;i <= 1024;i ++)
		f[0][0][i] = 1;
	for(int i = 0;i < n;i ++)	
		for(int j = 0;j < r;j ++)
			for(int k = 0;k <= 1024;k ++){
				if (!f[i][j][k]) continue;
				for (int p = i + 1; p <= n; p ++)
					f[p][j + 1][(xo[p] ^ xo[i]) & k] = 1;
			}
	int mx = 0;
	for(int i = l;i <= r;i ++)
		for(int j = 1024;j >= mx;j --)
			if(f[n][i][j]){ 
				mx = j;
				break;
			}
	printf("%d\n",mx);
	return 0;
}
