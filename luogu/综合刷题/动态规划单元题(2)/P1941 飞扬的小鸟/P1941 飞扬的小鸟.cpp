#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ri register int

using namespace std;

int n,m,p;
int x[10005],y[10005];
int down[10005],up[10005];
int f[10005][2005];
bool have[10005];

int main() {
	ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(ri i = 1;i <= n;i ++)
		cin >> x[i] >> y[i];
    for(ri i = 1;i <= n;i ++){
        down[i] = 1;
        up[i] = m;
    }
    int a,b,c;
    for(ri i = 1;i <= p;i ++) {
        cin >> a >> b >> c;
        have[a] = 1;
        down[a] = b+1;
        up[a] = c-1;
    }
    memset(f,0x3f,sizeof(f));
    for(ri i = 1;i <= m;i ++) 
		f[0][i] = 0;
    for(ri i = 1;i <= n;i ++) {
        for(ri j = x[i]+1;j <= m+x[i];j ++)
            f[i][j] = min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
        for(ri j = m+1;j <= m+x[i];j ++)
            f[i][m] = min(f[i][m],f[i][j]);
        for(ri j = 1;j <= m-y[i];j ++)
            f[i][j] = min(f[i][j],f[i-1][j+y[i]]);
        for(ri j = 1;j < down[i];j ++)
            f[i][j] = f[0][0];
        for(ri j = up[i]+1;j <= m;j ++)
            f[i][j] = f[0][0];
    }
    int ans = f[0][0];
    for(ri j = 1;j <= m;j ++) {
        ans = min(ans,f[n][j]);
    }
    if(ans < f[0][0]) 
		cout << "1\n" << ans;
    else{
    	int i,j;
        for(i = n;i >= 1;i --) {
            for(j = 1;j <= m;j ++) {
                if(f[i][j] < f[0][0]) 
					break;
            }
            if(j <= m) 
				break;
        }
        ans = 0;
        for(j = 1;j <= i;j ++) {
            if(have[j]) 
				ans++;
        }
        cout << "0\n" << ans;
    }
    return 0;
}
