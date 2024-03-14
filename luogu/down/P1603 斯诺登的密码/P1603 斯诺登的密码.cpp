#include <bits/stdc++.h>

using namespace std;

string num[25] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
string num2[3] = {"a","both","another"};
string num3[3] = {"first","second","third"};
string s[6];
int e;
string temp1,temp2;

void myin(){
	for(int i = 0;i <= 5;i++){
		e = 0;
		cin >> s[i];
		for(int j = 0;j < s[i].length();j ++)
			if(s[i][j] <= 'Z')
				s[i][j] += 32;
		for(int j = 0;j <= 20;j ++)
			if(s[i] == num[j]){
				e = j;
				break;
			}
		for(int j = 0;j <3;j ++)
			if(s[i] == num2[j]){
				e = j+1;
				break;
			}
		for(int j = 0;j <3;j ++)
			if(s[i] == num3[j]){
				e = j+1;
				break;
			}
			
				
		e = e * e % 100;
		if(e == 0)
			s[i] = "0";
		else if(e <= 9){
			temp1 = "0";
			temp2 = char(e + 48);
			s[i] = temp1 + temp2;
		}
		else{
			temp1 = char(e/10 + 48);
			temp2 = char(e%10 + 48);
			s[i] = temp1 + temp2;
		}
	}
}

int main(){
	string ans;
	myin();
	sort(s,s+6);
	ans = s[0];
	for(int i = 1;i < 6;i ++)
		ans += s[i];
	bool pd = 1;
	for(int i = 0;i < ans.length();i ++)
		if(ans[i] == '0' && pd == 1)
			continue;
		else{
			cout << ans[i];
			pd = 0;
		}
	if(pd == 1)
		cout << "0";
	return 0;
}
