#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m;
int a[1005],d[1005],f[1005],vi[1005][1005],c[1005][1005];

int dfs(int x){
    if (f[x]) 
		return f[x];
    for(ri i = 1;i <= c[x][0];i ++) 
		f[x] = max(f[x],dfs(c[x][i]));
    return ++f[x];
}

int main(){
    scanf("%d%d",&n,&m);
    int l;
    for (ri i = 1;i <= m;i ++){
        scanf("%d",&a[0]);
        for (ri j = 1;j <= a[0];j ++) 
			scanf("%d",&a[j]);
        l = 1;
        for (ri j = a[1];j < a[a[0]];j ++){
            if (a[l] == j) 
				l ++;
            else 
				for (ri k = 1;k <= a[0];k ++)
                	if (!vi[a[k]][j]){
						c[a[k]][++c[a[k]][0]] = j;
						vi[a[k]][j] = 1;
					}
		}
    }
    int ans = 0;
    for(ri i = 1;i <= n;i ++) 
		ans = max(ans,dfs(i));
    printf("%d",ans);
}
