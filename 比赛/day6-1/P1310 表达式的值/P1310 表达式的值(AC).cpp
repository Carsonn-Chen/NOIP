#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <stack>
#define ri register int
#define mod 10007

using namespace std;

int f[2][100005];
stack<char>s;

int main(){
	ios::sync_with_stdio(false);
	int len;
	string c,te = ".";
	cin >> len >> c;
	for(ri i = 0;i < len;i ++) {
		if(c[i] == '('  ||  c[i] == '*')
			s.push(c[i]);
		if(c[i] == '+') {
			while(!s.empty() && s.top() == '*') {
				te += s.top();
				s.pop();
			}
			s.push('+');
		}
		if(c[i] == ')'){
			while(s.top() != '(') {
				te += s.top();
				s.pop();
			}
			s.pop();
		}
		if(c[i] != '(' && c[i] != ')')
			te += '.';
	}
	while(!s.empty()) {
		te += s.top();
		s.pop();
	}
	int j = 0;
	for(ri i = 0;i < (int)te.size();i ++) {
		if(te[i] == '.') {
			j ++;
			f[0][j] = 1;
			f[1][j] = 1;
		}
		if(te[i] == '*') {
			j --;
			f[0][j] = (f[0][j+1]*f[1][j] + f[0][j]*f[1][j+1] + f[0][j]*f[0][j+1]) % mod;
			f[1][j] = (f[1][j]*f[1][j+1]) % mod;
		}
		if(te[i] == '+') {
			j --;
			f[1][j] = (f[0][j]*f[1][j+1] + f[0][j+1]*f[1][j] + f[1][j]*f[1][j+1]) % mod;
			f[0][j] = (f[0][j] * f[0][j+1]) % mod;
		}
	}
	cout << f[0][j] << endl;
	return 0;
}
