#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>
#define ri register int

using namespace std;

int f[10005],dis[10005],a[10005],flag[10005],l,s,t,n;

int main() {
	freopen("in.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> l;
	cin >> s >> t >> n;
	if(s == t){
		int cnt = 0,temp;
		for(ri i = 1; i <= n;i ++){
			cin >> temp;
			if(temp % s == 0)
				cnt += 1;
		}
		cout << cnt << endl;
	}else{
		for(ri i = 1;i <= n;i++)
			cin >> a[i];
		sort(a+1,a+n+1);
		a[0] = 0;
		f[0] = 0;
		dis[n+1] = min(l-a[n],100);
		l = 0;
		for(ri i = 1;i <= n;i ++){
			dis[i] = min(a[i]-a[i-1],90);
			l += dis[i];
			flag[l] = 1;
		}
		l += dis[n+1];
		for(ri i = 1;i <= l+9;i++){
			f[i] = INT_MAX-1;
			for(ri j = s;j <= t;j ++)
				if(i >= j)
					f[i] = min(f[i],f[i-j]+flag[i]);
		}
		int Min = INT_MAX-1;
		for(ri i = l;i <= l+9;i++)
			Min = min(Min,f[i]);
		cout << Min << endl;
	}
	return 0;
}
