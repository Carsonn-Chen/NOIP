/* �������½� 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

int a[1000005],n,k;

int Erfen(){    // ���Ӷ�O(log(n)) �����������Ǳ����� 
   int L = 0; // �����������˵�
   int R =n - 1; // ����������Ҷ˵�
   int ans=n; // ��ĿǰΪֹ�ҵ������Ž�
   while( L <= R) { // ����������䲻Ϊ�վͼ�������
      int mid = L+(R-L>>1);   // ���� 
      if(a[mid]>= k) { ans = mid; R = mid - 1;}  
      else  L = mid+1;
   }
   return ans;
}

int main(){
	freopen("lower.in","r",stdin);
    freopen("lower.out","w",stdout);    
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i]; 
    cout<<Erfen()<<endl;   
    return 0;
}


