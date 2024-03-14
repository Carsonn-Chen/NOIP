#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

struct E{
	int to,next,w;
}edge[200005];
int head[100005],cnt;

void add(int u,int v,int w){
	edge[++cnt].to  =v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m,s;
int dis[100005];
bool vis[100005];
struct node{
	int d;
	int u;
	node(int u,int d):d(d),u(u){}
	bool operator < (const node & a) const{
		return d > a.d;
	}
};

void dij(){
	fill(dis+1,dis+1+n,INT_MAX);
	priority_queue<node>q;
	q.push(node(s,0));
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().u;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(ri i = head[u];i;i = edge[i].next){
			int v = edge[i].to,w = edge[i].w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push(node(v,dis[v]));
			}
		}
	}
}

int main(){
	n = read(),m = read(),s = read();
	int a,b,c;
	for(ri i = 1;i <= m;i ++){
		a = read(),b = read(),c = read();
		add(a,b,c);
	}
	dij();
	for(ri i = 1;i <= n;i ++)
		cout << dis[i] << " ";
	return 0;
}
