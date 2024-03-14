#include <bits/stdc++.h>

using namespace std;

struct node{
	char i;
	string x,y;
};

stack<node>s;
bool alph[30];					//标记变量字母的使用情况 

int main(){
	freopen("complexity5.in","r",stdin);
	freopen("complexity.ans","w",stdout);

	int T,n,e,cnt,cnt1;
	string fzd;
	node temp;				
	char fe;					//读取F或E 
	bool zt;					//标记判断的状态 

	cin >> T;
	while(T --){
		zt = 1;
		cnt = 0;
		memset(alph,0,sizeof(alph));

		cin >> n >> fzd;
		if(n%2 != 0)
			zt = 0;
		if(fzd[2] == '1')
			e = 0;
		else
			e = (fzd[4]-'0');

			while(n--){
				cin >> fe;
				if(fe == 'F' && zt){
					cin >> temp.i >> temp.x >> temp.y;
					if(alph[temp.i -'a'])
						zt = 0;
					alph[temp.i -'a'] = 1;
					s.push(temp);
					if(s.empty())
						cnt1 = 0;
				}
				else if(zt){
					temp = s.top();
					s.pop();
					alph[temp.i -'a'] = 0;
					if(temp.x[0] == 'n'){
						if(temp.y[0] != 'n')
							cnt1 = 0;
					}
					else{
						if(temp.y[0] == 'n')
							cnt1 ++;
						else{
							if(temp.x.size() > temp.y.size())
								cnt1 = 0;
							else if(temp.x.size() == temp.y.size()){
								bool dx = 1;
								for(int m = 0;m < temp.x.size();m++)
									if(temp.x[m] < temp.y[m])
										dx = 0;
								if(dx)
									cnt1 = 0;
							}
								
						}
					}
					if(cnt1)
						cnt = max(cnt,cnt1);
					else
						cnt = 0;	
				}
			}
		if(zt == 0)
			printf("ERR\n");
		else{
			if(cnt == e)
				printf("Yes\n");
			else
				printf("No\n");
		}
		while(!s.empty())
			s.pop();
	}
	return 0;
}
