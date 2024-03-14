#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL pow_mod(int a,int n,int k){
	if(n == 1)
		return a;
	LL ans = (pow_mod(a,n/2,k) % k);
	ans = ans*ans % k;
	if(n %2 == 0)
		return ans;
	else 
		return ans * (a%k);
}

int main(){
	int a,n,k;
	LL an;
	cin >> a >> n >> k;
	if(n == 0)
		an = 1;
	else
		an = pow_mod(a,n,k);
		an = an % k;
	printf("%d^%d mod %d=%lld",a,n,k,an);
	return 0;
}
