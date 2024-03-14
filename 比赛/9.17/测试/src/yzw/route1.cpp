#include<cstdio>
#include<cstring>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
const int maxn=105;
const int INF=1e6;
int n;
int u[maxn];
int v[maxn];
int d[maxn][maxn];
void Floyd(int a)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++) d[i][i%n+1]=d[i%n+1][i]=1,d[i][i]=0;
	d[a][a%n+1]=d[a%n+1][a]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main()
{
	freopen("route1.in","r",stdin);
	freopen("routel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	if(n>maxn) printf("1\n");
	else
	{
		int ans=INF;
		for(int i=1;i<=n;i++)
		{
			int temp=0;
			Floyd(i);
			for(int i=1;i<=m;i++) temp=MAX(temp,d[u[i]][v[i]]);
			ans=MIN(temp,ans);	
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
