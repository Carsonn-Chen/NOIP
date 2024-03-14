#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

long long a[1005];
long long Max[1005][1005],Gcd[1005][1005];

/*long long Max(int x,int y){
	long long maxx = 0;
	for(int i = x;i <= y;i ++)
		maxx = max(maxx,a[i]);
	return maxx;
}

long long gcd(int x,int y){
	if(y == x)
		return a[x];
	long long re = __gcd(a[x],a[x+1]);
	for(int i = x+2;i <= y;i ++){
		re = __gcd(re,a[x]);
		if(re == 1)
			return 1;
	}
	return re;
}*/

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	for(int i = 1;i <= n;i ++)
		Gcd[i][i] = a[i];
	for(int i = 1;i <= n;i ++)
		for(int j = i;j <= n;j ++){
			Max[i][j] = max(Max[i][j-1],a[j]);
			Gcd[i][j] = __gcd(Gcd[i][j-1],a[j]);
		}
	long long ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = i;j <= n;j ++)
			// O(1)
			ans = (ans + Gcd[i][j]*Max[i][j])%998244353;
	printf("%lld\n",ans);
	return 0;
}
