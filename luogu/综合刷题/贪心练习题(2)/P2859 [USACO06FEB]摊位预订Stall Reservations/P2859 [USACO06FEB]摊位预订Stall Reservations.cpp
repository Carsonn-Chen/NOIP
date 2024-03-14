#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int pos[100005],Time[1000005],pen[1000005];

struct node{
    int l;
	int r;
	int no;
}inf[1000005];

inline bool cmp(node a,node b){
    return a.l < b.l;
}
int main(){
	int n;
    scanf("%d",&n);
    int Max = -1e9;
    for(register int i = 1;i <= n;i ++){
        int x,y;
		scanf("%d%d",&x,&y);
        inf[i] = (node){x,y,i};
        pos[x]++;
		pos[y+1]--;
        Max = max(Max,y);
    }
    int temp = 0,ans = 0;
    for(register int i = 1;i <= Max;i ++){
        temp += pos[i];
        ans = max(ans,temp);
    }
    printf("%d\n",ans);
    sort(inf+1,inf+1+n,cmp);
    for(register int i = 1;i <= n;i ++)
        for(register int k = 1;k <= ans;k ++)
            if(pen[k] < inf[i].l){
                pen[k] = inf[i].r;
				Time[inf[i].no]=k;
				break;
            }
    for(register int i = 1;i <= n;i ++)
       printf("%d\n",Time[i]);
    return 0;
}
