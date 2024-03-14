#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

struct pha{
    int begin;
    int end;
    int value;
}p[10005];

int fa[105];

bool cmp1(pha x,pha y){
    return x.value < y.value;
}

int Find(int x){
    while(fa[x] != x)
        x = fa[x];
    return x;
}

int main(){
	ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    long long tot = 0;
    for(ri i = 1;i <= k;i ++)
    	cin >> p[i].begin >> p[i].end >> p[i].value,tot += p[i].value;
    for(ri i = 1;i <= n;i ++)
        fa[i] = i;
    sort(p+1,p+k+1,cmp1);
    int cnt = 0,Max = 0;
    for(ri i = 1;cnt < n-1;i ++){
        int f1 = Find(p[i].begin);
        int f2 = Find(p[i].end);
        if(f1 != f2){
            fa[f2] = f1;
            Max += p[i].value;
            cnt ++;
        }
    }
    printf("%d\n",tot - Max);
	return 0;
}
