#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n; string s;
	cin >> n >> s;
	if(n % 2) { cout << "-1" << endl; return 0; }
	if(n == 2 && s[0] != s[1]){
		if(s[0] == ')' && s[1] == '(') cout << "1" << endl;
		else cout << "0" << endl;
	}
	else cout << "-1" << endl;
	return 0;
}
