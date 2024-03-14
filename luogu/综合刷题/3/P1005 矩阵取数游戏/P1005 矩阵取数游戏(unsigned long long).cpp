#include <bits/stdc++.h>
#define ulld unsigned long long

using namespace std;

const int MAXN=81;

int n, m;
ulld game[MAXN][MAXN];

ulld f[MAXN][MAXN];
ulld solve(ulld a[])
{
    memset(f,0,sizeof(f));
    for(int len=0;len<=m;++len)
        for(int i=1;i+len<=m;++i)
            f[i][i+len]=max(2*f[i+1][i+len]+2*a[i],2*f[i][i+len-1]+2*a[i+len]);
    return f[1][m];
}

ulld ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> game[i][j];
    for(int i=1;i<=n;i++)
        ans+=solve(game[i]);
    cout << ans;
    return 0;
}
