#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string s;
string word[10];
int n,m;
int dp[205][50],sum[205][205];

bool check(int l,int r){
    string x = s.substr(l,r-l+1);
    for(ri i = 1;i <= n;i ++)
		if(x.find(word[i]) == 0)
			return true;
    return false;
}

int main(){
	ios::sync_with_stdio(false);
	int p,k;
	cin >> p >> k;
	s += '0';
	string temp;
	for(ri i = 1;i <= p;i ++)
		cin >> temp,s += temp;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> word[i];
	m = s.length()-1;
	for(ri i = m;i >= 1;i --)
    	for(ri j = i;j >= 1;j --){
        	sum[j][i] = sum[j+1][i];
        	if(check(j,i))
				sum[j][i] ++;
    	}
	dp[0][0] = 0;
    for(ri i = 1;i <= k;i ++)
		dp[i][i] = dp[i-1][i-1]+sum[i][i];
    for(ri i = 1;i <= m;i ++)
		dp[i][1] = sum[1][i];
    for(ri i = 1;i <= m;i ++)
    	for(ri j = 1;j <= k && j < i;j ++)
    		for(ri l = j;l < i;l ++)
    			dp[i][j] = max(dp[i][j],dp[l][j-1]+sum[l+1][i]);
    cout << dp[m][k] << endl;
	return 0;
}
