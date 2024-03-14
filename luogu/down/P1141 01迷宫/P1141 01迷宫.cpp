#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;
int n,pace[1002][1002]={0};
//ֻ�в�������������Ҫ�ģ���������û��Ҫ��Ϊȫ�ֱ�����
int read(){
    int abs=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) abs=abs*10+c-'0',c=getchar();
    return abs;
}//�����Ż�(����ѯ����ô���...)
void getpace(){
    int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    //�ƶ���ʽ
    char c=getchar();
    bool map[1002][1002],can[1002][1002]={0};
    //map���Թ�
    //can==1��ʾ��δ���ʹ��������Ѿ����ʻ��߲�ͨ(�߽�)
    for(int i=0;i<n*n;i++){
        while(c!='1'&&c!='0') c=getchar();
        map[i/n+1][i%n+1]=(c=='1');
        //����Ϊ1ʱ��Ϊ1�������Ϊ0
        can[i/n+1][i%n+1]=1;
        c=getchar();
    }
    for(int i=0;i<n*n;i++){
        if(!can[i/n+1][i%n+1]) continue;
        //�Ѿ����ʹ����򲻱ؼ����䲽����
        //�ڱ�ĵ����;�ϼ������
        int tot=0;//���㲽��
        queue<int> qx,qy,rx,ry;
        qx.push(i/n+1);
        qy.push(i%n+1);
        can[i/n+1][i%n+1]=0;
        while(qx.size()){
            tot++;
            int x=qx.front(),y=qy.front();
            rx.push(x);//rx�д���;�ĵ��x
            ry.push(y);//ͬ��
            qx.pop();
            qy.pop();
            for(int j=0;j<4;j++){
                int nx=x+dx[j],ny=y+dy[j];
                if(can[nx][ny]&(map[nx][ny]^map[x][y])){
                //�õ�������չ����
                    qx.push(nx);
                    qy.push(ny);
                    can[nx][ny]=0;
                }

            }
        }
        while(rx.size()){
            pace[rx.front()][ry.front()]=tot;
            rx.pop();ry.pop();
        }//���²���
    }
}
int main(){
    n=read();int m=read();
    getpace();
    while(m--) printf("%d\n",pace[read()][read()]);
    return 0;
}
