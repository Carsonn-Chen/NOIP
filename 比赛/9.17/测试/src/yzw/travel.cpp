#include<cstdio>
#define INF 100000000000000000LL
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
const int maxn=505;
int n,m;
long long d[maxn][maxn];
inline void Init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=INF;
		}
		//d[i][i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k=i%n+1;
		scanf("%lld",&d[i][k]);
		d[k][i]=d[i][k];
	}
	while(m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=MIN(d[u][v],w);
		//d[v][u] = d[u][v];//
	}
}
inline void Floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++) //if (d[i][k] < INF)//
		{
			for(int j=1;j<=n;j++) //if (d[k][j] < INF)
			{
				d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
			}
		}
		
	}
}
inline void Print()
{
	scanf("%d",&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",d[x][y]);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Init();
	Floyd();
	Print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
