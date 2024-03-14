#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define ri register int

using namespace std;

map<char,vector<char> >m;
string s;
int k,l,c[15],ans[105];

void dfs(char e) {
	c[e-'0'] = 1;
	for(ri i = 0; i < (int)m[e].size(); i++)
		if(!c[m[e][i]-'0'])
			dfs(m[e][i]);
}

int main() {
	cin >> s >> k;
	for(ri i = 1; i <= k; i ++) {
		char x,y;
		cin >> x >> y;
		m[x].push_back(y);
	}
	ans[0] = 1;
	for(ri i = 0; i < (int)s.size(); i ++){
		memset(c,0,sizeof(c));
		dfs(s[i]);
		int sum = 0;
		for(ri i = 0; i <= 9; i ++)
			sum += c[i];
		int x = 0;
		for(ri i = 0; i <= 100; i ++) {
			ans[i] = ans[i]*sum+x;
			x = ans[i]/10;
			ans[i] %= 10;
		}
	}
	int i = 100;
	while(i > 0 && !ans[i])
		i --;
	for(; i >= 0; i --)
		cout << ans[i];
	return 0;
}
