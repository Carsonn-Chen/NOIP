#include<bits/stdc++.h>

using namespace std;

int n;
int a[10005];
int f[105][10005];
int root[105][10005];

void fx(int l,int r)
{
    if(l > r)												//�ݹ�߽�
    	return ;
    cout << root[l][r]<<" ";								//������ڵ�
    fx(l,root[l][r]-1);										//�������ݹ�
    fx(root[l][r]+1,r);										//�������ݹ�
}

int dfs(int L,int R)
{
    if(f[L][R] > 0)											//��֦����
    	return f[L][R];
    if(L == R){												//��������
    	f[L][R] = a[L];
    	root[L][R] = L;										//���µ�ǰ�ĸ��ڵ�
    }
    if(L > R)												//�����⣬�������ӷ�Ϊ1
    	return 1;
    if(L < R)
    	for(int k = L;k <= R;k ++)							//ö�ٸ���λ�ò��������ֵ
    		if(f[L][R] < dfs(L,k-1)*dfs(k+1,R)+a[k]){
		        f[L][R] = dfs(L,k-1)*dfs(k+1,R)+a[k];
		        root[L][R] = k;
    		}
    return f[L][R];
} 

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i ++)
    cin >> a[i];
    cout << dfs(1,n) << endl;
    fx(1,n);
} 
