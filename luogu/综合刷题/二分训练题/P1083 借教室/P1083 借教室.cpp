#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m;
int cf[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];

bool check(int x) {
	memset(cf,0,sizeof(cf));
	for(int i = 1; i <= x; i ++) {
		cf[l[i]] += d[i];
		cf[r[i]+1] -= d[i];
	}
	for(int i = 1; i <= n; i ++) {
		need[i] = need[i-1]+cf[i];
		if(need[i] > rest[i])
			return false;
	}
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i ++)
		scanf("%d",&rest[i]);
	for(int i = 1; i <= m; i ++)
		scanf("%d%d%d",&d[i],&l[i],&r[i]);
	int begin = 1,end = m;
	if(check(m)) {
		printf("0\n");
		return 0;
	}
	int ans = 0;
	while(begin <= end) {
		int mid = (begin+end)>>1;
		if(check(mid)) {
			begin = mid+1;
			ans = mid;
		} else
			end = mid-1;
	}
	printf("-1\n%d\n",ans+1);
}
