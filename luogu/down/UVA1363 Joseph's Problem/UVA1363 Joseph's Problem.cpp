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
	while(scanf("%lld%lld",&n,&k) == 2){					//ע��������� 
		ll ans = 0;
	    ll a = (ll)sqrt(k*1.0);								//����!!!(��waŶ) 
		ll b = k/a;
	    if (n > k)											//n>k��ʱ��,����i>kʱ,mod�Ľ������k,ֱ�ӳ��������Ͼͺ��� 
			ans += (n-k)*k;
	    for (ri i = a;i > 1;i --){
	        ll s = k/i,e = k/(i-1);
	        if (s > n)
				break;
	        if (e > n)
				e = n;
	        ans += (k%(s+1) + k%e) * (e-s)/2;				//�Ȳ�������͹�ʽ 
	    }
	    for(ri i = 2;i <= n && i <= b;i ++)
	        ans += k%i;
	    printf("%lld\n",ans);
	}
	return 0;
}
