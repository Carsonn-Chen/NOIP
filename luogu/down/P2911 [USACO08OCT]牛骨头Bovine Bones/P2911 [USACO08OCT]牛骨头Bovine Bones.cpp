#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int sum[100];

int main(){
	ios::sync_with_stdio(false);
	int s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	for(ri i = 1;i <= s1;i ++)
		for(ri j = 1;j <= s2;j ++)
			for(ri k = 1;k <= s3;k ++)
				sum[i+j+k] ++;
	cout << max_element(sum+3,sum+s1+s2+s3) - sum << endl;
}
