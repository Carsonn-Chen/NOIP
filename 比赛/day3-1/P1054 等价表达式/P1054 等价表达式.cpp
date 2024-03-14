#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string z = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s,ss;
int n;
int sums;

bool check(){
	int sumss = 0;
	int flag = 1;
	for(ri i = 0;i < (int)ss.size();i += 1){
		if(ss[i] == 'a')
			sumss += flag*8,i ++;
		else{
			int num = 0,cnt = 1;
			while(isdigit(ss[i]))
				i ++;
			int j = i - 1;
			while(isdigit(ss[j])){
				num += (ss[j]-'0') * cnt;
				cnt *= 10;
				j --;
			}
			sumss += num*flag;
		}
		while(ss[i] == ' ')
			i ++;
		if(ss[i] == '-')
			flag = -1;
		else
			flag = 1;
	}
	if(sumss == sums)
		return true;
	else
		return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> s >> n;
	int flag = 1;
	for(ri i = 0;i < (int)s.size();i += 1){
		if(s[i] == 'a')
			sums += flag*8,i ++;
		else{
			int num = 0,cnt = 1;
			while(isdigit(s[i]))
				i ++;
			int j = i - 1;
			while(isdigit(s[j])){
				num += (s[j]-'0') * cnt;
				cnt *= 10;
				j --;
			}
			sums += num*flag;
		}
		while(s[i] == ' ')
			i ++;
		if(s[i] == '-')
			flag = -1;
		else
			flag = 1;
	}
	for(ri i = 1;i <= n;i ++){
		cin >> ss;
		if(check())
			cout << z[i];
	}
	return 0;
}
