/*最小距离尽可能的最大：双'最'问题。二分配合贪心即可解决 O(nlogn)。*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

int n,m,x[100010],l,r,mid,ans;

bool check(int d){
	int rec=1,now=x[1]+d;
	for(int i=2;i<=n;++i){
		if(x[i]<now) continue;
		++rec; now=x[i]+d;
	}
	return rec>=m;
}
int main(){
    freopen("aggr.in","r",stdin);
    freopen("aggr.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	l=0; r=x[n]-x[1];
	while(l<=r){
		mid=l+(r-l>>1);
		if(check(mid)){ ans=mid; l=mid+1; }
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
