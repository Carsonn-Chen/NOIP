#include<iostream>
#include<cmath>
using namespace std;

struct data{
   int fa,count,no;  //根结点编号fa、集合大小count、离根的距离no
}a[30005];

int find(int x) //查找
{
    if(a[x].fa==x) return x;
    int k=a[x].fa;
    a[x].fa=find(a[x].fa); //路径压缩
    a[x].no +=a[k].no;    //更新当前节点到根的距离
    return a[x].fa;
}

int main(){

    int T; cin>>T;
    for(int i=1;i<=30000;i++) {  //初始化
       a[i].fa=i;
       a[i].no=0;
       a[i].count=1;
    }
    while(T--){
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        int r1=find(x),r2=find(y);  //查找x,y的根
        if(ch=='M'){
          a[r1].fa=r2;  //把 x所在集合放在y所在集合的后面
          a[r1].no += a[r2].count;    //更新r1的到新根的距离
          a[r2].count+=a[r1].count ; //更新集合大小
        }
        if(ch=='C'){
            if(r1!=r2)cout<<-1<<endl; //不在同一个集合中
            else  cout<<abs(a[x].no-a[y].no)-1<<endl;
        }
    }
    return 0;
}
