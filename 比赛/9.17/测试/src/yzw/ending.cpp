#include<cstdio>
using namespace std;
const int maxn=10;
bool yes;
int m,n,hp;
int A[maxn];
int B[maxn];
void DFS(int cur,int now,int kill)
{
	if(yes||kill<hp||cur>=n) return;
	if(!now)
	{
		yes=kill>=hp;
		return;
	}
	for(int i=cur+1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(B[j]>0)
			{
				B[j]-=A[i];
				DFS(i,now-(B[j]<=0),kill-A[i]);
				B[j]+=A[i];
			}
		}
	}
}
int main()
{
	freopen("ending.in","r",stdin);
	freopen("ending.out","w",stdout);
	int sum=0;
	scanf("%d%d%d",&m,&n,&hp);
	for(int i=1;i<=m;i++) scanf("%d",&B[i]);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),sum+=A[i];
	DFS(yes=0,m,sum);
	if(yes) printf("Yes\n");
	else printf("No\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
