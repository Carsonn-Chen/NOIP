#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int Clock[10],cnt[10];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1;i <= 9;i ++){
		cin >> Clock[i];
		Clock[i] /= 3;
	}
	for(int a = 0;a <= 3;a ++)
		for(int b = 0;b <= 3;b ++)
			for(int c = 0;c <= 3;c ++)
				for(int d = 0;d <= 3;d ++)
					for(int e = 0;e <= 3;e ++)
						for(int f = 0;f <= 3;f ++)
							for(int g = 0;g <= 3;g ++)
								for(int h = 0;h <= 3;h ++)
									for(int i =0;i <= 3;i ++){
										if( (a+b+d+Clock[1])%4 == 0 && (a+b+c+e+Clock[2])%4 == 0 && (b+c+f+Clock[3])%4 == 0 && (a+d+e+g+Clock[4])%4 == 0 && (a+c+e+g+i+Clock[5])%4 == 0 && (c+e+f+i+Clock[6])%4 == 0 && (d+g+h+Clock[7])%4 == 0 && (e+g+h+i+Clock[8])%4 == 0 && (f+h+i+Clock[9])%4 == 0){
											cnt[1] = a;
											cnt[2] = b;
											cnt[3] = c;
											cnt[4] = d;
											cnt[5] = e;
											cnt[6] = f;
											cnt[7] = g;
											cnt[8] = h;
											cnt[9] = i;
											for(int i = 1;i <= 9;i ++)
												for(int j = 1;j <= cnt[i];j ++)
													cout << i << " ";
											return 0;
										}
									}
	return 0;
}
