#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

bool check(int x){
	char t[10];
	for(ri i = 7;i >= 0;i --){
		t[i] = x%10 + '0';
		x /= 10;
	}
	for(ri i = 0,j = 7;i <= j;i ++,j --)
		if(t[i] != t[j])
			return false;
	return true;
}

int main(){
	int d1,d2;
	scanf("%d%d",&d1,&d2);
	int ans = 0;
	while(d1 <= d2){
		if(check(d1))
			ans ++;
		int t1 = d1%100;
		d1 /= 100;
		int t2 = d1%100;
		d1 /= 100;
		int t3 = d1;
		if(t2 == 1 || t2 ==3 || t2 == 5 || t2 == 7 || t2 == 8 || t2 == 10 || t2 == 12){
			if(t1 == 31)
				t1 = 1,t2 ++;
			else
				t1 ++;
		}else if(t2 == 2){
			if((t3 % 4 == 0 && t3 % 100 != 0) || (t3 % 400) == 0){
				if(t1 == 29)
					t1 = 1,t2 ++;
				else
					t1 ++;
			}
			else{
				if(t1 == 29)
					t1 = 1,t2 ++;
				else
					t1 ++;
			}
		}else{
			if(t1 == 30)
				t1 = 1,t2 ++;
			else
				t1 ++;
		}
		if(t2 > 12)
			t2 = 1,t3 ++;
		d1 = t3*10000 + t2*100 + t1;
	}
	printf("%d",ans);
	return 0;
}
