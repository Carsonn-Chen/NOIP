#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 1501;
int N,L,R,A[maxn],ans;
inline int read() {
	char ch = getchar();int k = 1,sum = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') k = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9') {sum = sum * 10 + ch - '0';ch = getchar();}
	return sum * k;
}
int f[maxn][maxn];
bool s[maxn];
void DFS(int cur,int c) {
	if(c > L)return;
	if(cur > N && c == L) {
		int la = 0,sum = 0;
		for(int i = 1;i < N;i ++) {
			if(s[i]) {
				if(sum == 0)sum = f[1][i];
				else sum = sum&f[la+1][i];
				la = i;
			}
		}
		sum = sum&f[la+1][N];
		ans = max(ans,sum);
	}
	else if(cur <= N){
		if(cur < N) {
		s[cur] = 1;
		DFS(cur+1,c+1);}
		s[cur] = 0;
		DFS(cur+1,c);
	}
}
int main() {
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	N = read(),L = read(),R = read();
	for(int i = 1;i <= N;i ++) A[i] = read(),f[i][i] = A[i];
	for(int i = 1;i <= N;i ++) {
		for(int j = i+1;j <= N;j ++) {
			if(i > 1)f[i][j] = f[1][j]^f[1][i];
			else f[i][j] = f[i][j-1]^A[j];
		}
	}
	for(;L <= R;L++) DFS(1,0);
	cout << ans;
	return 0;
}
