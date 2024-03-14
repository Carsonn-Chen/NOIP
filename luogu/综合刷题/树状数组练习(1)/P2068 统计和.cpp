#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int tree[500005];
int n,m;

int lowbit(int x){
    return x & -x;
}

void add(int x,int k){
    for(;x <= n;x += lowbit(x))
        tree[x] += k;
}

int sum(int x){
    int ans = 0;
    for(;x != 0;x -= lowbit(x))
        ans += tree[x];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int b,c;
    char e;
    for(ri i = 1;i <= m;i ++){
        cin >> e >> b >> c;
        if(e == 'x')
            add(b,c);
        if(e == 'y')
            printf("%d\n",sum(c)-sum(b-1));
    }
    return 0;
}
