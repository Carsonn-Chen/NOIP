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
}p[260000];

struct pos{
	int x,y;
}q[700];

int fa[700];
bool tag[700];

bool cmp1(pha x,pha y){
    return x.value < y.value;
}

bool cmp2(pha x,pha y){
    return x.value > y.value;
}

int Find(int x){
    while(fa[x] != x)
        x = fa[x];
    return x;
}

double calc(int i,int j){
	return sqrt((q[i].x - q[j].x)*(q[i].x - q[j].x) + (q[i].y - q[j].y)*(q[i].y - q[j].y));
}

int main(){
    ios::sync_with_stdio(false);
    int s,P,tot = 0;
    cin >> s >> P;
    for(ri i = 1;i <= P;i ++)
        cin >> q[i].x >> q[i].y;
    for(ri i = 1;i <= P;i ++){
    	fa[i] = i;
    	for(ri j = 1;j <= P;j ++){
			tot ++;
			p[tot].begin = i;
			p[tot].end = j;
			p[tot].value = calc(i,j);
		}
	}
    sort(p+1,p+1+tot,cmp1);
    int cnt = 0;
    double ans;
    s = P-s;
    for(ri i = 1;i <= tot && s;i ++){
        int f1 = Find(p[i].begin);
        int f2 = Find(p[i].end);
        if(f1 != f2){
            fa[f2] = f1;
            ans = p[i].value;
            s --;
        }
    }
	printf("%.2lf\n",ans);
    return 0;
}
