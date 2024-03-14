#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define INF 1e9
using namespace std;
int n,m,min_cnt=INF,min_i;
int road[2000001*2],nxt[2000001*2],head[100001],rn;
int cnt[100001];
bool fl[100001],fl2[2001];
int to_i[100001],tn;
int mp[2001][2001];
int ans,ans_n[2001];
void build(int x,int y){road[++rn]=y;nxt[rn]=head[x];head[x]=rn;}
void dfs(int now)
{
    if(now==to_i[min_i])ans_n[ans]+=n-tn+1;else ans_n[ans]++;
    fl2[now]=1;
    for(int i=1;i<=tn;i++)if(i!=now && (!fl2[i]) && mp[now][i])dfs(i);
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
      scanf("%d%d",&a,&b);
      build(a,b);build(b,a);
      cnt[a]++;cnt[b]++;
    }
    for(int i=1;i<=n;i++){if(cnt[i]<min_cnt)min_cnt=cnt[i],min_i=i;}
    fl[min_i]=1;for(int i=head[min_i];i;i=nxt[i])fl[road[i]]=1;
    for(int i=1;i<=n;i++)if(fl[i])to_i[i]=++tn;
    for(int i=1;i<=n;i++)
    {
      if(fl[i]){for(int j=head[i];j;j=nxt[j]){if(fl[road[j]])mp[to_i[i]][to_i[road[j]]]=1;else mp[to_i[i]][to_i[min_i]]=1;}}
      else{for(int j=head[i];j;j=nxt[j])if(fl[road[j]])mp[to_i[min_i]][to_i[road[j]]]++;}
    }
    for(int i=1;i<=tn;i++)
    {
      if(i!=to_i[min_i])
      {
        if(mp[to_i[min_i]][i]==n-tn+1)mp[to_i[min_i]][i]=mp[i][to_i[min_i]]=1;
        else mp[to_i[min_i]][i]=mp[i][to_i[min_i]]=0;
      }
    }
    for(int i=1;i<=tn;i++)for(int j=1;j<=tn;j++)if(i!=j)mp[i][j]^=1;
    for(int i=1;i<=tn;i++)if(!fl2[i]){ans++;dfs(i);}
    printf("%d\n",ans);
    sort(ans_n+1,ans_n+1+ans);
    for(int i=1;i<=ans;i++)printf("%d ",ans_n[i]);
    return 0;
}
