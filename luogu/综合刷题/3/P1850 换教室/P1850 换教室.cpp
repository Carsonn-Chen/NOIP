#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 2005

using namespace std;

const int INF = 1<<20;
int c[maxn],d[maxn],dis[305][305];
double k[maxn],f[maxn][maxn][2],ans;

int main(){
	int n,m,v,e;
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&c[i]);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&d[i]);
	for(int i = 1;i <= n;i ++)
		cin >> k[i];
	for(int i = 1;i <= v;i ++)
		for(int j = 1;j < i;j ++)
			dis[i][j] = dis[j][i] = INF;
	for(int i = 1;i <= e;i ++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		dis[a][b] = dis[b][a] = min(dis[a][b],w);
	}
	for(int i = 1;i <= v;i ++)
		for(int j = 1;j <= v;j ++)
			for(int k = 1;k < j;k ++)
				if(dis[j][i]+dis[i][k] < dis[j][k])
                    dis[j][k] = dis[k][j] = dis[j][i]+dis[i][k];
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= m;j ++)
            f[i][j][0] = f[i][j][1] = INF;
    f[1][0][0] = f[1][1][1] = 0;
    for(int i = 2;i <= n;i ++){
    	int Min = min(i,m);
        double w1 = dis[c[i-1]][c[i]],
        w2 = dis[d[i-1]][c[i]]*k[i-1]+dis[c[i-1]][c[i]]*(1-k[i-1]),
        w3 = dis[c[i-1]][d[i]]*k[i]+dis[c[i-1]][c[i]]*(1-k[i]),
        w4 = dis[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])+dis[c[i-1]][d[i]]*(1-k[i-1])*k[i]+dis[d[i-1]][c[i]]*(1-k[i])*k[i-1]+dis[d[i-1]][d[i]]*k[i-1]*k[i];//预先算好加速，这是一个很不好看的递推式
        for(int j = 0;j <= Min;j ++){
            f[i][j][0] = min(f[i-1][j][0]+w1,f[i-1][j][1]+w2);
            if(j)
				f[i][j][1] = min(f[i-1][j-1][0]+w3,f[i-1][j-1][1]+w4);
        }
    }
    ans = INF;
    for(int i = 0;i <= m;i ++)
        ans = min(ans,min(f[n][i][0],f[n][i][1]));
    printf("%.2lf",ans);
	return 0;
}
