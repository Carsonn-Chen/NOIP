#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define ll long long 
#define maxn 1000005

using namespace std;

ll read(){
	ll sum = 0,f = 1;
	char e = getchar();
	while(!isdigit(e)){
		if(e == '-')
			f = -1;
		e = getchar();
	}
	while(isdigit(e)){
		sum = sum*10 + e - '0';
		e = getchar();
	}
	return sum*f;
}

ll n,p,maxsum;
ll a[maxn];
ll sum[maxn],t[maxn];
ll b[maxn];

int main() {
	n = read(),p = read();
	for(ri i = 1;i <= n;i ++)
		a[i] = read();
	sum[1] = a[1];
	maxsum = a[1];
	t[1] = a[1];
	for(ri i = 2;i <= n;i ++){ 
		sum[i] = max(sum[i-1]+a[i],a[i]);
		t[i] = max(sum[i],maxsum);
		maxsum = t[i];
	}
	b[1] = t[1];
	b[2] = t[1]+b[1];
	bool tag = 0;
	if(b[2] >= b[1])
		tag = 1;
	for(ri i = 3;i <= n;i ++) {
		if(t[i-1] > 0) {
			b[i] = b[i-1]+t[i-1];
			if(b[i] > b[1])
				tag = 1;
			if(b[i] > 1e9)
				b[i] %= p;
		}
		else
			b[i] = b[2];
	}
	ll ans;
	if(tag)
		ans = b[n];
	else
		ans = b[1];
	ans = ans % p;
	cout << ans;
	return 0;
}
