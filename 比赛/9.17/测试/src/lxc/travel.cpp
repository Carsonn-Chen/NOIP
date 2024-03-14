#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;

const LL maxn = 1e14+5;

struct node{
	int to;
	LL time;
	node(int to,LL time):to(to),time(time){}
};

int n,m;
vector<node>v[52505];
bool vis[52505];
LL dis[52505];

void spfa(int a){
	queue<int>q;
	q.push(a);
	vis[a] = 1;
	dis[a] = 0;
	while(!q.empty()){
		int b = q.front();q.pop();
		for(int i = 0;i < v[b].size();i ++){
			int u = v[b][i].to;
			LL cos = v[b][i].time;
			if(dis[b] + cos < dis[u]){
				dis[u] = dis[b] + cos;
				if(!vis[u]){
					q.push(u);
					vis[u] = 1;
				}
			}
		}
		vis[b] = 0;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	LL a,b,c;
	for(int i = 1;i < n;i ++){
		scanf("%lld",&a);
		v[i].push_back(node(i+1,a));
		v[i+1].push_back(node(i,a));
	}
	scanf("%lld",&a);
	v[n].push_back(node(1,a));
	v[1].push_back(node(n,a));
	for(int i = 1;i <= m;i ++){
		scanf("%lld%lld%lld",&a,&b,&c);
		v[a].push_back(node(b,c));
		v[b].push_back(node(a,c));
	}
	int Q;
	scanf("%d",&Q);
	int x,y;
	while(Q--){
		scanf("%d%d",&x,&y);
		for(int i = 1;i <= n;i ++){
			dis[i] = maxn;
			vis[i] = 0;
		}
		spfa(x);
		printf("%I64d\n",dis[y]);
	}
	return 0;
}
