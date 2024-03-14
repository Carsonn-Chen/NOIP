#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int next,to,w;
}edge[260000];
int head[505],cnt;

void add(int u,int v,int w){
	edge[++ cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int f,n,m,w;
bool flag;
int dis[505];
bool vis[505];

void Dfs_spfa(int u){
	if(flag)
		return;
	vis[u] = 1;
	for(ri i = head[u];i;i = edge[i].next){
		if(flag)
			return;
		int v = edge[i].to;
		if(dis[v] > dis[u] + edge[i].w){
			dis[v] = dis[u] + edge[i].w;
			if(vis[v]){
				flag = 1;
				return;
			}else
				Dfs_spfa(v);
		}
	}
	vis[u] = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> f;
	while(f --){
		memset(head,0,sizeof(head));
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		flag = 0;
		cin >> n >> m >> w;
		int s,e,t;
		for(ri i = 1;i <= m;i ++){
			cin >> s >> e >> t;
			add(s,e,t);
			add(e,s,t);
		}
		for(ri i = 1;i <= w;i ++){
			cin >> s >> e >> t;
			add(s,e,-t);
		}
		for(ri i = 1;i <= n;i ++){
			Dfs_spfa(i);
			if(flag)
				break;
		}
		if(flag)	
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
