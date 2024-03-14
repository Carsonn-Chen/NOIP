#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int M[105][105];
int n,k,m,s,t;
int cul[105];
int hate[105][105];
int dis[105];
bool via[105];

void spfa(){
	queue<int>q;
	q.push(t);
	via[t] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(ri i = 1;i <= n;i ++){
			if(M[x][i] == 0)
				continue;
			if(dis[x] + M[x][i] < dis[i]){
				dis[i] = dis[x] + M[x][i];
				if(!via[i]){
					q.push(i);
					via[i] = 1;
				} 
			}
		}
		via[x] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> m >> s >> t;	//依次代表国家个数，文化种数，道路的条数，以及起点和终点的编号；
	for(ri i = 1;i <= n;i ++)
		cin >> cul[i];
	for(ri i = 1;i <= k;i ++)
		for(ri j = 1;j <= k;j ++)
				cin >> hate[i][j];
	for(ri i = 1;i <= k;i ++)
		hate[i][i] = 1;
	for(ri i = 1;i <= m;i ++){
		int u,v,d;
		cin >> u >> v >> d;
		if(!hate[cul[u]][cul[v]])
			M[u][v] = d;
		if(!hate[cul[v]][cul[u]])
			M[v][u] = d;
	}
	for(ri i = 1;i <= n;i ++)
			dis[i] = 2147483647;
	dis[t] = 0;
	spfa();
	if(dis[s] == 2147483647 || cul[s] == cul[t])
		printf("-1\n");
	else
		printf("%d\n",dis[s]);
	return 0;
}
