#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

/*string s[2] = {"abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ"};*/
string Key;
string in,ans;

void calc(char e,int i){
	if(in[i] >= 'a' && in[i] <= 'z'){
		if(e >= 'A' && e <= 'Z')
			e = e - 'A' + 'a';
		int cnt = in[i] - e;
		if(cnt < 0)
			cnt += 26;
		char ch = cnt + 'a';
		ans += ch;
	}else{
		if(e >= 'a' && e <= 'z')
			e = e - 'a' + 'A';
		int cnt = in[i] - e;
		if(cnt < 0)
			cnt += 26;
		char ch = cnt + 'A';
		ans += ch;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> Key >> in;
	int now = 0;
	int lenk = Key.size();
	for(ri i = 0;i < (int)in.size();i ++){
		if(now == lenk)
			now = 0;
		calc(Key[now++],i);
	}
	cout << ans;
	return 0;
}
