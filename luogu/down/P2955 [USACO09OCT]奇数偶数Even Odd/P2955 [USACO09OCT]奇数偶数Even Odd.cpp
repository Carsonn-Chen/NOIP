#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++){
		string a;
		cin >> a;
		if((a[a.size()-1] - '0') % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}
}
