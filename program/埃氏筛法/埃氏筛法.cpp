#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <bitset>
#define ri register int

using namespace std;

bitset<10000000005>vis;

bool isprime(int x){
	if(x == 2 || x == 3)
		return 1;
	if(x % 6 != 1 && x % 6 != 5)
		return 0;
	for(ri i = 5;i <= sqrt(x+0.5);i += 6)
		if(x % i == 0 || x % (i+2) == 0)
			return 0;
	return 1;
}

int main(){
	int n;
	cin >> n;
	/*if(isprime(n))
		cout << 1;
	else
		cout << 0;*/
		
	int m = sqrt(n+0.5);
	vis[1] = 1;
	for(ri i = 2;i <= m;i ++)
		if(!vis[i])
			for(ri j = i*i;j <= n;j += i)
				vis[j] = 1;
	for(ri i = 1;i <= n;i ++)
		if(!vis[i])
			cout << i << " ";

	return 0;
}
