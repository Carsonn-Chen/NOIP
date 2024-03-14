#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	else{
		int r = exgcd(b,a%b,x,y);
		int t = x - a / b * y;
		x = y; 
		y = t;
		return r;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	while(x < 0) 
		x = x + b;
	cout << x;
	return 0;
} 
