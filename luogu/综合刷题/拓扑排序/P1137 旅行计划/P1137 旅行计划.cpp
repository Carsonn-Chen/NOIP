#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <queue>
#define ri register int

using namespace std;

struct node{
	int next,to;
}edge[200005];
int head[100005],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m;
int ans[100005],in[100005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1;i <= m;i ++){
		int x,y;
		cin >> x >> y;
		add(x,y);
		in[y] ++;
	}
	queue<int>q;
	for(int i = 1;i <= n;i ++)
		if(in[i] == 0)
			q.push(i),ans[i] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(ri i = head[u];i;i = edge[i].next){
			int v = edge[i].to;
			in[v] --;
			ans[v] = max(ans[v],ans[u]+1);
			if(in[v] == 0)
				q.push(v);
		}
	}
	for(ri i = 1;i <= n;i ++)
		printf("%d\n",ans[i]);
	return 0;
}
