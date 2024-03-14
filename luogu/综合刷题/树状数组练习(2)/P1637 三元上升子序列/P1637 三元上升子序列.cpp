#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int read(){
    char e = getchar();
    int ans = 0,f = 1;
    while(!isdigit(e)){
    	if(e == '-')
    		f = -1;
        e = getchar();
    }
    while(isdigit(e)){
        ans = ans*10+e-'0';
        e = getchar();
    }
    return ans*f;
}

int a[30005],b[30005],tree1[30005],tree2[30005];
int f[30005];
int n;

bool cmp(int x,int y){
	return a[x] < a[y];
}

inline int lowbit(int x){
	return x & -x;
}

void add1(int x,int k){
	for(;x <= n;x += lowbit(x))
		tree1[x] += k;
}

int sum1(int x){
	int ans = 0;
	for(;x;x -= lowbit(x))
		ans += tree1[x];
	return ans;
}

void add2(int x,int k){
	for(;x <= n;x += lowbit(x))
		tree2[x] += k;
}

int sum2(int x){
	int ans = 0;
	for(;x;x -= lowbit(x))
		ans += tree2[x];
	return ans;
}

int main(){
	n = read();
	for(ri i = 1;i <= n;i ++)
		a[i] = read(),b[i] = i;
	sort(b+1,b+1+n,cmp);
	int tmp = 0;
	for(ri i = 1;i <= n;i ++){
		if (i == 1 || a[b[i]] != a[b[i-1]])
            tmp ++;
        f[b[i]] = tmp;
	}
	long long ans = 0;
	for(ri i = 1;i <= n;i ++){
		ans += sum2(f[i]-1);
		add2(f[i], sum1(f[i] - 1));
        add1(f[i], 1);
	}
	printf("%lld",ans);
	return 0;
}
