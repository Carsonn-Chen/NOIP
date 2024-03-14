#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ri register int
#define maxn 100005
#define maxt 86400

using namespace std;

int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

void write(int x){
	if(x > 9)
		write(x/10);
	putchar(x%10 + '0');
}

int n;
int cnt[maxn][2],t[maxn];
vector<int>peo[maxn];

int main(){
	n = read();
	int k;
	for(ri i = 1;i <= n;i ++){
		cnt[i][0] = read();
		k = read();
		for(ri j = 1;j <= k;j ++)
			peo[i].push_back(read());
	}
	for(ri i = 1;i <= n;i ++){
		set<int>ans;
		for(ri j = i;j >= 1;j --){
			if(cnt[i][0] - cnt[j][0] >= maxt)
				break;
			for(ri k = 0;k < (int)peo[j].size();k ++)
				ans.insert(peo[j][k]);
		}
		write(ans.size());
		putchar('\n');
	}
	return 0;
}
