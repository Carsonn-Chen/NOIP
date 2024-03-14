#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int r,n,m;
int a[50005];

bool check(int x) {
	int cnt = 0;
	int now = 0;
	for(int i = 1; i <= n+1; i ++){
		if(a[i] - a[now] < x)
			cnt++;
		else
			now = i;
	}
	if(cnt > m)
		return false;
	return true;
}

int main() {
	scanf("%d%d%d",&r,&n,&m);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&a[i]);
	a[n+1] = r;
	int l = 1;
	int ans;
	while(l <= r) {
		int mid = (r+l) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		} 
		else
			r = mid -1;
	}
	printf("%d\n",ans);
	return 0;
}
