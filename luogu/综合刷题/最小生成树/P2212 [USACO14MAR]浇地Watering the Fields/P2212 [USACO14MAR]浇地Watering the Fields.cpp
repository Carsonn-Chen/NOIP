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
    double value;
}p[4000005];

struct pos{
	int x,y;
}q[2005];

int fa[2005];

bool cmp1(pha x,pha y){
    return x.value < y.value;
}

int Find(int x){
    if(x == fa[x])
    	return x;
    return fa[x] = Find(fa[x]);
}

int calc(int i,int j){
	return (q[i].x - q[j].x)*(q[i].x - q[j].x) + (q[i].y - q[j].y)*(q[i].y - q[j].y);
}

int main(){
    ios::sync_with_stdio(false);
    int n,c,tot = 0;
    cin >> n >> c;
    for(ri i = 1;i <= n;i ++)
        cin >> q[i].x >> q[i].y;
    for(ri i = 1;i <= n;i ++){
    	fa[i] = i;
    	for(ri j = 1;j < i;j ++){
			int d = calc(i,j);
			if(d >= c){
				tot ++;
				p[tot].begin = i;
				p[tot].end = j;
				p[tot].value = d;
			}
		}
	}
    sort(p+1,p+1+tot,cmp1);
    int cnt = 0;
    long long ans = 0;
    for(ri i = 1;i <= tot && cnt < n - 1;i ++){
		int f1 = Find(p[i].begin);
        int f2 = Find(p[i].end);
        if(f1 != f2){
            fa[f2] = f1;
            ans += p[i].value;
            cnt ++;
        }
    }
    if(cnt == n-1)
		cout << ans << endl;
	else
		cout << "-1" << endl;
    return 0;
}
