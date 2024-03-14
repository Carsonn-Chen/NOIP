#include <bits/stdc++.h>
#define mod 10007

using namespace std;

vector<int>m[200020];
long long v[200020];
long long sum;
long long Max;

int main(){
	int n;
	scanf("%d",&n);
	int x,y;
	for(int i = 1;i < n;i ++){
		scanf("%d%d",&x,&y);
		m[x].push_back(y);
		m[y].push_back(x);
	}
	for(int i = 1;i <= n;i ++)
		scanf("%lld",&v[i]);
	for(int x = 1;x <= n;x ++){
		long long s1 = 0, s2 = 0, Max1 = 0, Max2 = 0;
	    for(int i = 0; i < (int)m[x].size(); i ++) {
	        s1 = (s1 + v[m[x][i]]) % mod;
	        s2 = (s2 + (v[m[x][i]] % mod) * (v[m[x][i]] % mod)) % mod;
	        if(v[m[x][i]] > Max1){ 
				Max2 = Max1; 
				Max1 = v[m[x][i]]; 
			}
	        else if(v[m[x][i]] > Max2) 
				Max2 = v[m[x][i]];
	    }
	    sum = (sum + (s1 * s1 % mod - s2 + mod)) % mod;
	    Max = max (Max, Max1 * Max2);
	} 
	printf("%lld %lld\n",Max,sum);
	return 0;
}
