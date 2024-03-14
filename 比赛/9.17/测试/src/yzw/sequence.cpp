#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int maxn=152505;
const int mod=998244353;
int a[maxn];
int f[20][maxn];
int delta[maxn];
inline void ST(int &n)
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[0][i]=a[i];
	int t=1;
    for(int j=0;(t<<1)<=n;j++,t<<=1)
	{
        for(int i=1;i<=n;i++)
            f[j+1][i]=MAX(f[j][i],f[j][i+t]);
    }
    t=0;
    for(int i=0;i<=n;i++)
	{
    	if(i>=(1<<(t+1))) t++;
    	delta[i]=t;
    }
}
inline int Search(int n)
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int k=delta[j-i];
			ans+=MAX(f[k][i],f[k][j-(1<<k)+1]);
			if(ans>=mod) ans%=mod;
		}
	}
	return (int)ans;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	ST(n);
	printf("%d\n",Search(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
