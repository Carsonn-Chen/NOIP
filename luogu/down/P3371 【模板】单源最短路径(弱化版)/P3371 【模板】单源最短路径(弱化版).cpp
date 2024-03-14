#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

struct node{
	int to,next,w;
}edge[500005];
int head[10005],cnt;

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m,s;
int dis[10005];
bool vis[10005];

void spfa(){
	queue<int>q;
	fill(dis+1,dis+1+n,INT_MAX);
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(ri i = head[u];i;i = edge[i].next){
			int v = edge[i].to,w = edge[i].w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		vis[u] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	int a,b,c;
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b >> c;
		add(a,b,c);
	}
	spfa();
	for(ri i = 1;i <= n;i ++)
		cout << dis[i] << " ";
	return 0;
}
