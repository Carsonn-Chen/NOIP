#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

string s;
stack<char>l;

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,ans;
	scanf("%d",&n);
	if(n%2 != 0)
		printf("-1\n");
	else{
		cin >> s;
		int lcnt = 0,rcnt = 0;
		for(int i = 0;i < s.length();i ++){
			if(s[i] == ('(')){
				l.push('(');
				lcnt ++;
			}
			else{
				rcnt ++;
				if(!l.empty())
					l.pop();
			}
		}
		if(lcnt != rcnt){
			printf("-1\n");
			return 0;
		}else{
			ans = l.size();
			ans += 1;
			ans /= 2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
