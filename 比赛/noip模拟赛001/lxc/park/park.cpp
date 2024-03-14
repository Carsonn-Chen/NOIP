#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string a,b;

int main(){
	freopen("park4.in","r",stdin);
	freopen("park.out","w",stdout);
	ios::sync_with_stdio(false);
	while(cin >> a >> b){
		if(a.size() == 1 && a[0] == '#')
			break;
		int cnt = 0,pos = 0;
		while(a.find(b,pos) != std::string::npos){
			cnt ++;
			pos = a.find(b,pos) + b.size();
		}
		cout << cnt << endl;
	}
	return 0;
}
