#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string a[5] = {"0123456789","abcdefghijklmnopqrstuvwxyz","ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
string s;
int pos[105];
int p1,p2,p3;

int main(){
	memset(pos,-1,sizeof(pos));
	ios::sync_with_stdio(false);
	cin >> p1 >> p2 >> p3;
	cin >> s;
	int cnt = 0;
	for(ri i = 0;i < (int)s.size();i ++)
		if(s[i] == '-')
			if((isdigit(s[i-1]) && isdigit(s[i+1])) || ((s[i-1] <= 'z' && s[i-1] >= 'a') && (s[i+1] <= 'z' && s[i+1] >= 'a')) || ((s[i-1] <= 'Z' && s[i-1] >= 'A') && (s[i+1] <= 'Z' && s[i+1] >= 'A')))
				if(s[i-1] < s[i+1])
					pos[++cnt] = i-1;
	cnt = 1;
	for(ri i = 0;i < (int)s.size();i ++){
		if(pos[cnt] != i)
			cout << s[i];
		else{
			int l,r;
			cnt ++;
			cout << s[i];
			if(p1 == 3){
				l = s[i] + 1;
				r = s[i+2] - 1;
				while(l <= r){
					for(ri j = 1;j <= p2;j ++)
						cout << '*';
					l ++;
				}
			}
			else{
				if(p3 == 1){
						if(isdigit(s[i])){
							l = s[i] - '0' + 1;
							r = s[i+2] - '0' - 1;
							while(l <= r){
								for(ri j = 1;j <= p2;j ++)
									cout << a[0][l];
								l ++;
							}
						}
						else{
							l = s[i] - 'a' + 1;
							r = s[i+2] - 'a' - 1;
							while(l <= r){
								for(ri j = 1;j <= p2;j ++)
									cout << a[p1][l];
								l ++;
							}
						}
				}
				else if(p3 == 2){
						if(isdigit(s[i])){
							l = s[i] - '0' + 1;
							r = s[i+2] - '0' - 1;
							while(l <= r){
								for(ri j = 1;j <= p2;j ++)
									cout << a[0][r];
								r --;
							}
						}
						else{
							l = s[i] - 'a' + 1;
							r = s[i+2] - 'a' - 1;
							while(l <= r){
								for(ri j = 1;j <= p2;j ++)
									cout << a[p1][r];
								r --;
							}
						}
				}
			}
			i ++;
		}
	}
	return 0;
}
