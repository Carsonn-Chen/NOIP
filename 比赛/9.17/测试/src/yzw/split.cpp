#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=1505;
int n,l,r,ans;
int a[maxn];
int f[maxn][maxn];
inline void Init()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=(f[i][j-1]^a[j]);
		}
	}
}
void DFS(int len,int temp,int cur)
{
	if(!len)
	{
		ans=MAX(ans,temp);
		return;
	}
	for(int i=cur+1;i<=n;i++)
	{
		DFS(len-1,temp&f[cur+1][i],i);
	}
}
int main()
{
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	Init();
	ans=0;
	for(int k=l;k<=r;k++) DFS(k,2147483647,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
