#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n,k;
int L[10005];

bool check(int x){
	int kk = 0;
	for(int i = 1;i <= n;i ++)
		kk = kk+L[i]/x;
	if(kk >= k)
		return true;
	return false;
}

int main(){
	scanf("%d%d",&n,&k);
	long long l = 0,r = 0;
	for(int i = 1;i <= n;i ++){
		double temp;
		scanf("%lf",&temp);
		L[i] = (int)(temp*100);
		r += L[i];
	}
	r /= k;
	long long ans = 0;
	while(l <= r){
		long long mid = (l+r) >> 1;
		if(mid == 0)
			break;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else
			r = mid-1;
	}
	printf("%.2lf",(double)ans/100.0);
	return 0;
}
