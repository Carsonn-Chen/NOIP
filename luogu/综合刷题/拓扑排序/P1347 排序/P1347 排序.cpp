#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

const int MAX=40;

int n,m,f[MAX][MAX],in[MAX];
int cnt,head[MAX],to[MAX],next[MAX];

inline int read(){
    char c = getchar();
	while (c<'A' || c>'Z') 
		c = getchar();
	return c-'A'+1;
}

void addedge(int u,int v){
    in[v]++;
	to[++cnt] = v;
	next[cnt] = head[u];
	head[u] = cnt;
}

void floyd(){
    for (ri k = 1;k <= n;k ++)
        for (ri i = 1;i <= n;i ++)
            for (ri j = 1;j <= n;j ++)
                f[i][j] |= f[i][k] & f[k][j];
}

void topsort(int u){
    int In[MAX];
    queue <int> q,ans;
    for (ri i = 1;i <= n;i ++) 
		In[i]=in[i];
    for (int i = 1;i <= n;i ++)
		if(!In[i]) 
			q.push(i);
    if (q.size()>1) return;
    while (!q.empty()){
        int u = q.front();
		q.pop();
		ans.push(u);
        for (ri i = head[u];i;i = next[i]){
            In[to[i]] --;
            if(!In[to[i]]){
                q.push(to[i]);
                if (q.size()>1) 
					return;
            }
        }
    }
    printf("Sorted sequence determined after %d relations: ",u);
    while (!ans.empty()) 
		printf("%c",ans.front()+'A'-1),ans.pop();
	putchar('.');
    exit(0);
}

int main(){
    int u,v;
    scanf("%d%d",&n,&m);
    for (ri i = 1;i <= m;i ++){
        u=read(),v=read();
        if (f[v][u] || u == v){
        	printf("Inconsistency found after %d relations.",i);
			return 0;
		}
        if (!f[u][v]){ 
			f[u][v] = 1;
			addedge(u,v);
		}
        floyd();
		topsort(i);
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}
