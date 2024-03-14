#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int main(){
	string s,s0;
	cin >> s;
	cout << s.size() << endl;
	do{
		s0 += s;
	}while(cin >> s);
	int cnt = 1;
	char e = s0[0];
	for(ri i = 1;i < (int)s0.size();i ++){
		if(e != s0[i]){
			cout << cnt << " ";
			cnt = 1;
		}
		else
			cnt ++;
	}
}
