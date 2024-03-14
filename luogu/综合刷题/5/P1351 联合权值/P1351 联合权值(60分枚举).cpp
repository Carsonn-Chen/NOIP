#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define mod 10007

using namespace std;

vector<int>m[2000005];
int v[2000005];
long long ans;
long long Max;

int main(){
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i = 1;i < n;i ++){
        scanf("%d%d",&x,&y);
        m[x].push_back(y);
        m[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++)
        scanf("%d",&v[i]);
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < (int)m[i].size();j ++)
            for(int k = 0;k < (int)m[i].size();k ++){
                if(k == j)
                    continue;
                Max = max(Max,(long long)v[m[i][j]]*v[m[i][k]]);
                ans = (ans + v[m[i][j]]*v[m[i][k]])%mod;
            }
    printf("%lld %lld\n",Max,ans);
    return 0;
}
