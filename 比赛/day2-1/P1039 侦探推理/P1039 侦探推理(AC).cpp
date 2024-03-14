#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <algorithm>
#define ri register int

using namespace std;

string S[10]= {
	"Today is Sunday.",
	"Today is Monday.",
	"Today is Tuesday.",
	"Today is Wednesday.",
	"Today is Thursday.",
	"Today is Friday.",
	"Today is Saturday.",
};

int m,n,p;
int T,F,ans;
int TF[25];
string s[25],name,a;
struct Sen {
	int id;
	string s;
} sen[105];
map<string,int> ma;

bool judgeTF(int id,bool flag) { //看一下有没有冲突，return 1 表示有冲突
	if(TF[id] == -1) {    //状态不确定
		TF[id] = flag;    //赋状态
		if(flag)    //说真话的人数++
			T ++;
		else    //说假话的人数++
			F ++;
	}
	else
		return TF[id] != flag;    //和之前的一不一样，一样返回0，不一样返回1
	if(F > n || T > m-n)  //说假话的人比n多或者是说真话的人比m-n多
		return 1;
	return 0;
}

void judge(int id,string day) {
	memset(TF,-1,sizeof(TF));   //所有人都不知道说的是真话假话
	T = F = 0;      //说真话、假话人数置0
	string tmp;
	for(ri i = 1;i <= p;i ++) {
		int pos = sen[i].s.find("I am guilty.");  //pos为-1则没说这句话
		if(~pos){
			if(judgeTF(sen[i].id,sen[i].id == id))    //因为我们假设了id是罪犯，所以不是id的人就不是罪犯，就是在说假话
				return;
		}
		pos=sen[i].s.find("I am not guilty");
		if(~pos) {
			if(judgeTF(sen[i].id,sen[i].id!=id))
				return;
		}
		pos = sen[i].s.find(" is guilty.");
		if(~pos) {
			tmp = sen[i].s;
			tmp.erase(pos,11);
			if(judgeTF(sen[i].id,ma[tmp] == id))
				return;
		}
		pos = sen[i].s.find(" is not guilty.");
		if(~pos){
			tmp = sen[i].s;
			tmp.erase(pos,15);
			if(judgeTF(sen[i].id,ma[tmp]!=id))
				return;
		}
		pos = sen[i].s.find("Today is ");
		if(~pos){
			if(judgeTF(sen[i].id,sen[i].s==day))
				return;
		}
	}
	if(ans && ans != id) {  //找到了不止一个罪犯
		puts("Cannot Determine");   //不能确定
		exit(0);
	}
	ans = id;     //id是罪犯
}

int main() {
	scanf("%d%d%d",&m,&n,&p);
	for(ri i = 1;i <= m;i ++) {
		cin >> s[i];
		ma[s[i]] = i;     //存名字标号
	}
	for(ri i = 1;i <= p;i ++) {
		cin >> name;      //输入说话者
		name.erase(name.length()-1,1);      //把后边的冒号搞掉
		getline(cin,a);
		a.erase(0,1);   //把前边的空格搞掉
		if(a[a.length()-1] == '\n' || a[a.length()-1] == '\r')    //把坑爹的换行符搞掉
			a.erase(a.length()-1,1);
		sen[i].id = ma[name];     //存说话者
		sen[i].s = a;     //存说话内容
	}
	for(ri i = 1;i <= m;i ++) //假设第i个人是罪犯
		for(ri j = 0;j < 7;j ++)  //假设今天是S[j]天
			judge(i,S[j]);
	if(!ans)    //找不到罪犯
		puts("Impossible");
	else
		cout<<s[ans] << endl;   //罪犯名字
	return 0;
}
