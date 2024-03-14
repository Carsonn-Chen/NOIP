#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct ndoe{
    int next,to,w;
}edge[2000005];
int head[1000005],cnt;
int n,k;
int dis[1000005];
bool vis[1000005];

void add(int u, int v, int w) {
    edge[++cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
    edge[cnt].to = v;
}

bool spfa(int u){
    vis[u] = 1;
    for(ri i = head[u];i;i = edge[i].next)
        if(dis[edge[i].to] < dis[u]+edge[i].w){
            dis[edge[i].to] = dis[u]+edge[i].w;
            if(vis[edge[i].to])
				return 0;
            if(!spfa(edge[i].to))
				return 0;
        }
    vis[u] = 0;
    return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int x,a,b;
	for(ri i = 1;i <= k;i ++){
		cin >> x >> a >> b;
		if(x == 1)
			add(a,b,0),add(b,a,0);
		else if(x == 2)
			add(a,b,1);
		else if(x == 3)
			add(b,a,0);
		else if(x == 4)
			add(b,a,1);
		else if(x == 5)
			add(a,b,0);
	}
	for(ri i = n;i >= 1;i --)
		add(0,i,1),dis[i] = -INT_MAX;
	long long ans = 0;
	if(spfa(0)){
		for(ri i = 1;i <= n;i ++)
			ans += dis[i];
		cout << ans << endl;
	}
	else
		cout << "-1" << endl;
	return 0;
}
