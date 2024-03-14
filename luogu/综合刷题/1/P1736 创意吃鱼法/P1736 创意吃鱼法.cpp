#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n,m,ans;
int a[2509][2509],f[2509][2509],s1[2509][2509],s2[2509][2509];//s1为横向，s2为纵向 

int main()
{
    cin >> n >> m;
    //第一遍左上——右下 
    for(int i = 1;i <= n;i ++)
    for(int j = 1;j <= m;j ++){
        scanf("%d",&a[i][j]);
        if(!a[i][j]){
            s1[i][j] = s1[i][j-1]+1;
            s2[i][j] = s2[i-1][j]+1;
        }
        if(a[i][j])
        f[i][j] = min(f[i-1][j-1],min(s1[i][j-1],s2[i-1][j]))+1;
        ans = max(ans,f[i][j]);
    }
    memset(f,0,sizeof(f)); 
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2)); 
    for(int i = 1;i <= n;i ++)
    for(int j = m;j >= 1;j --){
        if(!a[i][j]){
        	s1[i][j] = s1[i][j+1]+1;
            s2[i][j] = s2[i-1][j]+1;
        }
        if(a[i][j])
        f[i][j] = min(f[i-1][j+1],min(s1[i][j+1],s2[i-1][j]))+1;
        ans = max(ans,f[i][j]);
    }
    cout << ans << endl;
    return 0;
}
