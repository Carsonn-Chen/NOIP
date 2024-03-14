#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <stack>
#define ri register int

using namespace std;

int n;
bool tag = 1;
int num[1005];
int s1[1005],s2[1005];
int top1,top2;
char ans[3005];

bool check(int k){
	if(!top2)
		return 1;
	int i,j;
	for(i = k + 1;i <= n;i ++)
		if(num[i] > num[k] && s2[top2] < num[i])
			break;
	for(j = i + 1;j <= n;j ++)
		if(num[k] > num[j])
			return 0;
	return 1;		
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> num[i];
	int now = 1;
	int pos = 0;
	int at = 1;
	s1[0] = s2[0] = INT_MAX;
	for(ri i = 1;i <= 2*n;i ++){
		if(s1[top1] == now){
			top1 --;
			now ++;
			ans[++pos] = 'b';
			continue;
		}
		if(s2[top2] == now){
			top2 --;
			now ++;
			ans[++pos] = 'd';
			continue;
		}
		if(at <= n && s1[top1] > num[at] && check(at)){
			s1[++top1] = num[at++];
			ans[++pos] = 'a';
			continue;
		}
		if(at <= n && s2[top2] > num[at]){
			s2[++top2] = num[at++];
			ans[++pos] = 'c';
			continue;
		}
		tag = 0;
		break;
	}
	if(tag == 0)
		cout << 0 << endl;
	else
		for(ri i = 1;i <= pos;i ++)
			cout << ans[i] << " ";
	return 0;
}
