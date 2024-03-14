#include <bits/stdc++.h>

using namespace std;

int last[55],cnt[55],sum[200005];

int main(){
	int n,k,p;
	cin >> n >> k >> p;
	int color,price;
	int now,ans = 0;
	for(int i = 1;i <= n;i ++){
		cin >> color >> price;
		if(price <= p)
			now = i;
		if(now >= last[color])
			sum[color] = cnt[color];
		ans += sum[color];
		last[color] = i;
		cnt[color]++;
	}
	printf("%d\n",ans);
	return 0;
}
