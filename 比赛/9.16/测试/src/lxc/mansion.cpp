#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

int num[5005];
int f[5005];
const int Mod = 1e9+7;

int calc(int x){
	int ans = 1;
	while(x > 1){
		ans *= x;
		x --;
	}
	return ans;
}

int main(){
	freopen("mansion.in","r",stdin);
	freopen("mansion.out","w",stdout);
	int n,l,r,ans = 0;
	scanf("%d%d%d",&n,&l,&r);
	for(int i = 1;i <= n;i ++)
		num[i] = i;
	int m = calc(n);
	for(int i = 1;i <= m;i ++){
		int lcnt = 0,rcnt = 0,max = num[1];
		f[1] = 1;
		for(int j = 2;j <= n;j ++){
			if(num[j] > max){
				f[j] = f[j-1]+1;
				max = num[j];
			}
			else
				f[j] = f[j-1];
		}
		lcnt = f[n];
		f[n] = 1;
		max = num[n];
		for(int j = n-1;j >= 1;j --){
			if(num[j] > max){
				f[j] = f[j+1]+1;
				max = num[j];
			}
			else
				f[j] = f[j+1];
		}
		rcnt = f[1];
		if(rcnt == r && lcnt == l)
			ans ++;
		next_permutation(num+1,num+1+n);	
	}
	printf("%d\n",ans%Mod);
	return 0;
}
