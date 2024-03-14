#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int x;
	int y;
	int t;
}xw[5005];

int via[30005];

bool cmp(node a,node b){
	if(a.y-a.x == b.y-b.x)
		return a.x < b.x;
	else
		return a.y-a.x > b.y-b.x;
}

int main(){
	freopen("trees.in","r",stdin);
	freopen("trees.out","w",stdout);
	int n,h;
	int ans = 0;
	scanf("%d%d",&n,&h);
	for(int i = 1;i <= h;i ++){
		scanf("%d%d%d",&xw[i].x,&xw[i].y,&xw[i].t);
		ans += xw[i].t; 
		for(int j = xw[i].x;j <= xw[i].y;j ++)
			via[j] ++;
	}
	sort(xw+1,xw+1+h,cmp);
	for(int i = 1;i <= h;i ++){
		for(int j = xw[i].x;j <= xw[i].y;j ++){
			if(via[j] > 1){
				ans = ans - via[j]+1;
				xw[i].t = xw[i].t - via[j] + 1;
				via[j] = 1;
			}
		}
		if(xw[i].t < 0)
			ans -= xw[i].t;
	}
	printf("%d\n",ans);
	return 0;
}
