#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
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

void write(int x){
	if(x > 9)
		write(x/10);
	putchar(x%10 + '0');
}

struct node{
	int next,to;
}edge[1000005];
int head[500005],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m,s;
int depth[500005],fa[500005][25],lg[500005];

void dfs(int now,int fath){
	depth[now] = depth[fath] + 1;
	fa[now][0] = fath;
	for(ri i = 1;(1 << i) <= depth[now];i ++)
		fa[now][i] = fa[fa[now][i-1]][i-1];
	for(ri i = head[now];i;i = edge[i].next)
		if(edge[i].to != fath)
			dfs(edge[i].to,now);
}

int lca(int u,int v){
	if(depth[u] < depth[v])
		swap(u,v);
	while(depth[u] > depth[v])
		u = fa[u][lg[depth[u] - depth[v]]-1];
	if(u == v)
		return u;
	for(ri i = lg[depth[u]] - 1;i >= 0;i --)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}

int main(){
	freopen("in.in","r",stdin);
	n = read(),m = read(),s = read();
	int x,y;
	for(ri i = 1;i <= n-1;i ++){
		x = read(),y = read();
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(ri i = 1;i <= n;i ++)
		lg[i] = lg[i-1] + (1<<lg[i-1] == i);
	for(ri i = 1;i <= m;i ++){
		x = read(),y = read();
		write(lca(x,y));
		putchar('\n');
	}
	return 0;
}
