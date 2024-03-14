#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int num[200];

int calc(int x){
	int sum = 1;
	while(x != 1)
		sum *= x,x --;
	return sum;
}

int main(){
	//freopen("num.in","r",stdin);
	//freopen("num.out","w",stdout);
	int a,b;
	cin >> a >> b;
	for(ri i = 1;i <= a;i ++)
		num[i] = i;
	int ans = 0;
	int cnt = 0;
	for(ri i = 1;i <= calc(a);i ++){
		cnt = 0;
		for(ri i = 1;i <= a-1;i ++)
			if(num[i] < num[i+1])
				cnt ++;
		if(cnt == b){
			ans ++;
			/*for(ri i = 1;i <= a;i ++)
				cout << num[i] << " ";
			cout << endl;*/
		}
		next_permutation(num,num+1+a);
	}
	cout << ans ;
	return 0;
}
