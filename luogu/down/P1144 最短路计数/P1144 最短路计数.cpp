#include <bits/stdc++.h>

using namespace std;

vector<int>v[1000005];
int n,m;
int cnt[1000005];
int vis[1000005];
int dis[1000005];

bool check(int x,int y){
	for(int i = 0;i < v[x].size();i ++)
		if(v[x][i] == y)
			return false;
	return true;
}

void spfa(){
	queue<int>q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i ++){
			int u = v[x][i];
			if(dis[x]+1 < dis[u]){
				dis[u] = dis[x]+1;
				cnt[u] = cnt[x];
				if(!vis[u]){
					q.push(u);
					vis[u] = 1;
				}
			}else if(dis[x]+1 == dis[u])
				cnt[u] = (cnt[x] + cnt[u]) % 100003;
		}
		vis[x] = 0;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i = 1;i <= m;i ++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i  = 2;i <= n;i ++)
		dis[i] = 999999999;
	dis[1] = 0;
	cnt[1] = 1;
	spfa();
	for(int i = 1;i <= n;i ++)
		printf("%d\n",cnt[i]);
	return 0;
}
