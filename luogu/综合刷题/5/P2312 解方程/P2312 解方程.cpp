#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mod 1000000007
#define ll long long

using namespace std;

int n,m;
ll a[105];
//bool tag[1000005];
int tag[1000005];
int ans;


ll read(){
	ll sum = 0,zf = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') 
			zf = -1;
		c = getchar();
	}
	while(c >='0' && c <='9'){
		sum = ((sum*10)+c-'0')%mod;
		c = getchar();
	}
	return zf*sum;
}

void out(int x){
	if(x>9)
        out(x/10);
    putchar(x%10+'0');
}

bool check(int x){
	int sum = 0;
	for(int i = n;i >= 1;i --)
		sum = ((sum + a[i])%mod * x%mod)%mod;
	sum = (sum + a[0])%mod;
	return !sum;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i <= n;i ++)
		a[i] = read();
	int cnt = 1;
	for(int i = 1;i <= m;i ++)
		if(check(i)){
			ans ++;
			tag[cnt ++] = i;
		}
	/*printf("%d\n",ans);
	for(int i = 1;i <= n;i ++)
		if(tag[i])
			printf("%d\n",i);*/
	if(ans == 0){
		printf("0\n");
		return 0;
	}
	out(ans);
	putchar('\n');
	for(int i = 1;i < cnt;i ++){
		out(tag[i]);
		putchar('\n');
	}
	return 0;
}
