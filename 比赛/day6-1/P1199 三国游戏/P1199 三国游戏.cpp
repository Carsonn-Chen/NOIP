#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

long long m[1005][1005];
long long maxx[1005];
long long ans[1005];

int main(){
	//freopen("testdata.in","r",stdin);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n-1;i ++)
		for(ri j = i+1;j <= n;j ++){
			cin >> m[i][j];
			m[j][i] = m[i][j];
		}
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			maxx[i] = max(maxx[i],m[i][j]);
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			if(m[i][j] < maxx[i])
				ans[i] = max(ans[i],m[i][j]);
	cout << 1 << endl;
	cout << *max_element(ans+1,ans+1+n) << endl;
	return 0;
}
