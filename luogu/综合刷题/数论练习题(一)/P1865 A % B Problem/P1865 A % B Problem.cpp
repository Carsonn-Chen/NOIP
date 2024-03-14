#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int cnt[1000005];
int vis[1000005];
int sum;

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	int l,r;
	cin >> n >> m;
	cnt[1] = 0;
    vis[1] = 1;
    for(ri i = 2;i <= m;i ++){
        if(!vis[i]){
            cnt[i] = cnt[i-1]+1;
            for(ri j = i+i;j <= m;j += i)
                vis[j] = 1;
        }
        else 
			cnt[i] = cnt[i-1];
    }
	while(n --){
		cin >> l >> r;
		if(l < 1 || r > m){
			cout << "Crossing the line" << endl;
			continue;
		}
		cout << cnt[r] - cnt[l-1] << endl;
	}
	return 0;
}
