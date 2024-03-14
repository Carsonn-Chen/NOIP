#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int peo[105];
int dis[105][105];
int n;

/*void build(int id,int cnt,int last){
	if(id == n+1)
		return;
	int a,b,c;
	cin >> a >> b >> c;
	peo[id] = a;
	dis[id][last]  = dis[last][id] = 1;
	if(b != 0)
		build(b,cnt+1,id);
	if(c != 0)
		build(c,cnt+1,id);
}*/

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			if(i != j)
				dis[i][j] = INT_MAX;
	int l,r;	
	for(ri i= 1;i <= n;i ++){
		cin >> peo[i];
		cin >> l >> r;
		if(l >= 0){
			dis[i][l] = 1;
			dis[l][i] = 1;
		}
        if(r >= 0){
			dis[i][r] = 1;
			dis[r][i] = 1;
		}
	}
	//build(1,1,0);
	
	for(ri k = 1;k <= n;k ++)
		for(ri i = 1;i <= n;i ++)
			if(dis[i][k] != INT_MAX)
				for(ri j = 1;j <= n;j ++)
					if(dis[k][j] != INT_MAX)
						dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	long long temp;
	long long ans = LLONG_MAX;
	for(ri i = 1;i <= n;i ++){
		temp = 0;
		for(ri j = 1;j <= n;j ++)
			if(i != j)
				temp += peo[j]*dis[i][j];
		ans = min(ans,temp);
	}
	cout << ans << endl;
	return 0;
}
