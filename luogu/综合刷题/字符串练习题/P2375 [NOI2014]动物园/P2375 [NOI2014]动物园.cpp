#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

const long long mod=1000000007;

int n;
char a[1000005];
int len;
int next[1000005];
long long num[1000005];
int j;

void kmp() {
	j = 0;
	for(ri i = 1;i < len;i ++) {
		while(j&&a[j] != a[i])
			j = next[j];
		if(a[j] == a[i])
			j ++;
		next[i+1] = j;
		num[i+1] = num[j]+1;
	}
}

int main() {
	scanf("%d",&n);
	while(n--){
		memset(next,0,sizeof(next));
		scanf("%s",a);
		len = strlen(a);
		num[0] = 0;
		num[1] = 1;
		kmp();
		j = 0;
		long long ans = 1;
		for(ri i = 1;i < len;i ++){
			while(a[j] != a[i]&&j)
				j = next[j];
			if(a[i] == a[j])
				j ++;
			while((j<<1) > i+1)
				j = next[j];
			ans = (ans * (num[j]+1)) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
