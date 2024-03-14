#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2147483647;

using namespace std;

vector<int>road[10005];
bool pd[10005],via[10005];
int n,m,s,t,dis[10005];

void search(int x){
	if(pd[x])
		for(int i = 0;i < (int)road[x].size();i ++){
			if(!pd[road[x][i]]){
				pd[road[x][i]] = 1;
				search(road[x][i]);
			}
		}
}

void solve(int x){
	for(int i = 0;i < (int)road[x].size();i ++){
		if(pd[road[x][i]] && road[x][i] != s){
			pd[road[x][i]] = 0;
			via[road[x][i]] = 1;
		}
	}
}

void spfa(){
	queue<int>q;
	q.push(t);
	via[t] = 1;
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i < (int)road[x].size();i ++){
			int x1 = road[x][i];
			if(pd[x1]){
				if(dis[x1] > dis[x]+1){
					dis[x1] = dis[x]+1;
					if(!via[x1]){
						q.push(x1);
						via[x1] = 1;
					}
				}
			}
		}
		via[x] = 0;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i ++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x == y)
			continue;
		road[y].push_back(x);
	}
	scanf("%d%d",&s,&t);
	for(int i = 1;i <= n;i ++)
		dis[i] = INF;
	pd[t] = 1;
	dis[t] = 0;
	search(t);
	for(int i = 1;i <= n;i ++)
		if(!pd[i] && !via[i])
			solve(i);
	memset(via,0,sizeof(via));
	spfa();
	printf("%d\n",(pd[s]==0?-1:dis[s]));
	return 0;
}
