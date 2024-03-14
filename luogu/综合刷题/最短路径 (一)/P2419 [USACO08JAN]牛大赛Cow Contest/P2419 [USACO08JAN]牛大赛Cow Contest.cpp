#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m,f[101][101];

int main(){
	ios::sync_with_stdio(false);
    cin >> n >> m;
    int a,b;
    for(ri i = 1;i <= m;i ++){
        cin >> a >> b;
        f[a][b] = 1;
    }
    for(ri k = 1;k <= n;k ++)
        for(ri i = 1;i <= n;i ++)
            for(ri j = 1;j <= n;j ++)
              f[i][j] |= f[i][k]&f[k][j];
    int ans = 0;
	for(ri i = 1;i <= n;i ++){
        int temp = 1;
        for(ri j = 1;j <= n;j ++)
        if(i == j)
			continue;
		else 
        	temp &= (f[i][j] | f[j][i]);
        ans += temp;
    }
    printf("%d\n",ans);
}
