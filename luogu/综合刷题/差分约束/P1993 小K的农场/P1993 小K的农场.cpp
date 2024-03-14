#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct ndoe{
    int next, to, w;
}edge[100005];
int head[10005], cnt;
int n,m;
bool vis[10005];
int dis[10005];

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
    cin >> n >> m;
    int f,a,b,c;
    while(m--){
        cin >> f >> a >> b;
        if(f == 1)
			cin >> c,add(b,a,c);
        else if(f == 2)
			cin >> c,add(a,b,-c);
        else if(f == 3)
			add(a,b,0),add(b,a,0);
    }
    for(ri i = 1;i <= n;i ++)
		add(0,i,0),dis[i] = -INT_MAX;
    if(!spfa(0))
		cout << "No" << endl;
    else
		cout << "Yes" << endl;
    return 0;
}
