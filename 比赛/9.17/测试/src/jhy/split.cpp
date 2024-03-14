#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define maxn 2000
using namespace std;
int n,l,r,ans,a[maxn];
int yhz[maxn][maxn];
vector<int> v;
void dfs (int st,int k) {
	if(k == 1){ 
		v.push_back(yhz[st][n]);
		int tmp = -1;
		for (int i = 0; i < v.size(); i ++) {
			tmp = tmp & v[i];
		}
		ans = max(ans,tmp);
		v.pop_back();
		return;
	}
	for (int i = st; i <= n; i ++) {
		v.push_back(yhz[st][i]);
		dfs(i + 1,--k);
		v.pop_back(); k ++;
	}
}
int main(){
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i ++) { cin >> a[i]; yhz[i][i] = a[i]; }
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			yhz[i][j] = yhz[i][j - 1] ^ a[j];
		}
	}
	for (int i = l; i <= r; i ++) {
		v.clear();
		dfs(1,i);
	} cout << ans << endl;
	return 0;
}
