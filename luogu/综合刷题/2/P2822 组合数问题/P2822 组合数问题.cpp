#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

int c[maxn][maxn],s[maxn][maxn];

int main(){
	int  t,k;
	scanf("%d%d",&t,&k);
	for(int i = 0;i <= 2000;i ++)
		c[i][i] = c[i][0] = 1;
	for(int i = 2;i <= 2000;i ++)
		for(int j = 1;j <= i;j ++)	
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%k;
	for(int i = 2;i <= 2000;i ++){
		for(int j = 1;j <= i;j ++){ 
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1];
			if(c[i][j] == 0)
				s[i][j] ++;
		}
		s[i][i+1]=s[i][i];
	}
	int n,m;
	while(t--){
		scanf("%d%d",&n,&m);
		if(m > n)
			m = n;
		printf("%d\n",s[n][m]);
	}
	return 0;
}
