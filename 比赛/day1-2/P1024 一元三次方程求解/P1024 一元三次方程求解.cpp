#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

double a,b,c,d;

double f(double x){
	return (a*x*x*x + b*x*x + c*x + d);
}

double calc(double x){
	double l = x,r = x + 1;
	while(r - l > 0.001){
		double mid = (l+r)/2;
		double k = f(mid);
		if(k == 0)
			return mid;
		if(k * f(r) < 0)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main(){
	cin >> a >> b >> c >> d;
	int cnt = 0;
	double i = -100;
	while(i < 100){
		if(f(i) == 0){
			printf("%.2lf ",i);
			cnt ++;
		}
		else if(f(i) * f(i+1) < 0){
			printf("%.2lf ",calc(i));
			cnt ++;
		}
		if(cnt == 3)
			break;
		i += 1;
	}
	return 0;
}
