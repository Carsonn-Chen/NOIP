#include <bits/stdc++.h>

using namespace std;

int m[160][160];
int d;
long long ans;
int ans2;

void solve(int x1,int y1){
	long long temp = 0;
	for(int i = ((x1-d)>=0?(x1-d):0);i <= (x1+d);i ++)
		for(int j = ((y1-d)>=0?(y1-d):0);j <= (y1+d);j ++)
			temp += m[i][j];
	if(temp > ans){
		ans = temp;
		ans2 = 1;
	}
	else if(temp == ans)
		ans2 ++;
}

int main(){
	int n;
	scanf("%d%d",&d,&n);
	int x,y,v;
	for(int i = 1;i <= n;i ++){
		scanf("%d%d%d",&x,&y,&v);
		m[x][y] = v;
	}
	for(int i = 0;i <= 128;i ++)
		for(int j = 0;j <= 128;j ++)
			solve(i,j);
	cout << ans2 << ' ' << ans << endl;
	return 0;
}
