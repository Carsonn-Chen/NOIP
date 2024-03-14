#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

struct node{
	int next,to;
}edge[1000005];
int head[200005],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m;
int dfn[200005],low[200005];
int now;
int ans[200005];

void tarjan(int u,int fa){
    int child = 0;
    dfn[u] = low[u] = ++now;
    for(ri i= head[u];i; i = edge[i].next){
        int v = edge[i].to;
        if (!dfn[v]){
            tarjan(v,fa);
            low[u] = min(low[u],low[v]);
            if (low[v] >= dfn[u] && u != fa) 
				ans[u] = 1;
            if (u == fa) 
				child++;
        }
        low[u] = min(low[u],dfn[v]);
    }    
    if (u == fa && child >= 2) 
		ans[fa] = 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= m;i ++){
		int a,b;
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}
	for(ri i = 1;i <= n;i ++)
		if(!dfn[i])
			tarjan(i,i);
	int Ans = 0;
	for(ri i = 1;i <= n;i ++)
		if(ans[i])
			Ans ++;
	cout << Ans << endl;
	for(ri i = 1;i <= n;i ++)
		if(ans[i])
			cout << i << " ";
	return 0;
}
