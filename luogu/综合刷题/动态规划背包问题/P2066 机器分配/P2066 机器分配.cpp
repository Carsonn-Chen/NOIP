#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int v[15][20];
int ans[15][20];
int f[20];

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> v[i][j];
	for (ri i = n;i > 0;i --){
        for (ri j = m;j >= 0;j --){
            for(ri k = 1;k <= j;k ++){
                if (f[j-k]+v[i][k] > f[j]){
                    f[j] = f[j-k]+v[i][k];
                    ans[i][j] = k;
                }
            }
        }
    }
	cout << f[m];
    for (ri i = 1,j = m;i <= n;i ++){
        cout << '\n' << i << " " << ans[i][j];
        j -= ans[i][j];
    }
    return 0;
}
