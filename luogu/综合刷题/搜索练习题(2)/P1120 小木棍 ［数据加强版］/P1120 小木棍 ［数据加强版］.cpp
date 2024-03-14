#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int N;
int L[55];
int sum,Max,Min = 2147483647;
bool tag;
int ans;

void Dfs(int rest,int sum,int need,int maxx){//还需要拼凑得到的木棍数量;当前已经拼凑得到的木棍的长度;需要得到的木棍的长度;当前可以使用的最长木棍的长度
	if(tag)
		return;
	if(rest == 0){
		tag = 1;
		ans = need;
		return;
	}
	if(sum == need){
		Dfs(rest - 1,0,need,Max);
		return;
	}
	for(ri i = maxx;i >= Min;i --){
		if(L[i] && i+sum <= need){
			L[i] --;
            Dfs(rest,sum+i,need,i);
            L[i] ++;
            if(sum == 0 || sum+i == need)
                return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	for(ri i = 1;i <= N;i ++){
		int tmp;
		cin >> tmp;
		if(tmp <= 50){
			L[tmp] += 1;
			Max = max(Max,tmp);
			Min = min(Min,tmp);
			sum += tmp;
		}
	}
	int end = sum / 2;
	for(ri i = Max;i <= end;i ++)
		if(sum%i == 0)
			Dfs(sum/i,0,i,Max);
	if(tag)
		printf("%d\n",ans);
	else
		printf("%d\n",sum);
	return 0;
}
