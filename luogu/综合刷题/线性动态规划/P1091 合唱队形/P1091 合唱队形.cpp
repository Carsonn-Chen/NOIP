#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int h[105];
int f[105];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int hest;
	int ans = 999999999;
	for(ri i = 1;i <= n;i ++)
		cin >> h[i];
	for(ri j = 1;j <= n;j ++){
		hest = j;	
		memset(f,0x3f,sizeof(f));
		for(ri i = 1;i <= hest; i++){
			int x = h[i];
			*lower_bound(f+1,f+1+hest,x) = x;
		}
		int cnt1 = lower_bound(f+1,f+n+1,f[0])-f-1;
		memset(f,0x3f,sizeof(f));
		for(ri i = n;i >= hest;i --){
			int x = h[i];
			*lower_bound(f+1,f+1+hest,x) = x;
		}
		int cnt2 = lower_bound(f+1,f+1+hest,f[0]) - f - 1;
		ans = min(ans,n - cnt1 - cnt2 + 1);
	}
	cout << ans << endl;
}
