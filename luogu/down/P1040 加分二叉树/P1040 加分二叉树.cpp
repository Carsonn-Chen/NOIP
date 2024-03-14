#include<bits/stdc++.h>

using namespace std;

int n;
int a[10005];
int f[105][10005];
int root[105][10005];

void fx(int l,int r)
{
    if(l > r)												//递归边界
    	return ;
    cout << root[l][r]<<" ";								//输出根节点
    fx(l,root[l][r]-1);										//左子树递归
    fx(root[l][r]+1,r);										//右子树递归
}

int dfs(int L,int R)
{
    if(f[L][R] > 0)											//剪枝过程
    	return f[L][R];
    if(L == R){												//搜索结束
    	f[L][R] = a[L];
    	root[L][R] = L;										//记下当前的根节点
    }
    if(L > R)												//依题意，空子树加分为1
    	return 1;
    if(L < R)
    	for(int k = L;k <= R;k ++)							//枚举根的位置并记下最大值
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
