#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define INF 10000000000000LL
using namespace std;
typedef long long LL;
const int maxn = 60005;
int headd[2*maxn];
struct deff
{
	int to,w,next;
}edge[2*maxn];
int place;
void add(int u,int v,int w)
{
	edge[++place].to=v;
	edge[place].w=w;
	edge[place].next=headd[u];
	headd[u]=place;
}
struct def
{
	int x,sum;
	def(int x,int sum):x(x),sum(sum) {}
};
int n,m;
LL d[maxn];
bool vis[maxn];
void SPFA(int x)
{
	for(int i=1;i<=n;i++) d[i]=INF;
	for(int i=1;i<=n;i++) vis[i]=0;
	d[x]=0;
	vis[x]=1;
	queue<int> q;
	q.push(x);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=headd[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			int w=edge[i].w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int  main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int w;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		int u=i;
		int v=i+1;
		if(v>n) v=1;
		add(u,v,w);
		add(v,u,w);
	}
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		if(x!=y)
		{
			add(x,y,w);
			add(y,x,w);
		}
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		scanf("%d%d",&x,&y);
		SPFA(x);
		cout<<d[y]<<endl;
	}
	return 0;
}
