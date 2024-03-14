#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#define ri register int

using namespace std;

map<char,int> a;
map<char,int> total;
char le[10];
string x,y;

int main() {
	int n;
	cin >> n;
	cin >> x;
	for(ri i = 1;i <= n-1;i ++) {
		cin >> x;
		le[i] = x[0];
	}
	for(ri i = 1;i <= n-1;i ++)
		for(ri j = 1;j <= n;j ++) {
			cin >> x;
			if(x == y && j != 1 && j != 2){
				cout << "ERROR!";
				return 0;
			}
			y = x;
			if(x.size() == 2) {
				a[x[1]] ++;
				total[le[i]] ++;
			}
		}
	for(ri i = 1;i <= n-1;i ++)
		if(total[le[i]] != n-2-a[le[i]]) {
			cout << "ERROR!";
			return 0;
		}
	for(ri i = 1;i <= n-1;i ++)
		cout << le[i] << '=' << total[le[i]] << ' ';
	cout << endl << n-1;
	return 0;
}
