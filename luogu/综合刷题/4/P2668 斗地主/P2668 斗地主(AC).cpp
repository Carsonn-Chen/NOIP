#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T,ans,n,paizhu[5],have[16],num[5]={0,5,3,2};				//have记录手牌，paizhu记录手牌中的组成
 
void dfs(int now){
    if(now > ans) 
		return;
    memset(paizhu,0,sizeof(paizhu));
    for(int i = 0;i <= 14;i ++)
        paizhu[have[i]] ++;
    int plus = 0;
    for(;paizhu[4];paizhu[4] --){								//存在4张相同的牌 
        if(paizhu[2] >= 2) 
			paizhu[2] -= 2;
        else if(paizhu[1] >= 2) 
			paizhu[1] -= 2;
        plus ++;
    }
    for(;paizhu[3];paizhu[3] --){								//存在3张相同的牌 
        if(paizhu[2]) 
			paizhu[2] --;
        else if(paizhu[1]) 
			paizhu[1] --;
        plus ++;
    }
    if(have[0] && have[1] && paizhu[1] >= 2) 
		plus --;
    plus += (paizhu[1]+paizhu[2]);
    ans = min(ans,now+plus);
    for(int i = 1;i <= 3;i ++){
        for(int j = 3;j<=14;j ++){
        	int k;
            for(k = j;have[k] >= i && k <= 14;k ++){
                have[k] -= i;
                 if(k-j+1 >= num[i]) 
				 	dfs(now+1);
            }
            for(;k>j;) 
				have[--k] += i;
        }
    }
}

int main()
{
    scanf("%d%d",&T,&n);
    while(T--){
        memset(have,0,sizeof(have));
        ans=0x7fffffff;
        for(int i = 1;i <= n;i ++){
            int a,b;
			scanf("%d%d",&a,&b);
            if(a == 1) 
				have[14]++;
            else if(a == 0 && b == 1) 
				have[0]++;
            else if(a == 0 && b == 2) 
				have[1]++;
            else 
				have[a]++;
        }
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
