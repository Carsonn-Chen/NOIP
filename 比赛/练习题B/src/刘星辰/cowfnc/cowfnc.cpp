#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=100005;
double a[maxn],sum[maxn];

int main() {
	freopen("cowfnc.in","r",stdin) ;
	freopen("cowfnc.out","w",stdout);
	int n,L,i;
	cin >> n >> L;
	for(int i = 1;i <= n;i ++) 
		cin >> a[i];
	double eps = 1e-5;
	double l = 0,r = 1e9,mid;
	while(r-l > eps) {
		mid = (r+l)/2;
		for(int i = 1; i <= n;i ++)
			sum[i] = sum[i-1]+a[i]-mid;
		double ans = -1e10;
		double minn = 1e10;
		for(int i = L;i <= n;i ++) {
			minn = min(minn,sum[i-L]);
			ans = max(ans,sum[i]-minn);
		}
		if(ans >= 0) 
			l = mid;
		else 
			r = mid;
	}
	cout << int(r*1000) << endl;
	return 0;
}
