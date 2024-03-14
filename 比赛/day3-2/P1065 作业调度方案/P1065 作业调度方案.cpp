#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int m,n;
int order[405];
int mac[2][25][25];
int pos[25];
bool TIME[25][405];
int ans;
int ti[25];

int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for(ri i = 1;i <= n;i ++)
		pos[i] = 1;
	for(ri i = 1;i <= m*n;i ++)
		cin >> order[i];					//安排的顺序 
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> mac[0][i][j];			//使用的机器的编号 
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= m;j ++)
			cin >> mac[1][i][j];			//每道工序消耗的时间 
	
	for(ri i = 1;i <= m*n;i ++){
		int x = order[i];
		int id = mac[0][x][pos[x]];
		int t = mac[1][x][pos[x]];
		int l = ti[order[i]],r = l;
		while(r - l < t){
			r ++;
			if(r - l == t)
				break;
			if(TIME[id][r]){
				while(TIME[id][r])
					r ++;
				l = r - 1;
			}
		}
		while(l <= r)
			TIME[id][l++] = 1;
		ans = max(ans,r);
		pos[x] ++;
		ti[x] = max(ti[x],r);
	}
	cout << ans << endl;
	return 0;
}
