#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int a,b,l,aa,bb;

int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b >> l;
	double last = 1e9;
	for(ri i = 1;i <= l;i ++)
		for(ri j = 1;j <= l;j ++)
			if(__gcd(i,j) == 1 && i * b >= a * j){
				if((double)((double)i / (double)j) - (double)((double)a / (double)b) < last){
					last = (double)((double)i / (double)j) - (double)((double)a / (double)b);
					aa = i;
					bb = j;
				}
			}
	cout << aa << " " << bb;
	return 0;
}
