#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int gcd(int x,int y){
	if(x < y)
		swap(x,y);
	if(y == 0)
		return x;
	if(x & 1){
		if(y & 1)
			return gcd((x-y) >> 1,y);
		else
			return gcd(x,y >> 1);
	}else{
		if(y & 1)
			return gcd(x >> 1,y);
		else
			return gcd(x >> 1,y >> 1) << 1;
	}
}

int main(){
	int x,y;
	cin >> x >> y;
	cout << gcd(x,y) << endl;
	return 0;
}
