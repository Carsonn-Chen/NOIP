#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 20123

using namespace std;

int read(){
	char e = getchar();
	int sum = 0;
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		sum = sum * 10 + e - '0';
		e = getchar();
	}
	return sum;
}

int n,m;
int a[10005][105][2];
int next[10005][105];
int nextt[10005][105];
long long ans = 0;

/*void search(int h,int pos){
	if(h == n+1){
		cout << ans << endl;
		exit(0);
	}
	int x = a[h][pos][1];
	ans += (x % mod);
	int cnt = 0;
	if(a[h][pos][0])
		cnt ++;
	while(cnt < x){
		pos ++;
		if(pos == m)
			pos = 0;
		if(a[h][pos][0] == 1)
			cnt ++;
	}
	search(h+1,pos);
}*/

int main(){
	n = read(),m = read();
	for(ri i = 1;i <= n;i ++){
		int cnt = 0;
		for(ri j = 0;j < m;j ++) {
			a[i][j][0] = read(),a[i][j][1] = read();
			next[i][j] = cnt;
			if(a[i][j][0] == 1){
				nextt[i][cnt] = j;
				cnt ++;
			}
		}
		for(ri j = m-1;j >= 1;j --){
			if(next[i][j] == cnt) 
				next[i][j] = 0;
			else
				break;
		}
		nextt[i][104] = cnt;
	}
	
	int now = read();
	for(ri i = 1;i <= n;i ++) {
		ans += a[i][now][1] % mod;
		now = nextt[i][(next[i][now] + a[i][now][1]-1)%nextt[i][104]];
	}
	cout << ans % mod;
	return 0;
}
