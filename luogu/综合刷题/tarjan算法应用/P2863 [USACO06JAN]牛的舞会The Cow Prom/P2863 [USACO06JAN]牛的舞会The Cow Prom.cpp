#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <stack>
#define ri register int
#define maxn 1000005

using namespace std;

struct node{
	int next,to;
}edge[maxn*2];
int head[maxn],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int dfn[maxn],low[maxn];
int n,m;
bool vis[maxn];
int ans;
int now;
stack<int>s;

void tarjan(int u){
	vis[u] = 1;
	dfn[u] = low[u] = (++now);
	s.push(u);
	for(ri i = head[u];i;i = edge[i].next){
		int v = edge[i].to;
		if(!vis[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]); 
		} 
		else if(vis[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){
		int temp = 0;
		while(s.top() != u){
            temp ++;
			s.pop();
		}
		if(!s.empty())
			s.pop(),temp ++;
        if(temp > 1)
        	ans ++;
	}
}

int main(){
	cin >> n >> m;
	for(ri i = 1;i <= m;i ++){
		int a,b;
		cin >> a >> b;
		add(a,b);
	}
	for(ri i = 1;i <= n;i ++)
		if(!vis[i])
			tarjan(i);
	if(ans)
		cout << ans << endl;
	return 0;
}
