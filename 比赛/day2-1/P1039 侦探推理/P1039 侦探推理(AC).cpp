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

bool judgeTF(int id,bool flag) { //��һ����û�г�ͻ��return 1 ��ʾ�г�ͻ
	if(TF[id] == -1) {    //״̬��ȷ��
		TF[id] = flag;    //��״̬
		if(flag)    //˵�滰������++
			T ++;
		else    //˵�ٻ�������++
			F ++;
	}
	else
		return TF[id] != flag;    //��֮ǰ��һ��һ����һ������0����һ������1
	if(F > n || T > m-n)  //˵�ٻ����˱�n�������˵�滰���˱�m-n��
		return 1;
	return 0;
}

void judge(int id,string day) {
	memset(TF,-1,sizeof(TF));   //�����˶���֪��˵�����滰�ٻ�
	T = F = 0;      //˵�滰���ٻ�������0
	string tmp;
	for(ri i = 1;i <= p;i ++) {
		int pos = sen[i].s.find("I am guilty.");  //posΪ-1��û˵��仰
		if(~pos){
			if(judgeTF(sen[i].id,sen[i].id == id))    //��Ϊ���Ǽ�����id���ﷸ�����Բ���id���˾Ͳ����ﷸ��������˵�ٻ�
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
	if(ans && ans != id) {  //�ҵ��˲�ֹһ���ﷸ
		puts("Cannot Determine");   //����ȷ��
		exit(0);
	}
	ans = id;     //id���ﷸ
}

int main() {
	scanf("%d%d%d",&m,&n,&p);
	for(ri i = 1;i <= m;i ++) {
		cin >> s[i];
		ma[s[i]] = i;     //�����ֱ��
	}
	for(ri i = 1;i <= p;i ++) {
		cin >> name;      //����˵����
		name.erase(name.length()-1,1);      //�Ѻ�ߵ�ð�Ÿ��
		getline(cin,a);
		a.erase(0,1);   //��ǰ�ߵĿո���
		if(a[a.length()-1] == '\n' || a[a.length()-1] == '\r')    //�ѿӵ��Ļ��з����
			a.erase(a.length()-1,1);
		sen[i].id = ma[name];     //��˵����
		sen[i].s = a;     //��˵������
	}
	for(ri i = 1;i <= m;i ++) //�����i�������ﷸ
		for(ri j = 0;j < 7;j ++)  //���������S[j]��
			judge(i,S[j]);
	if(!ans)    //�Ҳ����ﷸ
		puts("Impossible");
	else
		cout<<s[ans] << endl;   //�ﷸ����
	return 0;
}
