#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1505;
int a[maxn];
LL d[maxn][maxn];
int p[maxn];
LL ans=-1;
int num;
int n,r,l;
void DFS(int place)
{
	if(place==num)
	{
		int next=1;
		LL sum=-1;
		for(int i=0;i<place;i++)
		{
			sum=sum  & d[next][p[i]];
			next=p[i]+1;
		}
		sum=sum & d[next][n];
		ans=max(ans,sum);
	}
	else
	{
		for(int i=place;i<n;i++)
		{
			p[place]=i;
			DFS(place+1);
		}
	}
}
int main()
{
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	scanf("%d%d%d",&n,&r,&l);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),d[i][i]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			d[i][j]=d[i][j-1]^a[j];
		}
	}
	for(int i=r;i<=l;i++)
	{
		num=i-1;
		DFS(0);
	}
	cout<<ans<<endl;
	return 0;	
} 
