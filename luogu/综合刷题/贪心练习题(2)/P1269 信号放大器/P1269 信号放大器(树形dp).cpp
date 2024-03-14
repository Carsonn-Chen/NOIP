#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define ri register int

using namespace std;

int n,s;
struct node{ 
	int to,w,next;
}edge[40005];
int head[20005],cnt;

void Add(int u,int v,int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int g[20005];
int f[20005];
bool vis[20005];

void Dfs(int u) {
    vis[u] = 1;
    g[u] = -1;
	f[u] = 0;
	int fu;
    for(ri i = head[u];i != 0;i = edge[i].next) {
        int v = edge[i].to,w = edge[i].w;
        if(vis[v]){ 
			fu = i;
			continue; 
		}
        if(w >=s ){
			printf("No solution.\n"); 
			exit(0);
		}
        Dfs(v);
		g[u] = max(g[u],g[v]+w);
		f[u] += f[v];
    }
    if (g[u] == -1){
		g[u] = 1;
		f[u] = 0;
	}
    else if(u != 1 && s-edge[fu].w < g[u]){
		g[u]=1;
		f[u]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin >> n;
    for(ri u = 1;u <= n;u ++) {
        int k;
		cin >> k;
        while(k --) {
            int v,w;
            cin >> v >> w;
            Add(u,v,w);
        }
    }
    cin >> s;
	Dfs(1);
	cout << f[1] << endl;
    return 0;
}
