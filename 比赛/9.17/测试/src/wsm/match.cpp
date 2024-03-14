#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
struct def
{
	int place;
	string s;
	def(int place,string s):place(place),s(s) {}
};
int n;
bool check(string s)
{
	int num=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') num++;
		else num--;
		if(num<0) return false;
	}
	return num==0?true:false;
}
char ch[100005]; 
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	string s;
	cin>>s;
	if(check(s))
	{
		cout<<0<<endl;
		return 0;
	}
	if(n%2)
	{
		cout<<-1<<endl;
		return 0;
	}
	int num=0;
	for(int i=0;i<n;i++) if(s[i]=='(') num++;
	if(num!=n/2)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int headd=1;
	int rail=1;
	if(n>10)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
			ch[rail++]='(';
			else if(ch[rail-1]=='(') rail--;
			else ch[rail++]=')';
		}
		string ss;
		for(int i=headd;i<rail;i++) ss=ss+ch[i];
		s=ss;//ÓÅ»¯s
//		cout<<s<<endl;
	}
	queue<def> q;
	map<string,int> m;
	m[s]=1;
	q.push(def(0,s));
//	cout<<s.length()<<endl;
	while(q.size())
	{
		def t=q.front();
		q.pop();
		for(int i=0;i<s.length();i++)
		{
			for(int j=0;j<s.length();j++)
			{
				if(s[i]==s[j]) continue;
				string ss=t.s;
				swap(ss[i],ss[j]);
				if(!m.count(ss))
				{
					m[ss]=1;
					q.push(def(t.place+1,ss));
					if(check(ss))
					{
						cout<<t.place+1<<endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
