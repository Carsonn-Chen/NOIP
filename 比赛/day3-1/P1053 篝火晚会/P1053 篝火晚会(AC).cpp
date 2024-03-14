#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define MAXN 50000+10

using namespace std;
int a[MAXN],b[MAXN],cir[MAXN],s[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> a[i] >> b[i];
	cir[1] = 1;
	cir[2] = a[1];
	for(ri i = 1;i <= n;i ++){
		if(b[a[i]] != i && a[a[i]] != i || a[b[i]] != i && b[b[i]] != i){
			printf("-1");
			return 0;
		}
		if(a[cir[i]] == cir[i-1])
			cir[i+1] = b[cir[i]];
		else
			cir[i+1]=a[cir[i]];
	}
	int ans = n+10;
	for(ri i = 1;i <= n;i ++){
		s[((i-cir[i]+n))%n] ++;
		ans = min(ans,n-s[((i-cir[i]+n))%n]);
	}
	memset(s,0,sizeof(s));
	memset(cir,0,sizeof(cir));
	cir[0] = 1;
	cir[1] = b[1];
	for(ri i = 1;i <= n;i ++){
		if(b[cir[i]] == cir[i-1])
			cir[i+1] = a[cir[i]];
		else 
			cir[i+1] = b[cir[i]];
	}
	for(ri i = 1;i <= n;i ++) {
		s[((i-cir[i]+n))%n] ++;
		ans = min(ans,n-s[((i-cir[i]+n))%n]);
	}
	cout << ans << endl;
}
