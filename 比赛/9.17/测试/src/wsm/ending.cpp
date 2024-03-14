#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#define INF 1e+9
using namespace std;
int A[15],B[15];
int M,N,HP;
bool find(int x)
{
	int ans=INF,order=INF;
	for(int i=0;i<(1<<N);i++)
	{
		int sum=0;
		for(int j=0;j<N;j++)
		{
			if( (1<<j) & i)
			sum+=B[j];
		}
		if(sum>=x&&sum-x<ans)
		{
			ans=sum-x;
			order=i;
		}
	}
	if(ans==INF) return false;
	for(int j=0;j<N;j++)
	{
		if((1<<j)&order)
		{
			B[j]=0;
		}
	}
	return true;
}
int main()
{
	freopen("ending.in","r",stdin);
	freopen("ending.out","w",stdout);
	cin>>M>>N>>HP;
	for(int i=0;i<M;i++)
	cin>>A[i];
	for(int i=0;i<N;i++)
	cin>>B[i];
	for(int i=0;i<M;i++)
	{
		if(!find(A[i]))
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	int sum=0;
	for(int i=0;i<N;i++) sum+=B[i];
	printf("%s\n",sum>=HP?"Yes":"No");
	return 0;
} 
