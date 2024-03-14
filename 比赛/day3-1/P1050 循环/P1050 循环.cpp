#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

string s;
int k;
int old[105],now[105];

void calc(){
	int result[205] = {0};
	for(ri i = 0; i < k; i++)
		for(ri j = 0; j < k; j++)
			result[i + j] += old[i] * now[j];
	for(ri i = 0; i < k; i++){
		result[i + 1] += result[i] / 10;
		result[i] %= 10;
	}
	for(ri i = 0;i < k;i ++)
		now[i] = result[i];
}

bool check(){
	for(ri i = 1;i < k;i ++)
		if(now[i] != old[i])
			return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> s >> k;
	for(ri i = 0,j = s.size()-1;i < k && j >= 0;i ++,j --)
		old[i] = now[i] = s[j] - '0';
	int cnt = 1;
	calc();
	while(check() && cnt <= 1000005){
		calc();
		cnt ++;
	}
	if(cnt > 100005)
		cout << "-1" << endl;
	else
		cout << cnt << endl;
	return 0;
}
