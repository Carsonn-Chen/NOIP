#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ri register int

using namespace std;

int f[45][45][45][45];
int v[355];
int num[5];

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		cin >> v[i];
	int x;
	for(ri i = 1;i <= m;i ++){
		cin >> x;
		num[x] ++;
	}
	f[0][0][0][0] = v[1];
	for(ri i = 0;i <= num[1];i ++)
		for(ri j = 0;j <= num[2];j ++)
			for(ri k = 0;k <= num[3];k ++)
				for(ri l = 0;l <= num[4];l ++){
					int dis = 1+i+2*j+3*k+4*l;
					if(dis <= n){
						if(i >= 1)
							f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k][l] + v[dis]);
						if(j >= 1)
							f[i][j][k][l] = max(f[i][j][k][l],f[i][j-1][k][l] + v[dis]);
						if(k >= 1)
							f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k-1][l] + v[dis]);
						if(l >= 1)
							f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k][l-1] + v[dis]);
					}
				}
	printf("%d\n",f[num[1]][num[2]][num[3]][num[4]]);
	return 0;
}
