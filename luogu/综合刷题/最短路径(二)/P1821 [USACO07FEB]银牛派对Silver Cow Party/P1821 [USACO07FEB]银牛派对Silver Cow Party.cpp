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
}edge1[100005],edge2[100005];
int head1[1005],cnt,head2[1005];

void add1(int u,int v,int w){
	edge1[++cnt].to = v;
	edge1[cnt].next = head1[u];
	edge1[cnt].w = w;
	head1[u] = cnt;
}

void add2(int u,int v,int w){
	edge2[cnt].to = v;
	edge2[cnt].next = head2[u];
	edge2[cnt].w = w;
	head2[u] = cnt;
}

int n,m,x;
int dis1[1005],dis2[1005];
bool vis[1005];
queue<int>q;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	for(ri i = 1;i <= m;i ++){
		int a,b,c;
		cin >> a >> b >> c;
		add1(a,b,c);
		add2(b,a,c);
	}
	
	for(ri i = 1;i <= n;i ++)
		dis1[i] = INT_MAX;
	q.push(x);
	vis[x] = 1;
	dis1[x] = 0;
	int ans = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(ri i = head1[u];i;i = edge1[i].next){
			int v = edge1[i].to,w = edge1[i].w;
			if(dis1[v] > dis1[u] + w){
				dis1[v] = dis1[u] + w;
				if(!vis[v]){
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
	
	memset(vis,0,sizeof(vis));
	for(ri i = 1;i <= n;i ++)
		dis2[i] = INT_MAX;
	q.push(x);
	vis[x] = 1;
	dis2[x] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(ri i = head2[u];i;i = edge2[i].next){
			int v = edge2[i].to,w = edge2[i].w;
			if(dis2[v] > dis2[u] + w){
				dis2[v] = dis2[u] + w;
				if(!vis[v]){
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
	for(ri i = 1;i <= n;i ++)
		if(i != x)
			ans = max(ans,dis1[i]+dis2[i]);
	cout << ans << endl;
	return 0;
}
