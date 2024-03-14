#include <bits/stdc++.h>

using namespace std;

int num[40005],temp[40005];
int ans = 0;

void solve(int begin,int end){
	if(end-begin > 1){
		int m = (begin+end)/2;
		int p = begin,q = m,i = begin;
		solve(begin,m);
		solve(m,end);
		while(p < m || q < end){
			if(q >= end || (p < m && num[p] < num[q]))
				temp[i++] = num[p++];
			else{
				temp[i++] = num[q++];
				ans += m-p;
			}
		}
		for(i = begin;i < end;i ++)
			num[i] = temp[i];
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> num[i];
	solve(1,n+1);
	cout << ans << endl;
}
