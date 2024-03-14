#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#define ri register int

using namespace std;

int a[12000],b[12000];
int lx,ly,rx,ry,p,n,py;
int X;
double Min,Max;

int main() {
	ios::sync_with_stdio(false);
	cin >> p;
	n = 1;
	cin >> a[1] >> b[1];
	while (true){
		cin >> rx >> ry;
		if(rx == -1 && ry == -1)
			break;
		lx = a[n];
		ly = b[n];
		for(ri i = lx+1;i <= rx;i ++){
			n ++;
			a[n] = a[n-1]+1;
			b[n] = b[n-1]+(ry-ly)/(rx-lx);
		}
	}
	cin >> X;
	if(p >= a[n]){
		lx = a[n];
		ly = b[n];
		for(ri i = lx+1;i <= p+1;i ++) {
			n ++;
			a[n] = a[n-1]+1;
			b[n] = b[n-1]-X;
		}
	}
	for(ri i = 1;i <= n;i ++) {
		if (a[i] == p) {
			py = b[i];
			break;
		}
	}
	Min=-233333333.0;
	Max=23333333.0;
	for(ri i = 1;i <= n;i ++) {
		if(py-b[i] > 0) {
			Min = max(Min,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*py)/(double)(py-b[i]));
		} 
		else{
			Max = min(Max,(double)((double)(a[i]-a[1])*b[i]-(double)(p-a[1])*py)/(double)(py-b[i]));
		}
	}
	if(Min > Max)
		printf("NO SOLUTION\n");
	else{
		if (Min>0) 
			printf("%.0lf",ceil(Min));
		else{
			if (Max<0) 
				printf("%.0lf",floor(Max));
			else
				printf("0");
		}
	}
	return 0;
}
