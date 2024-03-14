#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

int n;
int r[25][25];
int v[25];
bool vis[25];
int temp[25],ans[25];
long long tot;
int cntt;

void search(int cnt,long long all,int i){
	bool flag = 1;
	for(ri j = 1;j <= n;j ++){
		if(r[i][j] == 1 && vis[j] == 0){
			flag = 0;
			vis[j] = 1;
			temp[cnt] = j;
			search(cnt+1,all+v[j],j);
			vis[j] = 0;
		}
	}
	if(flag){
		if(all > tot){
			tot = all;
			cntt = cnt-1;
			for(ri j = 1;j <= cntt ;j ++)
				ans[j] = temp[j];
		}
		return ;
	}
}

int main(){
	scanf("%d",&n);
	for(ri i = 1;i <= n;i ++)
		scanf("%d",&v[i]);
	for(ri i = 1;i <= n;i ++){
		r[i][i] = 0;
		for(ri j = i+1;j <= n;j ++){
			int x;
			scanf("%d",&x);
			r[i][j] = x;
		}
	}
	
	/*for(ri i = 1;i <= n;i ++){
		for(ri j = 1;j <= n;j ++)
			printf("%d ",r[i][j]);
		printf("\n");
	}*/
	
	for(ri i = 1;i <= n;i ++){
		vis[i] = 1;
		temp[1] = i;
		search(2,v[i],i);
		vis[i] = 0;
	}
	for(ri i = 1;i <= cntt;i ++)
		printf("%d ",ans[i]);
	printf("\n%lld\n",tot);
	return 0;
}
