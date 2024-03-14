#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tree[1000005];
long long m;

bool check(int x){
	long long mm = 0;
	for(int i = 1;i <= n;i ++){
		if(tree[i] <= x)
			break;
		mm = (mm + tree[i]-x);
	}
	if(mm >= m)
		return true;
	else
		return false; 
}

bool cmp(int a,int b){
	return a > b;
}

int main(){
	int l = 0,r = 0;
	scanf("%d%lld",&n,&m);
	m = m;
	for(int i = 1;i <= n;i ++){
		scanf("%d",&tree[i]);
		r = max(r,tree[i]);
	}
	sort(tree+1,tree+1+n,cmp);
	int ans;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else
			r = mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
