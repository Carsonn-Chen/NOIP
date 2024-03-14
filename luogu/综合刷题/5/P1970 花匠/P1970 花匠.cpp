#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int num[1000005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++)
        scanf("%d",&num[i]);
    bool con = 0;
    long long ans = 2;
    if(num[2] >= num[1])
        con = 1;
    for(int i = 2;i < n;i ++){
        if(con == 1){
            if(num[i] > num[i+1])
                con = 0,ans ++;
        }
        else{
            if(num[i] < num[i+1])
                con = 1,ans ++;
        }
    }
    printf("%lld",ans);
    return 0;
} 
