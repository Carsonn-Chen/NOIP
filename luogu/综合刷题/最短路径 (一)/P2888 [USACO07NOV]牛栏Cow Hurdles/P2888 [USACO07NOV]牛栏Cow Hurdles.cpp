#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int dis[305][305];

int main(){
	ios::sync_with_stdio(false);
	int n,m,t;
	cin >> n >> m >> t;
	int s,e,h;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			dis[i][j] = INT_MAX;
	for(ri i = 1;i <= m;i ++){
		cin >> s >> e >> h;
		dis[s][e] = h;
	}
	for(ri k = 1;k <= n;k ++)
		for(ri i = 1;i <= n;i ++)
			if(dis[i][k] != -1)
				for(ri j = 1;j <= n;j ++)
					if(dis[k][j] != -1)
						dis[i][j] = min(dis[i][j],max(dis[i][k],dis[k][j]));
	while(t --){
		cin >> s >> e;
		if(dis[s][e] != INT_MAX)
			cout << dis[s][e] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
