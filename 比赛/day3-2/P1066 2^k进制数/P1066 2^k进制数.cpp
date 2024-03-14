#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;
int a[30001][205],ans[205],k,w;

void calc(int *a,int *b) {
	int len = 0,x = 0;
	while (len < a[0] || len < b[0]){
		len ++;
		a[len] = a[len] + b[len] + x;
		x = a[len]/10;
		a[len] %= 10;
	}
	if (x > 0)
		a[++len] = x;
	a[0] = len;
}

int main() {
	scanf("%d%d",&k,&w);
	int kk = w%k;
	int ll = w/k;
	int maxx = 0;
	for(ri i = 1;i <= kk;i ++)
		maxx += 1 << (i-1);     //最高位最大是几
	int minn = (1<<k)-1;//第一位最大是多少
	if (ll == 1 || (ll == 2 && kk == 0)) {
		if (kk == 0)
			maxx = minn;
		int tot = 0;
		for (ri i = 1;i <= maxx;i ++)
			tot += minn-i;
		cout << tot;
		return 0;
	}
	for (ri i = 1;i <= minn-1;i ++) {
		a[i][1] = i;
		a[i][0] = 1;
		calc(ans,a[i]);
	}
	for (ri i = 3;i <= ll;i ++)
		for (ri j = 1;j <= minn-i+1;j ++){
			calc(a[j],a[j-1]);
			calc(ans,a[j]);
		}
	for (ri j = 1;j <= minn-ll;j ++)
		calc(a[j],a[j-1]);
	for (ri j = minn-ll;j >= max(minn-ll-maxx+1,1);j --)
		calc(ans,a[j]);
	for (ri i = ans[0];i >= 1;i --)
		printf("%d",ans[i]);
}
