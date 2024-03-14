#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
	char e = getchar();
	int ans = 0;
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		ans = ans*10 + e - '0';
		e = getchar();
	}
	return ans;
}

int n,f,c;
int like[505];
int dis[505][505];

int main(){
	n = read();	f = read();	c = read();
	for(ri i = 1;i <= f;i ++)
		like[i] = read();
	for(ri i = 1;i <= n;i ++)
		for(ri j = 1;j <= n;j ++)
			if(i != j)
				dis[i][j] = 1e9;
	for(ri i = 1;i <= c;i ++){
		int a = read(),b = read(),c = read();
		dis[a][b] = dis[b][a] = c;
	}
	for(ri k = 1;k <= n;k ++)
		for(ri i = 1;i <= n;i ++)
			if(dis[i][k] != 1e9)
				for(ri j = 1;j <= n;j ++)
					if(dis[k][j] != 1e9)
						dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	int Min = 1e9;
	int ans;
	for(ri i = 1;i <= n;i ++){
		int temp = 0;
		for(ri j = 1;j <= f;j ++)
			temp += dis[i][like[j]];
		if(Min > temp){
			Min = temp;
			ans = i;
		}
	}
	cout << ans << endl;	
}
