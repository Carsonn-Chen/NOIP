#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

struct node{										//前向星 
	int next,to;
}edge[1000005];
int head[500005],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

struct node2{
	int id;											//编号,方便记录答案 
	int to;
	int next;
}que[1000005];										//记录询问的结构体 
int ans[500005];
int headq[500005],cnt2;

void add_q(int u,int v,int i){
	que[++cnt2].to = v;
	que[cnt2].id = i;
	que[cnt2].next = headq[u];
	headq[u] = cnt2;
}

int n,m,s;
int fa[500005];
bool vis[500005];
int lca[500005];

int find(int x){
	if(x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void tarjan(int u){
	vis[u] = 1;
	for(ri i = head[u];i;i = edge[i].next){
		int v = edge[i].to;
		if(!vis[v]){										//如果没有被访问过,就tagjan这个点 
			tarjan(v);
			fa[v] = find(u);
		}
	}
	for(ri i = headq[u];i;i = que[i].next){
		int v = que[i].to;
		if(vis[v])											//找答案时,已经访问过的节点就可以记录lca了 
			lca[que[i].id] = find(v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	int a,b;
	for(ri i = 1;i <= n-1;i ++){
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b;
		add_q(a,b,i);
		add_q(b,a,i);
	}
	for(ri i = 1;i <= n;i ++)
		fa[i] = i;
	tarjan(s);
	for(ri i = 1;i <= m;i ++)
		cout << lca[i] << endl;
	return 0;
}
