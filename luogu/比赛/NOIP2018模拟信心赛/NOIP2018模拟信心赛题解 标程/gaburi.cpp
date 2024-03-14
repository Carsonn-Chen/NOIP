#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int n,ans,tot;
char ch[2000002];
int f[1000001],g[1000001];
struct node
{
    int s,v;
}item[1000001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      scanf("%s",ch);
      int t=0,l=strlen(ch),cnt=0;
      for(int j=0;j<l;j++){if(ch[j]=='s')t++,cnt++;if(ch[j]=='c')t--,cnt++;}
      item[i]=(node){t,cnt};tot+=cnt;
    }
    for(int i=1;i<=n;i++)
    {
      if(item[i].s>0)
      {
        for(int j=tot;j>item[i].s;j--)if(f[j-item[i].s])f[j]=max(f[j],f[j-item[i].s]+item[i].v);
        f[item[i].s]=max(f[item[i].s],item[i].v);
      }
      if(item[i].s==0)ans+=item[i].v;
      if(item[i].s<0)
      {
        for(int j=tot;j>(-item[i].s);j--)if(g[j+item[i].s])g[j]=max(g[j],g[j+item[i].s]+item[i].v);
        g[(-item[i].s)]=max(g[(-item[i].s)],item[i].v);
      }
    }
    int tans=0;
    for(int i=1;i<=tot;i++)if(f[i] && g[i])tans=max(tans,f[i]+g[i]);
    printf("%d",(ans+tans)/2);
}
