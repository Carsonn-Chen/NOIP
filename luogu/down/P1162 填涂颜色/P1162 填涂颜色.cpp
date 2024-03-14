#include<iostream>
#include<cstdio>
using namespace std;
int a[100][100],b[100][100]={0};
int n,x,y;

void dfs(int x,int y)
{
    if(x>n||x<1||y>n||y<1||a[x][y]!=0)//判断是否越界 
        return;
    a[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);//四个方向 
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1) b[i][j]=-1;//b用来存原来的位置 
        }
    int flag=0;
    for(int i=1;i<=n;i++)
    {
    if(a[i][1]!=1) dfs(i,1);
    if(a[i][n]!=1) dfs(i,n);//搜第i行的第一列和第n列 
    }
    for(int i=1;i<=n;i++)
    {
    if(a[1][i]!=1) dfs(1,i);
    if(a[n][i]!=1) dfs(n,i);//搜第i列的第一行和第n行 
    } 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[i][j]==-1) printf("1 ");
            else
            if(a[i][j]==0) printf("2 ");
            else printf("0 ");
        }
        printf("\n");
    }//输出，如果这个看不懂的话建议刷P1000(大牛分站的！); 
    return 0;
}
//代码如下： 
