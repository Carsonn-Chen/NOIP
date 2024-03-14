#include <bits/stdc++.h>

using namespace std;

int seat[1005][1005] = {0};

int main(){
	ios::sync_with_stdio(false);
	int m,n,k,l,d;
	cin >> m >> n >> k >> l >> d;
	int xi,yi,pi,qi;
	for(int i = 1;i <= d;i ++){
		cin >> xi >> yi >> pi >> qi;
		seat[xi][yi] = seat[pi][qi] = i;
	}
	
}
