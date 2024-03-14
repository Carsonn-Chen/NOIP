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
	int next,to,w;
}edge[100005];
int head[1505],cnt;

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
	edge[cnt].w = w;
}

int n,m;
int in[1505];
int dis[1505];
bool vis[1505];
queue<int>q;

int main(){
	//freopen("in.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a,b,c;
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b >> c;
		add(a,b,c);
		in[b] ++;
	}
	vis[1] = 1;
	for(int i = 1;i <= n;i ++)
		if(in[i] == 0)
			q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(ri i = head[u];i;i = edge[i].next){
			int v = edge[i].to;
			in[v] --;
			if(vis[u])
				if(dis[v] < dis[u]+edge[i].w){
					dis[v] = dis[u]+edge[i].w;
					vis[v] = 1;
				}
			if(in[v] == 0)
				q.push(v);
		}
	}
	if(dis[n] != 0)
		cout << dis[n] << endl;
	else
		cout << "-1" << endl;
	return 0;
}
