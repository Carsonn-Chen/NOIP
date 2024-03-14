#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int
#define MAXN 30005

using namespace std;

struct ndoe{
    int next, to, w;
}edge[100005];
int head[MAXN], cnt;
int n,m;
int dis[MAXN];
bool vis[MAXN];

void add(int u, int v, int w) {
    edge[++cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
    edge[cnt].to = v;
}

void spfa(int S){
    queue<int> Q;
    Q.push(S);
    for(ri i = 0;i <= n+1;i ++)
		dis[i] = INT_MAX;
    dis[S] = 0;
    vis[S] = 1;
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        vis[k] = 0;
        for(ri i = head[k];i;i = edge[i].next) {
            int to = edge[i].to;
            if(dis[to] > dis[k] + edge[i].w) {
                dis[to] = dis[k] + edge[i].w;
                if(!vis[to]) {
                    Q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int S = n+1;
	for(ri i = 0;i <= n;i ++) 
		add(S, i, 0);
	int x,y,t;
    for(ri i = 1;i <= m;i ++) {
        cin >> x >> y >> t;
        add(y, x-1, -t);
    }
    for(ri i = 1;i <= n;i ++) {
        add(i-1,i,1);
        add(i,i-1,0);
    }
    spfa(S);
    cout << dis[n] - *min_element(dis,dis+n) << endl;
	return 0;
}
