#include<iostream>
#include<cstring>
#include<map>
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
int len,ans;
map<string,int> M;
bool pd(string s)
{
	if(!(len&1)) return false;
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(') cnt++;
		else cnt--;
	}
	return cnt;
}
bool check(string s)
{
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(') cnt++;
		else
		{
			if(!cnt) return false;
			cnt--;
		}
	}
	return !cnt;
}
void DFS(string s,int temp,int cur)
{
	if(temp>=ans||M.count(s)) return;
	else M[s]=1;
	if(check(s))
	{
		ans=MIN(ans,temp);
		return;
	}
	for(int i=cur;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			swap(s[i],s[j]);
			DFS(s,temp+1,i+1);
			swap(s[i],s[j]);
		}
	}
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	cin>>len>>s;
	ans=2147483647;
	if(len>10) cout<<-1<<endl;
	else
	{
		if(pd(s)) cout<<-1<<endl;
		else DFS(s,0,0),cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
