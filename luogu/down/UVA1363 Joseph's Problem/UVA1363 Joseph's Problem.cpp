#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int
#define ll long long

using namespace std;

int main(){
	ll n,k;
	while(scanf("%lld%lld",&n,&k) == 2){					//注意多组数据 
		ll ans = 0;
	    ll a = (ll)sqrt(k*1.0);								//精度!!!(会wa哦) 
		ll b = k/a;
	    if (n > k)											//n>k的时候,对于i>k时,mod的结果都是k,直接乘起来加上就好啦 
			ans += (n-k)*k;
	    for (ri i = a;i > 1;i --){
	        ll s = k/i,e = k/(i-1);
	        if (s > n)
				break;
	        if (e > n)
				e = n;
	        ans += (k%(s+1) + k%e) * (e-s)/2;				//等差数列求和公式 
	    }
	    for(ri i = 2;i <= n && i <= b;i ++)
	        ans += k%i;
	    printf("%lld\n",ans);
	}
	return 0;
}
