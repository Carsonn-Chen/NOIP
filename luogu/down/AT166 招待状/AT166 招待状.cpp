#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int month[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
	int m1,d1,m2,d2;
	cin >> m1 >> d1 >> m2 >> d2;
	int ans = 0;
	while(m1 != m2){
		 ans += month[m1];
		 m1 ++;
	}
	ans += (d2-d1);
	cout << ans << endl;
	return 0;
}
