#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int num;
	int cnt;
}ss[105];
int pos;

int main(){
	ios::sync_with_stdio(false);
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	int x = m1;
	for(ri i = 2;i <= x;i ++){
		if(x % i == 0){
			ss[++pos].num = i;
			while(x % i == 0){
				x /= i;
				ss[pos].cnt ++;
			}
			ss[pos].cnt *= m2;
		}
	}
	int minn = INT_MAX;
	while(n --){
		int m;
		cin >> m;
		bool tag = 1;
        for(ri i = 1;i <= pos;i ++)
			tag = tag && (m % ss[i].num == 0);
		if(tag){
			int maxx=0;
			for(ri i = 1;i <= pos;i ++){
				int ans = 0,mx = m;
				while(mx % ss[i].num == 0){
					mx /= ss[i].num;
					ans ++;
				}
				ans = (ss[i].cnt-1)/ans + 1;
				maxx = max(maxx,ans);
			}
			minn = min(minn,maxx);
		}
	}
	if(minn == INT_MAX)
		cout << -1 << endl;
	else
		cout << minn << endl;
	return 0;
}
