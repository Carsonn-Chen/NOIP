#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
	int summ = 0,f = 1;
	char e = getchar();
	while(!isdigit(e)){
		if(e == '-')
			f = -1;
		e = getchar();
	}
	while(isdigit(e)){
		summ = summ*10 + e - '0';
		e = getchar();
	}
	return summ * f;
}

int n,d,k;
int x[500005],w[500005];
long long f[500005];

bool check(int g){
	memset(f,-127,sizeof(f));
	f[0] = 0;
	int minn = d-g,maxx = d+g;
	for(ri i = 1;i <= n;i ++){
		for(ri j = i-1;j >= 0;j --){
			if(x[i] - x[j] < minn)
				continue;
			else if(x[i]- x[j] > maxx)
				break;
			f[i] = max(f[i],f[j] + w[i]);
			if(f[i] >= k)
				return true;
		}
	}
	return false;
}

int main(){
	n = read(),d = read(),k = read();
	int maxx = 0;
	for(ri i = 1;i <= n;i ++){
		x[i] = read();
		w[i] = read();
		maxx = max(maxx,maxx+w[i]);
	}
	if(maxx < k){
		printf("-1");
		return 0;
	}
	int l = 1,r = 100005;
	int ans;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid))
			r = mid - 1,ans = mid;
		else
			l = mid + 1;
	}
	printf("%d",ans);
	return 0;
}
