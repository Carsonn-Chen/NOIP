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
    int ans = 0;
    while(!isdigit(e))
        e = getchar();
    while(isdigit(e)){
        ans = ans*10+e-'0';
        e = getchar();
    }
    return ans;
}

int n;
struct node{
    int v;
    int x;
}cow[20005];
//int tree[20005];

LL calc(node a,node b){
    return max(a.v,b.v)*(b.x-a.x);
}

bool cmp(node a,node b){
    return a.x < b.x;
}

/*int lowbit(int x){
    return x & -x;
}

void add(int x,int k){
    for(;x <= n;x += lowbit(x))
        tree[x] += k;		
}*/


int main(){
    n = read();
    for(ri i = 1;i <= n;i ++){
        cow[i].v = read();
        cow[i].x = read();
    }
    sort(cow+1,cow+1+n,cmp);
    LL ans = 0;
    for(ri i = 1;i <= n;i ++)
        for(ri j = i;j <= n;j ++)
            ans += calc(cow[i],cow[j]);
    printf("%lld\n",ans);
    return 0;
}
