#include<iostream>
#include<cmath>
using namespace std;

struct data{
   int fa,count,no;  //�������fa�����ϴ�Сcount������ľ���no
}a[30005];

int find(int x) //����
{
    if(a[x].fa==x) return x;
    int k=a[x].fa;
    a[x].fa=find(a[x].fa); //·��ѹ��
    a[x].no +=a[k].no;    //���µ�ǰ�ڵ㵽���ľ���
    return a[x].fa;
}

int main(){

    int T; cin>>T;
    for(int i=1;i<=30000;i++) {  //��ʼ��
       a[i].fa=i;
       a[i].no=0;
       a[i].count=1;
    }
    while(T--){
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        int r1=find(x),r2=find(y);  //����x,y�ĸ�
        if(ch=='M'){
          a[r1].fa=r2;  //�� x���ڼ��Ϸ���y���ڼ��ϵĺ���
          a[r1].no += a[r2].count;    //����r1�ĵ��¸��ľ���
          a[r2].count+=a[r1].count ; //���¼��ϴ�С
        }
        if(ch=='C'){
            if(r1!=r2)cout<<-1<<endl; //����ͬһ��������
            else  cout<<abs(a[x].no-a[y].no)-1<<endl;
        }
    }
    return 0;
}
