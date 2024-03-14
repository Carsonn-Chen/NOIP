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
	int next,to;
	double w;
}edge[1000005];
int head[2005],cnt;

void add(int u,int v,double w){
	edge[++cnt].to = v;
	edge[cnt].w = 1 - w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m,a,b;
double dis[2005];
bool vis[2005];

void spfa()
{
    queue<int>q;
    q.push(a);
    dis[a] = 1; 
    vis[a] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(ri i = head[u];i;i = edge[i].next){
            int v = edge[i].to;
            if(dis[v] < dis[u]*edge[i].w){
                dis[v] = dis[u]*edge[i].w;
                if(!vis[v]){
                	q.push(v);
                    vis[v] = 1;
                }
            }
        }
        vis[u] = 0;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    fill(dis+1,dis+n+1,0);
    for(ri i = 1;i <= m;i ++){
    	int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,(double)z/100);
        add(y,x,(double)z/100);
    }
    scanf("%d%d",&a,&b);
    spfa();
    printf("%.8lf",100/dis[b]);
    return 0;
}
