#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

const int maxn=100005;
double a[maxn],sum[maxn]; //原始序列a[], 前缀和sum[], 

int main(){
    freopen("cowfnc.in","r",stdin) ;
    freopen("cowfnc.out","w",stdout);
	int n,L,i;	
	cin>>n>>L;
	for(i=1;i<=n;i++) cin>>a[i];
	double eps=1e-5;     //精度  
	double l=0,r=1e9,mid; //答案范围在[l,r] 
	while(r-l>eps){
		mid=(r+l)/2;
		for(i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i]-mid;
		double ans=-1e10;
		double minn=1e10;
		for(i=L;i<=n;i++){
			minn=min(minn,sum[i-L]);
			ans=max(ans,sum[i]-minn);
		}
		if(ans>=0) l=mid;
		else r=mid;
	}
	cout<<int(r*1000)<<endl;
	return 0;
}
