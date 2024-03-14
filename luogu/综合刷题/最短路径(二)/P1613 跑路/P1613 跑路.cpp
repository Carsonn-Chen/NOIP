#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int dis[55][55];
int n,m;
bool g[55][55][65];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			dis[i][j] = 1e9;
	for(ri i = 1;i <= m;i ++){
		int a,b;
		cin >> a >> b;
		dis[a][b] = 1;
		g[a][b][0] = 1;
	}
	for(ri k = 1;k <= 64;k ++) 
    	for(ri i = 1;i <= n;i ++)
    		for(ri t = 1;t <= n;t ++)
    			for(ri j = 1;j <= n;j ++)
    				if(g[i][t][k-1] && g[t][j][k-1]){				//2^(k-1) + 2^(k-1) == 2^k
    					g[i][j][k] = 1;								//即枚举中间点判断能不能到达 
        				dis[i][j] = 1;
        			}
	for(ri k = 1;k <= n;k ++)
		for(ri i = 1;i <= n;i ++)
			if(dis[i][k] != 1e9)
				for(ri j = 1;j <= n;j ++)
					if(dis[k][j] != 1e9)
						if(dis[i][j] > dis[i][k] + dis[k][j])
							dis[i][j] = dis[i][k] + dis[k][j];
	cout << dis[1][n] << endl;
	return 0;
}
