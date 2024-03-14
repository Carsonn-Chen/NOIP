#include <bits/stdc++.h>

using namespace std;

int price[100005];
struct node{
	int to;
	int w;
	node(int to,int w):to(to),w(w){}
};
vector<node>way[100005];
int vis[100005];
int dis[100005];

void spfa(){
	queue<int>q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int a = q.front();q.pop();
		for(int i = 0;i < way[a].size();i ++){
			int b = way[a][i].to,c = way[a][i].w;
			if(c > 0){
				if(dis[a] + c > dis[b]){
					dis[b] = dis[a] + c;
					if(!vis[b]){
						q.push(b);
						vis[b] = 1;
					}
				}
			}
			else{
				if(!vis[b]){
					q.push(b);
					vis[b] = 1;
				}
			}
		}
		vis[a] = 0;
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&price[i]);
	int x,y,z,p;
	for(int i = 1;i <= m;i ++){
		scanf("%d%d%d",&x,&y,&z);
		p = price[y] - price[x];
		way[x].push_back(node(y,p));
		if(z == 2)
			way[y].push_back(node(x,-p));
	}
	spfa();
	printf("%d",*max_element(dis+1,dis+1+n));
	return 0;
}
