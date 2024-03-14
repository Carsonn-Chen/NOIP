#include <bits/stdc++.h>

using namespace std;

string s[25];

bool cmp(string a,string b){
	return a+b > b+a;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> s[i];
	sort(s+1,s+1+n,cmp);
	string ans = "";
	for(int i = 1;i <= n;i ++)
		ans += s[i];
	cout << ans << endl;
	return 0;
}
