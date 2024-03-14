#include <bits/stdc++.h>

using namespace std;

int food[205][205],f[205][205];

int main(){
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	int m,n;
	scanf("%d%d",&m,&n);
	int cnt = 3;
	for(int i = 1;i <= m;i ++)
		for(int j = 1;j <= n;j ++)
			scanf("%d",&food[i][j]);
	for(int i = m;i > (n+1)/2;i -= 1,cnt += 2){
		int cnt2 = (n-cnt)/2;
		for(int j = 1;j <= cnt2;j ++)
			food[i][j] = -99999;
		for(int j = n-cnt2+1;j <= n;j ++)
			food[i][j] = -99999;
	}
	for(int i = m;i >= 1;i --){
		for(int j = 1;j <= n;j ++){
			f[i][j] = max(f[i+1][j-1]+food[i][j],f[i+1][j]+food[i][j]);
			f[i][j] = max(f[i][j],f[i+1][j+1]+food[i][j]);
		}
	}
	printf("%d",*(max_element(f[1]+1,f[1]+n+1)));
	return 0;
}
