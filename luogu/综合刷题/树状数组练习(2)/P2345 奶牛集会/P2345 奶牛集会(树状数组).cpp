// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define LL long long

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

int n;
LL Max = -1e9;
struct node{
    int v;
    int x;
}cow[20005];
LL tree1[20005],tree2[20005];

bool cmp(node a,node b){
    return a.v < b.v;
}

int lowbit(int x){
    return x & -x;
}

void add1(int x,int k){
    for(;x <= Max;x += lowbit(x))
        tree1[x] += k;		
}

LL sum1(int x){
	LL ans = 0;
	for(;x > 0;x -= lowbit(x))
		ans += tree1[x];
	return ans;
}

void add2(int x,int k){
    for(;x <= Max;x += lowbit(x))
        tree2[x] += k;		
}

LL sum2(int x){
	LL ans = 0;
	for(;x > 0;x -= lowbit(x))
		ans += tree2[x];
	return ans;
}

int main(){
    n = read();
    for(ri i = 1;i <= n;i ++){
        cow[i].v = read();
        cow[i].x = read();
        Max = max(Max,(LL)cow[i].x);
    }
    LL ans = 0;
    sort(cow+1,cow+1+n,cmp);
    for(ri i = 1;i <= n;i ++){
        add1(cow[i].x,1);
		add2(cow[i].x,cow[i].x);
        LL q1 = sum1(cow[i].x-1),q2 = i-sum1(cow[i].x);
		LL h1 = sum2(cow[i].x-1),h2 = sum2(Max)-sum2(cow[i].x);
        ans += ((q1-q2)*cow[i].x + h2 - h1)*cow[i].v;
    }
	printf("%lld\n",ans);
    return 0;
}
