#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;
int n,pace[1002][1002]={0};
//只有步数才是我们需要的，那其他就没必要存为全局变量了
int read(){
    int abs=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) abs=abs*10+c-'0',c=getchar();
    return abs;
}//读入优化(介于询问那么多次...)
void getpace(){
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    //移动方式
    char c=getchar();
    bool map[1002][1002],can[1002][1002]={0};
    //map存迷宫
    //can==1表示还未访问过，否则已经访问或走不通(边界)
    for(int i=0;i<n*n;i++){
        while(c!='1'&&c!='0') c=getchar();
        map[i/n+1][i%n+1]=(c=='1');
        //输入为1时存为1，否则存为0
        can[i/n+1][i%n+1]=1;
        c=getchar();
    }
    for(int i=0;i<n*n;i++){
        if(!can[i/n+1][i%n+1]) continue;
        //已经访问过，则不必计算其步骤了
        //在别的点的沿途上计算过了
        int tot=0;//计算步骤
        queue<int> qx,qy,rx,ry;
        qx.push(i/n+1);
        qy.push(i%n+1);
        can[i/n+1][i%n+1]=0;
        while(qx.size()){
            tot++;
            int x=qx.front(),y=qy.front();
            rx.push(x);//rx中存沿途的点的x
            ry.push(y);//同上
            qx.pop();
            qy.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j],ny=y+dy[j];
                if(can[nx][ny]&(map[nx][ny]^map[x][y])){
                //该点满足拓展条件
                    qx.push(nx);
                    qy.push(ny);
                    can[nx][ny]=0;
                }

            }
        }
        while(rx.size()){
            pace[rx.front()][ry.front()]=tot;
            rx.pop();ry.pop();
        }//更新步数
    }
}
int main(){
    n=read();int m=read();
    getpace();
    while(m--) printf("%d\n",pace[read()][read()]);
    return 0;
}
